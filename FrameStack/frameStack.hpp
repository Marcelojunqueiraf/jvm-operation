#include "../common/index.hpp"
#include <stack>
#include <vector>

#ifndef FRAME_STACK_H
#define FRAME_STACK_H

using namespace std;

struct Frame {
  stack<JvmValue> operandStack;
  vector<JvmValue> localVariables;
  Method_info * method_info;
  int pc;
  Frame(Method_info * method_info);
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
  int getStackSize();
};

#endif
