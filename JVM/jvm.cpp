#include "jvm.hpp"

void JVM::initClass(MethodAreaItem * methodAreaItem) {
  // Verificar se é a classe object do java
  if (methodAreaItem->getClassName() == JAVA_OBJ_CLASSNAME) return;

  this->frameStack.push(methodAreaItem->getStaticBlock());
  MethodAreaItem * superClass = this->methodArea.getMethodAreaItem(methodAreaItem->getSuper());
  this->initClass(superClass);
}

void JVM::initialize(string classPath) {
  MethodAreaItem * firstClass = this->methodArea.getMethodAreaItemFromFile(classPath);

  Method_info * mainMethod =  firstClass->getMainMethod();
  this->frameStack.push(mainMethod);
  this->initClass(firstClass);
}

code_attribute * getCode(Method_info * method_info) {
  // TODO: Piano, implementar
  // for (int i = 0; i < method_info->attributes_count; i++) {
  //   if (method_info->attributes[i] == "Code") {
  //     return method_info->attributes[i]->info.code;
  //   }
  // }
  return NULL;
}

void JVM::executeInstruction(u1 * instruction, Frame * frame){
}

void JVM::executeFrame() {
  Frame * frame = this->frameStack.top();
  code_attribute * codeAtt = getCode(frame->method_info);
  // verifica se o método acabou
  if (frame->pc >= codeAtt->code_length) {
    this->frameStack.pop();
    return;
  }
  u1 * instruction = codeAtt->code + frame->pc;
  executeInstruction(instruction, frame);
  frame->pc++;
}

void JVM::run() {
  while (this->frameStack.getStackSize() > 0) {
    this->executeFrame();
  }
}