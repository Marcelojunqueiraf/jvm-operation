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
  this->instructionsMap[*opcode](frame, this);
}

void JVM::executeFrame(Frame * frame) {
  string methodName = frame->methodAreaItem->getUtf8(frame->method_info->name_index);
  // salvar methodName no frame por performance?

  DCOUT << "executeFrame #" <<  frame->method_info->name_index << ' ' << methodName << " from " << frame->methodAreaItem->getClassName() << ".class" <<endl;

  code_attribute * codeAtt = getCode(frame->method_info, frame->methodAreaItem);
  // salvar ponteiro pro code por performance?

  DCOUT << "code len: " << codeAtt->code_length << endl;

  if (frame->pc < codeAtt->code_length) {
    DCOUT << "Executing instruction at pc: " << frame->pc << ", stackSize: " << frame->operandStack.size() << endl;
    
    u1 * opcode = codeAtt->code + frame->pc;
    this->executeInstruction(opcode, frame);
  }
  else{
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

void JVM::returnValueWide(JvmValue low, JvmValue high) {
  DCOUT << "return wide value" << endl;
  this->frameStack.pop();
  Frame * nextFrame = this->frameStack.top();
  nextFrame->pushWideOperandStack(low, high);
}

void JVM::run() {
  while (this->frameStack.getStackSize() > 0) {
    Frame * frame = this->frameStack.top();
    this->executeFrame(frame);
  }
}

u4 JVM::pushHeapItem(HeapItem *heapItem) {
  return this->heap.pushHeapItem(heapItem);
}

JvmValue JVM::getField(u4 heapItemIndex, string fieldName) {
  HeapItem * heapItem = this->heap.getHeapItem(heapItemIndex);
  return heapItem->getFieldValue(fieldName);
}

pair<JvmValue, JvmValue> JVM::getFieldWide(u4 heapItemIndex, string fieldName) {
  HeapItem * heapItem = this->heap.getHeapItem(heapItemIndex);
  return heapItem->getFieldValueWide(fieldName);
}

JvmValue JVM::getStaticField(u4 heapItemIndex, string fieldName) {
  return JvmValue(); // TODO: implement
}

pair<JvmValue, JvmValue> JVM::getStaticFieldWide(u4 heapItemIndex, string fieldName) {
  return pair<JvmValue, JvmValue>(); // TODO: implement
}

void JVM::setField(u4 heapItemIndex, string fieldName, JvmValue value) {
  HeapItem * heapItem = this->heap.getHeapItem(heapItemIndex);
  heapItem->setFieldValue(fieldName, value);
}

void JVM::setFieldWide(u4 heapItemIndex, string fieldName, JvmValue low, JvmValue high) {
  HeapItem * heapItem = this->heap.getHeapItem(heapItemIndex);
  heapItem->setFieldValueWide(fieldName, low, high);
}

void JVM::setStaticField(u4 heapItemIndex, string fieldName, JvmValue value) {
  // TODO: implement
}

void JVM::setStaticFieldWide(u4 heapItemIndex, string fieldName, JvmValue low, JvmValue high) {
  // TODO: implement
}

JVM::JVM() {
  this->instructionsMap = InstructionsMap(256);
  loadInstructions(&this->instructionsMap);
}