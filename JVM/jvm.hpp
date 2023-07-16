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
    void returnValueWide(JvmValue low, JvmValue high);
    
    u4 pushObject(Object * heapItem);
    u4 pushArray(Array * arrayItem);

    JvmValue getField(u4 heapItemIndex, string fieldName);
    pair<JvmValue, JvmValue> getFieldWide(u4 heapItemIndex, string fieldName);
    JvmValue getStaticField(u4 heapItemIndex, string fieldName);
    pair<JvmValue, JvmValue> getStaticFieldWide(u4 heapItemIndex, string fieldName);

    void setField(u4 heapItemIndex, string fieldName, JvmValue value);
    void setFieldWide(u4 heapItemIndex, string fieldName, JvmValue low, JvmValue high);
    void setStaticField(u4 heapItemIndex, string fieldName, JvmValue value);
    void setStaticFieldWide(u4 heapItemIndex, string fieldName, JvmValue low, JvmValue high);
};
