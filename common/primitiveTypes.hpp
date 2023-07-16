
#ifndef PRIMITIVE_TYPES_H 
#define PRIMITIVE_TYPES_H

#include <string>

typedef enum {
    BYTE,
    SHORT,
    INT,
    LONG,
    CHAR,
    FLOAT,
    DOUBLE,
    BOOL,
    REFERENCE,
    STRING,
    RETURNADDRESS
  } JVMType;

typedef union 
  {
    uint32_t u;
    int32_t i;
    int64_t l; // long
    float f;
    double d;
  } DataUnion;


class JvmValue
{
  public:
  JVMType type;
  DataUnion data;
  std::string s;

  JvmValue() {}

  JvmValue(JVMType type, DataUnion data) {
    this->type = type;
    this->data = data;
  }
  JvmValue(JVMType type, std::string s) {
    this->type = type;
    this->s = s;
  }
};

#endif
