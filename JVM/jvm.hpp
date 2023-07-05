#ifndef JVM_H
#define JVM_H

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

class JVM {
  private:
    FrameStack frameStack;
    Heap heap;
    MethodArea methodArea;
    void * pc;
    void initClass(MethodAreaItem * methodAreaItem);
    void executeFrame(Frame * frame);
    void executeInstruction(u1 * instruction, Frame * frame);
    InstructionsMap instructionsMap;
  public:
    void initialize(string classPath);
    void run();
    JVM();
};

#endif