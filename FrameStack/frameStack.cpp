#include "frameStack.hpp"

// Frame

stack<Frame> FrameStack::data = stack<Frame>();

//construtor 
Frame::Frame(Method_info * method_info, MethodAreaItem * methodAreaItem) {
  vector<JvmValue> localVariables(255);
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

pair<JvmValue, JvmValue> Frame::popWideOperandStack() {
  JvmValue low = this->operandStack.top();
  this->operandStack.pop();
  JvmValue high = this->operandStack.top();
  this->operandStack.pop();
  return {low, high};
}

void Frame::pushWideOperandStack(JvmValue low, JvmValue high) {
  this->operandStack.push(high);
  this->operandStack.push(low);
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

