#include "frameStack.hpp"

// Frame

stack<Frame> FrameStack::data = stack<Frame>();

//construtor 
Frame::Frame(Method_info * method_info, MethodAreaItem * methodAreaItem) {
  vector<JvmValue> localVariables(255); //TODO: verificar se o tamanho é esse mesmo
  this->localVariables = localVariables;

  stack<JvmValue> operandStack;
  this->operandStack = operandStack;

  this->method_info = method_info;
  this->methodAreaItem = methodAreaItem;
  this->pc = 0;
}

JvmValue Frame::popOperandStack() {
  JvmValue value = this->operandStack.top();
  this->operandStack.pop();
  return value;
}

void Frame::pushOperandStack(JvmValue value) {
  this->operandStack.push(value);
}

// FrameStack

void FrameStack::pop(){
  this->data.pop();
}

void FrameStack::push(Frame frame) {
  this->data.push(frame);
}

Frame * FrameStack::top() {
  return &this->data.top();
}

FrameStack::FrameStack() {
  // construtor
}

int FrameStack::getStackSize() {
  return this->data.size();
}

