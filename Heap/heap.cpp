#include "heap.hpp"

// Object

JvmValue Object::getFieldValue(string fieldName) {
  return this->getFieldValueWide(fieldName).first;
}

pair<JvmValue, JvmValue> Object::getFieldValueWide(string fieldName) {
  if (this->fields.find(fieldName) == this->fields.end()) {
    // TODO: verificar se o field existe na classe para inicializar
    this->fields[fieldName] = {JvmValue(), JvmValue()};
  }

  return this->fields[fieldName];
}

void Object::setFieldValue(string fieldName, JvmValue value) {
  this->fields[fieldName] = {value, JvmValue()};
}

void Object::setFieldValueWide(string fieldName, JvmValue low, JvmValue high) {
  this->fields[fieldName] = {low, high};
}

Object::Object(MethodAreaItem *methodAreaItem) {
  this->methodAreaItem = methodAreaItem;
  this->fields = map<string, pair<JvmValue, JvmValue>>();

  // TODO: iniciar fields como null
}

// ARRAY
Array::Array(JVMType type, u4 size) {
  this->type = type;
  this->array = vector<JvmValue>(size);
}

JvmValue Array::getArrayValue(u4 index) {
  if (index < 0 || index >= this->array.size()) {
    throw std::runtime_error("ArrayItem não encontrado no index " + to_string(index));
  }

  return this->array[index];
}

void Array::setArrayValue(u4 index, JvmValue value) {
  if (index < 0 || index >= this->array.size()) {
    throw std::runtime_error("ArrayItem não encontrado no index " + to_string(index));
  }

  this->array[index] = value;
}

// Heap

Object * Heap::getHeapItem(u4 index) {
  if (index == 0) return nullptr;

  if (index < 0 || index >= this->heapItems.size()) {
    throw std::runtime_error("HeapItem não encontrado no index " + to_string(index));
  }

  return this->heapItems[index];
}

u4 Heap::pushHeapItem(Object *heapItem) {
  this->heapItems.push_back(heapItem);
  return this->heapItems.size() - 1;
}

Heap::Heap() {
  this->heapItems = vector<Object *>();
  heapItems.push_back(nullptr); // Ponteiro para null
  this->arrayItems = vector<Array *>();
  arrayItems.push_back(nullptr); // Ponteiro para null
}

Array * Heap::getArrayItem(u4 index) {
  if (index == 0) return nullptr;

  if (index < 0 || index >= this->arrayItems.size()) {
    throw std::runtime_error("ArrayItem não encontrado no index " + to_string(index));
  }

  return this->arrayItems[index];
}

u4 Heap::pushArrayItem(Array *arrayItem) {
  this->arrayItems.push_back(arrayItem);
  return this->arrayItems.size() - 1;
}