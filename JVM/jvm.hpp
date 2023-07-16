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
    JVM();
    void initialize(string classPath);
    void run();
    
    void invoke(Frame frame);
    void returnVoid();
    void returnValue(JvmValue);
    
    int32_t pushObject(Object * heapItem);
    int32_t pushArray(Array * arrayItem);

    JvmValue getField(int32_t heapItemIndex, string fieldName);
    JvmValue getStaticField(int32_t heapItemIndex, string fieldName);

    JvmValue getArrayValue(int32_t arrayItemIndex, int32_t index);
    void setArrayValue(int32_t arrayItemIndex, int32_t index, JvmValue value);

    void setField(int32_t heapItemIndex, string fieldName, JvmValue value);
    void setStaticField(int32_t heapItemIndex, string fieldName, JvmValue value);
};
