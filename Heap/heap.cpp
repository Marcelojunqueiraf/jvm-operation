#include "heap.hpp"

JvmValue Object::getFieldValue(string fieldName) {
  if (this->fields.find(fieldName) == this->fields.end()) {
    if (this->super != nullptr) return this->super->getFieldValue(fieldName);
    throw std::runtime_error("Field não encontrado (" + this->methodAreaItem->getClassName() + ' ' + fieldName + ")");
  }
  return this->fields[fieldName];
}

void Object::setFieldValue(string fieldName, JvmValue value) {
  if (this->fields.find(fieldName) == this->fields.end()) {
    if (this->super != nullptr) return this->super->setFieldValue(fieldName, value);
    throw std::runtime_error("Field não encontrado (" + this->methodAreaItem->getClassName() + ' ' + fieldName + ")");
  }
  this->fields[fieldName] = value;
}

Object::Object(MethodAreaItem * methodAreaItem) {
  this->methodAreaItem = methodAreaItem;
  this->fields = map<string, JvmValue>();

  // Inicializar fields
  for (auto field : methodAreaItem->getFieldInfos()) {
    if (field.access_flags & 0x0008) { // static, são inicializados no methodAreaItem
      continue;
    }

    string fieldName = methodAreaItem->getUtf8(field.name_index);
    vector<string> descriptors = methodAreaItem->getMethodArgTypesByDescriptorIndex(field.descriptor_index, true);
    string descriptor = descriptors[0];
    
    this->fields[fieldName] = createInitialField(descriptor);
  }

  // Inicializar super
  string supername = methodAreaItem->getSuper();
  if (supername != JAVA_OBJ_CLASSNAME) {
    MethodAreaItem * super = methodAreaItem->getMethodArea()->getMethodAreaItem(supername);
    this->super = new Object(super);
  } else {
    this->super = nullptr;
  }

}

// ARRAY
Array::Array(JVMType type, u4 size) {
  JvmValue value;

  for(u4 i = 0; i < size; i++) {
    switch (type){
      case BYTE:
        value.type = BYTE;
        value.data.u = 0;
        break;
      case SHORT:
        value.type = SHORT;
        value.data.u = 0;
        break; 
      case INT:
        value.type = INT;
        value.data.u = 0;
        break;
      case LONG:
        value.type = LONG;
        value.data.u = 0;
        break;
      case CHAR:
        value.type = CHAR;
        value.data.u = 0;
        break;
      case FLOAT:
        value.type = FLOAT;
        value.data.u = 0;
        break;
      case DOUBLE:
        value.type = DOUBLE;
        value.data.u = 0;
        break;
      case BOOL:
        value.type = BOOL;
        value.data.u = 0;
        break;
      case REFERENCE:
        value.type = REFERENCE;
        value.data.u = 0;
        break;
      case STRING:
        value.type = STRING;
        value.data.u = 0;
        break;
      case RETURNADDRESS:
        value.type = RETURNADDRESS;
        value.data.u = 0;
        break;
      default:
        throw std::runtime_error("Tipo de array não encontrado");
    }

    this->type = type;
    this->array = vector<JvmValue>(size, value);
  }
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

int32_t Array::getArraySize() {
  return this->array.size();
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
