#include "frameStack.hpp"


stack<Frame> FrameStack::data = stack<Frame>();

Frame::Frame(Method_info * method_info) {
  this->method_info = method_info;
  this->pc = 0;
}

void FrameStack::pop(){
  this->data.pop();
}

void FrameStack::push(Frame frame) {
  this->data.push(frame);
}

Frame * FrameStack::top() {
  //return this->data.top();
  return new Frame(NULL);
}

FrameStack::FrameStack() {
  // construtor
}

int FrameStack::getStackSize() {
  return this->data.size();
}

