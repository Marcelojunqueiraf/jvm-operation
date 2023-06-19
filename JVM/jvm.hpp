#include "../common/index.hpp"
#include <stack>
#include "../FrameStack/frameStack.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../Heap/heap.hpp"
#include <iostream>

#ifndef JVM_H
#define JVM_H

using namespace std;

class JVM {
  private:
    FrameStack frameStack;
    Heap heap;
    MethodArea methodArea;
    void * pc;
  public:
    void initialize(string classPath);
    void run();
};

#endif