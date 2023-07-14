#include "heap.hpp"

JvmValue HeapItem::getFieldValue(string fieldName) {
  if (this->fields.find(fieldName) == this->fields.end()) {
    string classname = this->methodAreaItem->getClassName();
    throw std::runtime_error("Campo " + fieldName + " não encontrado numa instância da classe " + classname);
  }

  return this->fields[fieldName];
}

void HeapItem::setFieldValue(string fieldName, JvmValue value) {
  if (this->fields.find(fieldName) == this->fields.end()) {
    string classname = this->methodAreaItem->getClassName();
    throw std::runtime_error("Campo " + fieldName + " não encontrado numa instância da classe " + classname);
  }

  this->fields[fieldName] = value;
}

HeapItem::HeapItem(MethodAreaItem *methodAreaItem) {
  this->methodAreaItem = methodAreaItem;
  this->fields = map<string, JvmValue>();

  // TODO: iniciar fields como null
}

HeapItem * Heap::getHeapItem(int index) {
  if (index < 0 || index >= this->heapItems.size()) {
    throw std::runtime_error("HeapItem não encontrado no index " + to_string(index));
  }

  return this->heapItems[index];
}

int Heap::pushHeapItem(HeapItem *heapItem) {
  this->heapItems.push_back(heapItem);
  return this->heapItems.size() - 1;
}

Heap::Heap() {
  this->heapItems = vector<HeapItem *>();
}
