#include "methodArea.hpp"

using namespace std;
#include <iostream>
/* Method Area */
////////////////


ClassFile * MethodArea::loadClass(string className) {
  // Workout path from className
  string path = "./" + className + ".class";
  return this->loadClassFromPath(path);
}

ClassFile * MethodArea::loadClassFromPath(string path) {
  // abre o descritor de arquivo class file

  FILE *fd = fopen(path.c_str(), "rb");   
  if (fd == NULL) {
    cout << "Erro ao abrir arquivo" << endl;
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
  this->classfile = classfile;
}

string MethodAreaItem::getClassName() {
  // TODO: 

  



  return "className";
}

Method_info * MethodAreaItem::getMainMethod() {
  // TODO: implementação
  Method_info * method_info = new Method_info();
  //method_info->attributes. 
  return method_info;
}

Method_info * MethodAreaItem::getStaticBlock() {
  Method_info * method_info= new Method_info();
  return method_info;
}

string MethodAreaItem::getSuper() {
  // TODO: implementar
  return "className"; 
}

