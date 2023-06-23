#include "../common/index.hpp"
#include <stack>

#ifndef FRAME_STACK_H
#define FRAME_STACK_H

using namespace std;

typedef struct {
  stack<JvmValue> operandStack;
  JvmValue * localVariables;
  void * code;
  int pc;
} Frame;

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
