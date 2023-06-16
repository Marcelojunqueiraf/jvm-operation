#include "frameStack.hpp"

void FrameStack::pop(){ 
  stack.pop();
}

void FrameStack::push(Frame frame) {
  stack.push(frame);
}

Frame FrameStack::top() {
  return stack.top();
}