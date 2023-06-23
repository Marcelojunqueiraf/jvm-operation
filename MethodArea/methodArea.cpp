#include "methodArea.hpp"

using namespace std;

MethodAreaItem::MethodAreaItem(ClassFile * classfile) {
  this->classfile = classfile;
}

string MethodAreaItem::getClassName() {
  // implementação
  return "className";
}

MethodArea::MethodArea() {
  // construtor
}

void MethodArea::insert (ClassFile * classfile) {
  MethodAreaItem * methodAreaItem = new MethodAreaItem(classfile);
  this->data.push_back(methodAreaItem);
}

MethodAreaItem * MethodArea::getMethodAreaItem (string className) {
  for (auto methodAreaItem : this->data) {
    if (methodAreaItem->getClassName() == className) {
      return methodAreaItem;
    }
  }
  return NULL;
}