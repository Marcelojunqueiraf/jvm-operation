#pragma once

#include "../common/index.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../FrameStack/frameStack.hpp"

class HeapItem {
  private:
    map<string, JvmValue> fields;
    MethodAreaItem * methodAreaItem;
  public:
    JvmValue getFieldValue(string fieldName);
    void setFieldValue(string fieldName, JvmValue value);
    HeapItem(MethodAreaItem * methodAreaItem);
};


class Heap {
  private:
    vector<HeapItem *> heapItems;
  public:
    HeapItem * getHeapItem(int index);
    int pushHeapItem(HeapItem * heapItem);
    Heap();
};
