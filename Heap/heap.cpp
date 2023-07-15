#include "heap.hpp"

JvmValue HeapItem::getFieldValue(string fieldName) {
  this->throwIfNotFound(fieldName);
  return this->fields[fieldName].first;
}

pair<JvmValue, JvmValue> HeapItem::getFieldValueWide(string fieldName) {
  this->throwIfNotFound(fieldName);
  return this->fields[fieldName];
}

void HeapItem::setFieldValue(string fieldName, JvmValue value) {
  this->throwIfNotFound(fieldName);
  this->fields[fieldName] = {value, JvmValue()};
}

void HeapItem::setFieldValueWide(string fieldName, JvmValue low, JvmValue high) {
  this->throwIfNotFound(fieldName);
  this->fields[fieldName] = {low, high};
}

void HeapItem::throwIfNotFound(string fieldName) {
  if (this->fields.find(fieldName) == this->fields.end()) {
    string classname = this->methodAreaItem->getClassName();
    throw std::runtime_error("Campo " + fieldName + " não encontrado numa instância da classe " + classname);
  }
}

HeapItem::HeapItem(MethodAreaItem *methodAreaItem) {
  this->methodAreaItem = methodAreaItem;
  this->fields = map<string, pair<JvmValue, JvmValue>>();

  // TODO: iniciar fields como null
}

HeapItem * Heap::getHeapItem(u4 index) {
  if (index < 0 || index >= this->heapItems.size()) {
    throw std::runtime_error("HeapItem não encontrado no index " + to_string(index));
  }

  return this->heapItems[index];
}

u4 Heap::pushHeapItem(HeapItem *heapItem) {
  this->heapItems.push_back(heapItem);
  return this->heapItems.size() - 1;
}

Heap::Heap() {
  this->heapItems = vector<HeapItem *>();
}
