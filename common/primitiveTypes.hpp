
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
    RETURNADDRESS
  } PrimitiveType;

typedef struct
{
  PrimitiveType type;
  u4 data;
} JvmValue;

#endif
