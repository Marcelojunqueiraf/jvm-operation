#pragma once

#include "../common/index.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../FrameStack/frameStack.hpp"

class Object {
  private:
    map<string, JvmValue> fields;
    MethodAreaItem * methodAreaItem;
  public:
    Object(MethodAreaItem * methodAreaItem);
    JvmValue getFieldValue(string fieldName);
    void setFieldValue(string fieldName, JvmValue value);
};

class Array {
  private:
    vector<JvmValue> array;
    JVMType type;
  public:
    Array(JVMType type, u4 size);
    JvmValue getArrayValue(u4 index);
    void setArrayValue(u4 index, JvmValue value);
};


class Heap {
  private:
    vector<Object *> heapItems;
    vector<Array *> arrayItems;
  public:
    Heap();
    Object * getHeapItem(u4 index);
    u4 pushHeapItem(Object * heapItem);
    Array * getArrayItem(u4 index);
    u4 pushArrayItem(Array * arrayItem);
};
