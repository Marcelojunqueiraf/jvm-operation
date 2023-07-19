/**
 * @file classfile.hpp
 * @author Marcelo Piano
 * @author Marcelo Junqueira
 * @author Gabriel Borges
 * @author Maycon Vinnicyus
 * @author Edson Sales
 * @brief Arquivo que define os tipos da JVM
 */

#pragma once

#include <string>

/// @brief Enum que define os tipos usados na JVM
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

/// @brief Tipos dos dados armazenados
typedef union 
  {
    uint32_t u;
    int32_t i;
    int64_t l; // long
    float f;
    double d;
  } DataUnion;

/// @brief Classe que armazena os dados de algum tipo da JVM
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
