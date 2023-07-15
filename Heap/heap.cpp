#include "heap.hpp"

JvmValue HeapItem::getFieldValue(string fieldName) {
  if (this->fields.find(fieldName) == this->fields.end()) {
    // TODO: verificar se o field existe na classe para inicializar
    this->fields[fieldName] = {JvmValue(), JvmValue()};
  }

  return this->fields[fieldName].first;
}

pair<JvmValue, JvmValue> HeapItem::getFieldValueWide(string fieldName) {
  if (this->fields.find(fieldName) == this->fields.end()) {
    // TODO: verificar se o field existe na classe para inicializar
    this->fields[fieldName] = {JvmValue(), JvmValue()};
  }

  return this->fields[fieldName];
}

void HeapItem::setFieldValue(string fieldName, JvmValue value) {
  this->fields[fieldName] = {value, JvmValue()};
}

void HeapItem::setFieldValueWide(string fieldName, JvmValue low, JvmValue high) {
  this->fields[fieldName] = {low, high};
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
  heapItems.push_back(nullptr); // Ponteiro para null
}
