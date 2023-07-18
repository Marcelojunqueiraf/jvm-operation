#include "methodArea.hpp"

using namespace std;
#include <iostream>
/* Method Area */
////////////////


ClassFile * MethodArea::loadClass(string className) {
  if (className == JAVA_OBJ_CLASSNAME)
    return this->loadClassFromPath("./tests/Object.class");

  string path = "./tests/" + className + ".class";
  return this->loadClassFromPath(path);
}

ClassFile * MethodArea::loadClassFromPath(string path) {
  DCOUT << "Lendo o arquivo: " << path << endl;

  // abre o descritor de arquivo class file
  FILE *fd = fopen(path.c_str(), "rb");   
  if (fd == NULL) {
    throw std::runtime_error("Erro ao abrir arquivo: " + path);
  }

  // malloc de uma estrutura class file
  ClassFile *classfile = new ClassFile();

  // lê os bytecodes baseados no path 
  class_reader(fd, classfile);
  fclose(fd);

  return classfile;
}

void MethodArea::insert (MethodAreaItem * methodAreaItem) {
  this->methodItems.push_back(methodAreaItem);
}

MethodArea::MethodArea() {}

MethodArea::MethodArea(FrameStack *frameStack) {
  this->frameStack = frameStack;
}

void MethodArea::pushStaticBlock(MethodAreaItem * methodAreaItem) {
  Method_info * staticBlock = methodAreaItem->getStaticBlock();
  if (staticBlock != NULL) {
    DCOUT << "Inserindo o bloco estático no framestack da " << methodAreaItem->getClassName() << endl;
    Frame * frame = new Frame(staticBlock, methodAreaItem);
    this->frameStack->push(*frame);
  }

  if (methodAreaItem->getClassName() != JAVA_OBJ_CLASSNAME) {
    this->getMethodAreaItem(methodAreaItem->getSuper());
  }
}

MethodAreaItem * MethodArea::getMethodAreaItem (string className) {
  // procura pela classe na method area
  for (auto methodAreaItem : this->methodItems) {
    if (methodAreaItem->getClassName() == className) {
      return methodAreaItem;
    }
  }

  // se não encontrar, carrega a classe
  ClassFile * classfile = this->loadClass(className);
  MethodAreaItem * newClass = new MethodAreaItem(classfile, this);
  this->insert(newClass);

  this->pushStaticBlock(newClass);

  DCOUT << "Classe " << className << ".class" <<" carregada na method area" <<endl;

  return newClass;
}

MethodAreaItem * MethodArea::getMethodAreaItemFromFile(string path) {
  ClassFile * classfile = this->loadClassFromPath(path);
  MethodAreaItem * methodAreaItem = new MethodAreaItem(classfile, this);
  this->insert(methodAreaItem);
  
  return methodAreaItem;
}

/* Method area Item*/
////////////////////
MethodAreaItem::MethodAreaItem(ClassFile * classfile, MethodArea * methodArea) {
  this->staticFields = map<string, JvmValue>();
  this->methodArea = methodArea;
  this->classfile = classfile;

  vector<field_info> fields = this->getFieldInfos();
  for (field_info field : fields) {
    if (field.access_flags & 0x0008) { // static, são inicializados no methodAreaItem
      string fieldName = this->getUtf8(field.name_index);
      DCOUT << "fieldName: " << fieldName << endl;
      vector<string> descriptors = this->getMethodArgTypesByDescriptorIndex(field.descriptor_index, true);
      string descriptor = descriptors[0];
      
      this->staticFields[fieldName] = createInitialField(descriptor);
    }
  }
}

string MethodAreaItem::getClassName() {
  return this->getUtf8(this->classfile->this_class);
}

vector<field_info> MethodAreaItem::getFieldInfos() {
  vector<field_info> fields;
  for (int i = 0; i < this->classfile->fields_count; i++) {
    fields.push_back(this->classfile->fields[i]);
  }

  return fields;
}

string MethodAreaItem::getSuper() {
  return this->getUtf8(this->classfile->super_class);
}

Method_info * MethodAreaItem::getMainMethod() {
  auto method = this->getMethodByName("main", true);
  if (method == NULL) {
    throw std::runtime_error("Method not found: " + this->getClassName() + ".main");
  }

  return method;
}

Method_info * MethodAreaItem::getInitMethod() {
  auto method = this->getMethodByName("<init>", true);
  if (method == NULL) {
    throw std::runtime_error("Method not found: " + this->getClassName() + ".<init>");
  }

  return method;
}

Method_info * MethodAreaItem::getStaticBlock() {
  return this->getMethodByName("<clinit>", true);
}

Method_info * MethodAreaItem::getMethodByName(string methodName, bool onlyActualClass) {
  for (int i = 0; i < this->classfile->methods_count; i++) {
    Method_info * actual = &this->classfile->methods[i];
    string actualName = this->getUtf8(actual->name_index);
    if (actualName == methodName) return actual;
  }

  if (onlyActualClass) return NULL;

  if (this->getClassName() != JAVA_OBJ_CLASSNAME) {
    string supername = this->getSuper();
    MethodAreaItem * superClass = this->methodArea->getMethodAreaItem(supername);
    return superClass->getMethodByName(methodName);
  }

  return NULL;
}

MethodAreaItem * MethodAreaItem::getMethodItemByMethodName(string methodName) {
  for (int i = 0; i < this->classfile->methods_count; i++) {
    Method_info * actual = &this->classfile->methods[i];
    string actualName = this->getUtf8(actual->name_index);
    if (actualName == methodName) return this;
  }

  if (this->getClassName() != JAVA_OBJ_CLASSNAME) {
    string supername = this->getSuper();
    MethodAreaItem * superClass = this->methodArea->getMethodAreaItem(supername);
    return superClass->getMethodItemByMethodName(methodName);
  }

  return NULL;
}

JvmValue MethodAreaItem::getStaticField(string fieldName) {
  if (this->staticFields.find(fieldName) == this->staticFields.end()) {
    if (this->getClassName() != JAVA_OBJ_CLASSNAME) {
      MethodAreaItem * superClass = this->methodArea->getMethodAreaItem(this->getSuper());
      return superClass->getStaticField(fieldName);
    }

    throw std::runtime_error("Field estático não encontrado (" + this->getClassName() + '.' + fieldName + ")");
  }
  return this->staticFields[fieldName];
}

void MethodAreaItem::setStaticField(string fieldName, JvmValue value) {
  if (this->staticFields.find(fieldName) == this->staticFields.end()) {
    if (this->getClassName() != JAVA_OBJ_CLASSNAME) {
      MethodAreaItem * superClass = this->methodArea->getMethodAreaItem(this->getSuper());
      superClass->setStaticField(fieldName, value);
      return;
    }

    throw std::runtime_error("Field estático não encontrado (" + this->getClassName() + '.' + fieldName + ")");
  }
  this->staticFields[fieldName] = value;
}

cp_info * MethodAreaItem::getConstantPoolItem(u2 index) {
  return &this->classfile->constant_pool[index];
}

string MethodAreaItem::getUtf8(u2 index) {
  u2 actualIndex = index;
  cp_info * actual = this->getConstantPoolItem(actualIndex);
  while (actual->tag != CONSTANT_Utf8_info) {
    actualIndex = actual->constant_type_union.Class_info.name_index;
    actual = this->getConstantPoolItem(actualIndex);
  }

  return utf8ToString(actual);
}

MethodArea * MethodAreaItem::getMethodArea() {
  return this->methodArea;
}

vector<string> MethodAreaItem::getMethodArgTypesByNameAndTypeIndex(u2 nameAndTypeIndex, bool isField) {
  cp_info * actual = this->getConstantPoolItem(nameAndTypeIndex);
  return this->getMethodArgTypesByDescriptorIndex(actual->constant_type_union.NameAndType.descriptor_index, isField);
}

vector<string> MethodAreaItem::getMethodArgTypesByDescriptorIndex(u2 descriptorIndex, bool isField) {
  string descriptor = this->getUtf8(descriptorIndex);
  DCOUT << "descriptor: " << descriptor << endl;

  if (isField) descriptor = '(' + descriptor + ')'; // adiciona os parenteses para o caso de ser field, facilita o parse

  vector<string> types; // não usei o tipo PrimitiveType pq o tipo L não é uma string com valor fixo, + array e void
  unsigned int i = 1; // pula o '('
  while (i < descriptor.size() && descriptor[i] != ')') {
    auto [argType, jump] = getArgType(descriptor, i);
    types.push_back(argType);
    i += jump;
  }

  if (!isField) { // se for função, pega o tipo de retorno
    string returnTypeString = descriptor.substr(descriptor.find(')') + 1);
    types.push_back(getArgType(returnTypeString, 0).first); // último tipo é o retorno
  }

  return types;
}

pair<string, int> getArgType(string signature, int index) {
  // retorno: {tipo, pulo}
  switch (signature[index]) {
    case 'B':
      return {"BYTE", 1};
    case 'C':
      return {"CHAR", 1};
    case 'D':
      return {"DOUBLE", 1};
    case 'F':
      return {"FLOAT", 1};
    case 'I':
      return {"INT", 1};
    case 'J':
      return {"LONG", 1};
    case 'S':
      return {"SHORT", 1};
    case 'Z':
      return {"BOOL", 1};
    case 'V':
      return {"VOID", 1};
    case 'L': // class
    {
      int asize = index;
      while (signature[asize] != ';') asize++;
      return {signature.substr(index, asize), asize};
    }
    case '[':
      // TODO: array
    default:
      throw std::runtime_error("Tipo de argumento não reconhecido \"" + string(1, signature[index]) + "\" no tipo " + signature);
      break;
  }
}

JvmValue createInitialField(string descriptor) {
  JvmValue value;
  if (descriptor == "LONG") {
    value.type = LONG;
    value.data.l = 0;
  } else if (descriptor == "DOUBLE") {
    value.type = DOUBLE;
    value.data.d = 0;
  } else if (descriptor == "FLOAT") {
    value.type = FLOAT;
    value.data.f = 0;
  } else if (descriptor == "INT") {
    value.type = INT;
    value.data.i = 0;
  } else if (descriptor == "SHORT") {
    value.type = SHORT;
    value.data.i = 0;
  } else if (descriptor == "BYTE") {
    value.type = BYTE;
    value.data.i = 0;
  } else if (descriptor == "CHAR") {
    value.type = CHAR;
    value.data.i = 0;
  } else if (descriptor == "BOOL") {
    value.type = BOOL;
    value.data.i = 0;
  } else if (descriptor == JAVA_STRING_CLASSNAME) {
    value.type = REFERENCE;
    value.data.i = 0;
  } else {
    throw std::runtime_error("Tipo de field não suportado (" + descriptor + ")");
  }
  return value;
}
