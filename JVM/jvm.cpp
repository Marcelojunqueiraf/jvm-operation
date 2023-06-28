#include "jvm.hpp"

void JVM::initClass(MethodAreaItem * methodAreaItem) {
  // Verificar se é a classe object do java
  if (methodAreaItem->getClassName() == JAVA_OBJ_CLASSNAME) return;

  this->frameStack.push(methodAreaItem->getStaticBlock());
  /*
  // TODO: remover comentário
  MethodAreaItem * superClass = this->methodArea.getMethodAreaItem(methodAreaItem->getSuper());
  this->initClass(superClass);
  */
}

void JVM::initialize(string classPath) {
  MethodAreaItem * firstClass = this->methodArea.getMethodAreaItemFromFile(classPath);

  Method_info * mainMethod =  firstClass->getMainMethod();
  this->frameStack.push(mainMethod);
  this->initClass(firstClass);
}

code_attribute * getCode(Method_info * method_info, MethodAreaItem * methodAreaItem) {
  for (int i = 0; i < method_info->attributes_count; i++) {
    Attribute_info * attribute = &method_info->attributes[i];
    u2 index = attribute->attribute_name_index;
    cp_info * cp = methodAreaItem->getConstantPoolItem(index);
    string name = Utf8_decoder(cp);
    if (name == "Code"){
      return &attribute->attribute_info_union.code_attribute;
    }
  }
  return NULL;
}

void JVM::executeInstruction(u1 * instruction, Frame * frame){
}

void JVM::executeFrame() {
  Frame * frame = this->frameStack.top();
  cout << "top" << endl;
  code_attribute * codeAtt = getCode(frame->method_info, frame->methodAreaItem);
  cout << "code" << endl;
  // verifica se o método acabou
  if (frame->pc >= codeAtt->code_length) {
    this->frameStack.pop();
    return;
  }
  cout << "verificou" << endl;
  u1 * instruction = codeAtt->code + frame->pc;
  cout << "pegou instruction" << endl;
  executeInstruction(instruction, frame);
  cout << "executou" << endl;
  frame->pc++;
}

void JVM::run() {
  while (this->frameStack.getStackSize() > 0) {
    this->executeFrame();
  }
}