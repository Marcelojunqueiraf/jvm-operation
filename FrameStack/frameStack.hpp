#include "../common/index.hpp"
#include "../MethodArea/class-file.hpp"
#include <stack>

#ifndef FRAME_STACK_H
#define FRAME_STACK_H

using namespace std;

struct Frame {
  stack<JvmValue> operandStack;
  JvmValue * localVariables;
  Method_info * method_info;
  int pc;
  Frame(Method_info * method_info) {
    this->method_info = method_info;
    this->localVariables = new JvmValue[100];
    this->pc = 0;
  }
};

class FrameStack
{
private:
  static stack<Frame> data;
public:
  FrameStack();
  void pop();
  Frame * top();
  void push(Frame frame);
};

#endif
