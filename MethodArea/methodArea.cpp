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

MethodAreaItem * MethodArea::getMethodAreaItem (string className) {
  // check if class is already loaded
  for (auto methodAreaItem : this->methodItems) {
    if (methodAreaItem->getClassName() == className) {
      return methodAreaItem;
    }
  }

  // E se der erro no load?
  ClassFile * classfile = this->loadClass(className);
  MethodAreaItem * newClass = new MethodAreaItem(classfile, this);
  this->insert(newClass);
  DCOUT << "Classe " << className << ".class" <<" carregada na method area" <<endl;
  return newClass;
}

MethodAreaItem * MethodArea::getMethodAreaItemFromFile(string path) {
  ClassFile * classfile = this->loadClassFromPath(path);
  MethodAreaItem * methodAreaItem = new MethodAreaItem(classfile, this);
  
  return methodAreaItem;
}

/* Method area Item*/
////////////////////
MethodAreaItem::MethodAreaItem(ClassFile * classfile, MethodArea * methodArea) {
  // Inicializar staticFields
  this->staticFields = map <string, JvmValue>();
  this->methodArea = methodArea;
  this->classfile = classfile;
}

string MethodAreaItem::getClassName() {
  return this->getUtf8(this->classfile->this_class);
}

string MethodAreaItem::getSuper() {
  return this->getUtf8(this->classfile->super_class);
}

Method_info * MethodAreaItem::getMainMethod() {
  auto method = this->getMethodByName("main");
  if (method == NULL) {
    throw std::runtime_error("Method not found: " + this->getClassName() + ".main");
  }

  return method;
}

Method_info * MethodAreaItem::getInitMethod() {
  auto method = this->getMethodByName("<init>");
  if (method == NULL) {
    throw std::runtime_error("Method not found: " + this->getClassName() + ".<init>");
  }

  return method;
}

Method_info * MethodAreaItem::getStaticBlock() {
  return this->getMethodByName("<clinit>");
}

Method_info * MethodAreaItem::getMethodByName(string name) {
  for (int i = 0; i < this->classfile->methods_count; i++) {
    Method_info * actual = &this->classfile->methods[i];
    string actualName = this->getUtf8(actual->name_index);
    if (actualName == name) return actual;
  }

  return NULL;
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

vector<string> MethodAreaItem::getMethodArgTypes(u2 nameAndTypeIndex) {
  cp_info * actual = this->getConstantPoolItem(nameAndTypeIndex);
  string descriptor = this->getUtf8(actual->constant_type_union.NameAndType.descriptor_index);
  string returnTypeString = descriptor.substr(descriptor.find(')') + 1);

  DCOUT << "descriptor: " << descriptor << endl;

  vector<string> types; // não usei o tipo PrimitiveType pq o tipo L não é uma string com valor fixo, + array e void
  int i = 1; // pula o '('
  while (descriptor[i] != ')') {
    auto [argType, jump] = getArgType(descriptor, i);
    types.push_back(argType);
    i += jump;
  }

  types.push_back(getArgType(returnTypeString, 0).first); // último tipo é o retorno

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
      throw std::runtime_error("Tipo de argumento não reconhecido " + signature + " no index " + to_string(index));
      break;
  }
}
