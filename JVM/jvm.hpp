#pragma once

#include "../common/index.hpp"
#include <stack>
#include "../FrameStack/frameStack.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../Heap/heap.hpp"
#include "../Instruction/instructions.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class JVM;

code_attribute * getCode(Method_info * method_info, MethodAreaItem * methodAreaItem);

typedef vector <void(*)(Frame *, JVM *)> InstructionsMap;

class JVM {
  private:
    FrameStack frameStack;
    Heap heap;
    MethodArea methodArea;
    InstructionsMap instructionsMap;
    void * pc;
    void initClass(MethodAreaItem * methodAreaItem);
    void executeFrame(Frame * frame);
    void executeInstruction(u1 * instruction, Frame * frame);

  public:
    void invoke(Frame frame);
    void initialize(string classPath);
    void run();
    int pushHeapItem(HeapItem * heapItem);
    void invoke(Frame frame);
    void returnVoid();
    void returnValue(JvmValue);
    void returnValueWide(JvmValue low, JvmValue high);
    JVM();
};
