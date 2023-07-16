#pragma once

#include "../common/index.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../FrameStack/frameStack.hpp"

class Object {
  private:
    map<string, pair<JvmValue, JvmValue>> fields;
    MethodAreaItem * methodAreaItem;
  public:
    Object(MethodAreaItem * methodAreaItem);
    JvmValue getFieldValue(string fieldName);
    pair<JvmValue, JvmValue> getFieldValueWide(string fieldName);
    void setFieldValue(string fieldName, JvmValue value);
    void setFieldValueWide(string fieldName, JvmValue low, JvmValue high);
};

class Array {
  private:
    vector<JvmValue> array;
    JVMType type;
  public:
    Array(JVMType type, u4 size);
    JvmValue getArrayValue(u4 index);
    pair<JvmValue, JvmValue> getArrayValueWide(u4 index);
    void setArrayValue(u4 index, JvmValue value);
    void setArrayValueWide(u4 index, JvmValue low, JvmValue high);
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
