#include "methodArea.hpp"

using namespace std;

/* Method Area */
////////////////

ClassFile * MethodArea::loadClass(string className) {
  // Workout path from className
  string path = "path";
  return this->loadClassFromPath(path);
}

ClassFile * MethodArea::loadClassFromPath(string path) {
  // Chamar leitor
  ClassFile * classfile = new ClassFile();
  return classfile;
}

void MethodArea::insert (MethodAreaItem * methodAreaItem) {
  this->data.push_back(methodAreaItem);
}

MethodAreaItem * MethodArea::getMethodAreaItem (string className) {
  // check if class is already loaded
  MethodAreaItem * target = NULL;
  for (auto methodAreaItem : this->data) {
    if (methodAreaItem->getClassName() == className) {
      target = methodAreaItem;
    }
  }
  if (target == NULL) {
    ClassFile * classfile = this->loadClass(className);
    // E se der erro no load?
    target = new MethodAreaItem(classfile);
  }
  this->insert(target);
  // stack static blocks from target
  
  // load super from target

  return target;
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
  // TODO: implementação
  return "className";
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
