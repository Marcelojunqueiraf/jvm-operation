#include "jvm.hpp"

void JVM::initClass(MethodAreaItem * methodAreaItem) {
  Method_info * staticBlock = methodAreaItem->getStaticBlock();
  Frame * frame = new Frame(staticBlock, methodAreaItem);
  if (staticBlock != NULL) this->frameStack.push(*frame);

  if (methodAreaItem->getClassName() == JAVA_OBJ_CLASSNAME) return;
  MethodAreaItem * superClass = this->methodArea.getMethodAreaItem(methodAreaItem->getSuper());

  this->initClass(superClass);
}

void JVM::initialize(string classPath) {
  MethodAreaItem * firstClass = this->methodArea.getMethodAreaItemFromFile(classPath);

  Method_info * mainMethod = firstClass->getMainMethod();
  Frame * frame = new Frame(mainMethod, firstClass);

  this->frameStack.push(*frame);
  this->initClass(firstClass);
}

code_attribute * getCode(Method_info * method_info, MethodAreaItem * methodAreaItem) {
  for (int i = 0; i < method_info->attributes_count; i++) {
    Attribute_info * attribute = &method_info->attributes[i];
    u2 index = attribute->attribute_name_index;
    string name = methodAreaItem->getUtf8(index);
    if (name == "Code") {
      return &attribute->attribute_info_union.code_attribute;
    }
  }
  return NULL;
}

void JVM::executeInstruction(u1 * opcode, Frame * frame){
  // cout << "instruction: " << hex << (int)*opcode << dec << endl;
  this->instructionsMap[*opcode](frame);
  // cout << "parou de executar a instrução" << endl;
}

void JVM::executeFrame(Frame * frame) {
  string methodName = frame->methodAreaItem->getUtf8(frame->method_info->name_index);
  DCOUT << "executeFrame #" <<  frame->method_info->name_index << ' ' << methodName << " from " << frame->methodAreaItem->getClassName() << ".class" <<endl;
  code_attribute * codeAtt = getCode(frame->method_info, frame->methodAreaItem);
  DCOUT << "code len: " << codeAtt->code_length << endl;

  
  // realizar a lógica do PC aqui 
  while(frame->pc < codeAtt->code_length){
    DCOUT << "Executing instruction at pc: " << frame->pc << " stackSize: " << frame->operandStack.size() << endl;
    u1 * opcode = codeAtt->code + frame->pc;
    this->executeInstruction(opcode, frame);
  };
}

void JVM::run() {
  while (this->frameStack.getStackSize() > 0) {
    Frame * frame = this->frameStack.top();
    this->executeFrame(frame);
    this->frameStack.pop();
  }
}

JVM::JVM() {
  this->instructionsMap = vector <void(*)(Frame *)>(256);
  loadInstructions(&this->instructionsMap);
}