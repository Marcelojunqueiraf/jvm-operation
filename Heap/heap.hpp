#pragma once

#include "../common/index.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../FrameStack/frameStack.hpp"

class HeapItem {
  private:
    map<string, pair<JvmValue, JvmValue>> fields;
    MethodAreaItem * methodAreaItem;
  public:
    HeapItem(MethodAreaItem * methodAreaItem);
    JvmValue getFieldValue(string fieldName);
    pair<JvmValue, JvmValue> getFieldValueWide(string fieldName);
    void setFieldValue(string fieldName, JvmValue value);
    void setFieldValueWide(string fieldName, JvmValue low, JvmValue high);
};


class Heap {
  private:
    vector<HeapItem *> heapItems;
  public:
    Heap();
    HeapItem * getHeapItem(u4 index);
    u4 pushHeapItem(HeapItem * heapItem);
};
