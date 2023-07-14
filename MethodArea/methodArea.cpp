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
    cout << "Erro ao abrir arquivo: " << path << endl;
    exit(1);
  }

  // malloc de uma estrutura class file
  ClassFile *classfile = new ClassFile();

  // lê os bytecodes baseados no path 
  class_reader(fd, classfile);
  fclose(fd);

  return classfile;
}

void MethodArea::insert (MethodAreaItem * methodAreaItem) {
  this->data.push_back(methodAreaItem);
}

MethodAreaItem * MethodArea::getMethodAreaItem (string className) {
  // check if class is already loaded
  for (auto methodAreaItem : this->data) {
    if (methodAreaItem->getClassName() == className) {
      return methodAreaItem;
    }
  }

  // E se der erro no load?
  ClassFile * classfile = this->loadClass(className);
  MethodAreaItem * newClass = new MethodAreaItem(classfile, this);
  this->insert(newClass);
  cout << "Classe " << className << ".class" <<" carregada na method area" <<endl;
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
    cout << "Method not found: " << this->getClassName() << ".main" << endl;
    exit(1);
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
