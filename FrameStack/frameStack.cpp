#include "frameStack.hpp"


stack<Frame> FrameStack::data = stack<Frame>();

void FrameStack::pop(){
  this->data.pop();
}

void FrameStack::push(Frame frame) {
  this->data.push(frame);
}

Frame * FrameStack::top() {
  //return this->data.top();
  return new Frame();
}

FrameStack::FrameStack() {
  // construtor
}