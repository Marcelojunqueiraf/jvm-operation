#include "methodArea.hpp"

using namespace std;
#include <iostream>
/* Method Area */
////////////////


ClassFile * MethodArea::loadClass(string className) {
  if (className == JAVA_OBJ_CLASSNAME)
    return this->loadClassFromPath("./tests/Object.class");

  string path = "./" + className + ".class";
  return this->loadClassFromPath(path);
}

ClassFile * MethodArea::loadClassFromPath(string path) {
  cout << "Lendo o arquivo: " << path << endl;

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
  MethodAreaItem * newClass = new MethodAreaItem(classfile);
  this->insert(newClass);
  return newClass;
}

MethodAreaItem * MethodArea::getMethodAreaItemFromFile(string path) {
  ClassFile * classfile = this->loadClassFromPath(path);
  MethodAreaItem * methodAreaItem = new MethodAreaItem(classfile);
  
  return methodAreaItem;
}

/* Method area Item*/
////////////////////
MethodAreaItem::MethodAreaItem(ClassFile * classfile) {
  // Inicializar staticFields
  this->staticFields = map <string, JvmValue>();

  this->classfile = classfile;
}

string MethodAreaItem::getClassName() {
  return this->getUtf8(this->classfile->this_class);
}

string MethodAreaItem::getSuper() {
  return this->getUtf8(this->classfile->super_class);
}

Method_info * MethodAreaItem::getMainMethod() {
  // TODO: implementação
  Method_info * method_info = new Method_info();
  return method_info;
}

Method_info * MethodAreaItem::getStaticBlock() {
  Method_info * method_info= new Method_info();
  return method_info;
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

  u2 len = actual->constant_type_union.Utf8.length;
  char * bytes = (char *) actual->constant_type_union.Utf8.bytes;
  return string(bytes, len);
}
