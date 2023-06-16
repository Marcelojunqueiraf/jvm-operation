#include "../common/index.hpp"
#include <stack>

#ifndef FRAME_STACK_H
#define FRAME_STACK_H

using namespace std;

class FrameStack
{
private:
  static stack<Frame> stack;
public:
  void pop();
  Frame top();
  void push(Frame frame);
};

typedef struct {
  stack<JvmValue> operandStack;
  JvmValue * localVariables;
  void * code;
  int pc;
} Frame;

#endif
