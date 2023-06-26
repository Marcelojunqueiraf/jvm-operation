#include "jvm.hpp"


void JVM::initialize(string classPath) {
  MethodAreaItem * firstClass = this->methodArea.getMethodAreaItemFromFile(classPath);

  Method_info * mainMethod =  firstClass->getMainMethod();
  this->frameStack.push(mainMethod);
  
  // stack static blocks
  // load superclasses

}

void JVM::run() {
  // while (this->frameStack.getStackSize() > 0) {
  //   this->frameStack.executeFrame();
  // }
}