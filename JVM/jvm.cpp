#include "jvm.hpp"

void JVM::initialize(string classPath) {
  MethodAreaItem * firstClass = this->methodArea.getMethodAreaItemFromFile(classPath);

  Method_info * mainMethod = firstClass->getMainMethod();
  Frame * frame = new Frame(mainMethod, firstClass);

  this->frameStack.push(*frame);
  this->methodArea.pushStaticBlock(firstClass);
}

void JVM::showClass(string classPath) {
  ClassFile * classfile = this->methodArea.loadClassFromPath(classPath);
  class_exibitor(classfile);
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
  this->instructionsMap[*opcode](frame, this);
}

void JVM::executeFrame(Frame * frame) {
  string methodName = frame->methodAreaItem->getUtf8(frame->method_info->name_index);
  
  code_attribute * codeAtt = getCode(frame->method_info, frame->methodAreaItem);
  
  if (frame->pc == 0) {
    DCOUT << "executeFrame #" <<  frame->method_info->name_index << ' ' << methodName << " from " << frame->methodAreaItem->getClassName() << ".class" <<endl;
    DCOUT << "code len: " << codeAtt->code_length << endl;
  }
  
  if (frame->pc < codeAtt->code_length) {
    DCOUT << "Executing instruction at pc: " << frame->pc << ", stackSize: " << frame->operandStack.size() << endl;
    
    u1 * opcode = codeAtt->code + frame->pc;
    this->executeInstruction(opcode, frame);
  } else {
    this->returnVoid();
  }
}

void JVM::invoke(Frame frame) {
  DCOUT << "invoke" << endl;
  this->frameStack.push(frame);
}

void JVM::returnVoid() {
  DCOUT << "return void" << endl;
  this->frameStack.pop();
}

void JVM::returnValue(JvmValue value) {
  DCOUT << "return value" << endl;
  this->frameStack.pop();
  Frame * nextFrame = this->frameStack.top();
  nextFrame->pushOperandStack(value);
}

void JVM::run() {
  while (this->frameStack.getStackSize() > 0) {
    Frame * frame = this->frameStack.top();
    this->executeFrame(frame);
  }
}

int32_t JVM::pushObject(Object *heapItem) {
  return this->heap.pushHeapItem(heapItem);
}

int32_t JVM::pushArray(Array *arrayItem) {
  return this->heap.pushArrayItem(arrayItem);
}

JvmValue JVM::getField(int32_t heapItemIndex, string fieldName) {
  Object * heapItem = this->heap.getHeapItem(heapItemIndex);
  return heapItem->getFieldValue(fieldName);
}

JvmValue JVM::getArrayValue(int32_t arrayItemIndex, int32_t index) {
  Array * arrayItem = this->heap.getArrayItem(arrayItemIndex);
  return arrayItem->getArrayValue(index);
}

void JVM::setArrayValue(int32_t arrayItemIndex, int32_t index, JvmValue value) {
  Array * arrayItem = this->heap.getArrayItem(arrayItemIndex);
  arrayItem->setArrayValue(index, value);
}

JvmValue JVM::getStaticField(string classname, string fieldName) {
  MethodAreaItem * methodAreaItem = this->methodArea.getMethodAreaItem(classname);
  return methodAreaItem->getStaticField(fieldName);
}

void JVM::setField(int32_t heapItemIndex, string fieldName, JvmValue value) {
  Object * heapItem = this->heap.getHeapItem(heapItemIndex);
  heapItem->setFieldValue(fieldName, value);
}

void JVM::setStaticField(string classname, string fieldName, JvmValue value) {
  MethodAreaItem * methodAreaItem = this->methodArea.getMethodAreaItem(classname);
  methodAreaItem->setStaticField(fieldName, value);
}

JVM::JVM() {
  this->frameStack = FrameStack();
  this->methodArea = MethodArea(&this->frameStack);
  this->instructionsMap = InstructionsMap(256);
  loadInstructions(&this->instructionsMap);
}
