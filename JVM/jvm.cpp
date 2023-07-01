#include "jvm.hpp"

void JVM::initClass(MethodAreaItem * methodAreaItem) {

  Method_info * staticBlock = methodAreaItem->getStaticBlock();
  if (staticBlock != NULL) this->frameStack.push(staticBlock);

  MethodAreaItem * superClass = this->methodArea.getMethodAreaItem(methodAreaItem->getSuper());
  if (superClass->getClassName() == JAVA_OBJ_CLASSNAME) return;

  this->initClass(superClass);
}

void JVM::initialize(string classPath) {
  MethodAreaItem * firstClass = this->methodArea.getMethodAreaItemFromFile(classPath);

  Method_info * mainMethod = firstClass->getMainMethod();

  this->frameStack.push(mainMethod);
  this->initClass(firstClass);
}

code_attribute * getCode(Method_info * method_info, MethodAreaItem * methodAreaItem) {
  cout << "method_info->attributes_count: " << method_info->attributes_count << endl;
  for (int i = 0; i < method_info->attributes_count; i++) {
    Attribute_info * attribute = &method_info->attributes[i];
    u2 index = attribute->attribute_name_index;
    cout << "attribute_name_index: " << index << endl;
    string name = methodAreaItem->getUtf8(index);
    if (name == "Code") {
      return &attribute->attribute_info_union.code_attribute;
    }
  }
  return NULL;
}

void JVM::executeInstruction(u1 * instruction, Frame * frame){
  cout << "instruction: " << *instruction << endl;
}

void JVM::executeFrame(Frame * frame) {
  cout << "executeFrame - " << frame->methodAreaItem->getUtf8(frame->method_info->name_index) << " #" <<  frame->method_info->name_index << endl;
  cout << "top" << endl;
  code_attribute * codeAtt = getCode(frame->method_info, frame->methodAreaItem);
  cout << "code len: " << codeAtt->code_length << endl;

  for (u2 i = 0; i < codeAtt->code_length; i++) {
    cout << codeAtt->code[i] << endl;
  }

  // verifica se o método acabou
  if (frame->pc >= codeAtt->code_length) return;
  cout << "verificou" << endl;
  u1 * instruction = codeAtt->code + frame->pc;
  cout << "pegou instruction" << endl;
  executeInstruction(instruction, frame);
  cout << "executou" << endl;
  frame->pc++;
}

void JVM::run() {
  while (this->frameStack.getStackSize() > 0) {
    Frame * frame = this->frameStack.top();
    this->executeFrame(frame);
    this->frameStack.pop();
  }
}
