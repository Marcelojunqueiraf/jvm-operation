#include "../common/index.hpp"
#include <stack>
#include "../FrameStack/frameStack.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../Heap/heap.hpp"
#include <fstream>
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
    ClassFile * loadClassFromFile(string path);
    void loadClass();
  public:
    void initialize(string classPath);
    void run();
};

#endif