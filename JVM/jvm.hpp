#include "../common/index.hpp"
#include <stack>
#include "../FrameStack/frameStack.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../Heap/heap.hpp"
#include <fstream>
#include <iostream>
#include <string>

#ifndef JVM_H
#define JVM_H

using namespace std;

class JVM {
  private:
    FrameStack frameStack;
    Heap heap;
    MethodArea methodArea;
    void * pc;
    void initClass(MethodAreaItem * methodAreaItem);
    void executeFrame();
    void executeInstruction(u1 * instruction, Frame * frame);
  public:
    void initialize(string classPath);
    void run();
};

const string JAVA_OBJ_CLASSNAME = "<java/lang/Object>";

#endif