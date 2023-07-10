#include "frameStack.hpp"


stack<Frame> FrameStack::data = stack<Frame>();

//construtor 
Frame::Frame(Method_info * method_info, MethodAreaItem * methodAreaItem) {
  vector<JvmValue> localVariables;
  this->localVariables = localVariables;
  stack<JvmValue> operandStack;
  this->operandStack = operandStack;
  this->method_info = method_info;
  this->methodAreaItem = methodAreaItem;
  this->pc = 0;
}

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

