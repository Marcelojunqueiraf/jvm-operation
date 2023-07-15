
#ifndef PRIMITIVE_TYPES_H 
#define PRIMITIVE_TYPES_H

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

typedef struct
{
  JVMType type;
  u4 data;
} JvmValue;

#endif
