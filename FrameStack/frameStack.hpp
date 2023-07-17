#ifndef FRAME_STACK_H
#define FRAME_STACK_H

#include "../common/index.hpp"
#include "../MethodArea/methodArea.hpp"
#include <stack>
#include <vector>

using namespace std;
class MethodAreaItem;

struct Frame {
  stack<JvmValue> operandStack;
  vector<JvmValue> localVariables;
  Method_info * method_info;
  MethodAreaItem * methodAreaItem;
  int pc;
  Frame(Method_info * method_info, MethodAreaItem * methodAreaItem);
  JvmValue popOperandStack();
  void pushOperandStack(JvmValue value);
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
  // criar invoke 
};

#endif
