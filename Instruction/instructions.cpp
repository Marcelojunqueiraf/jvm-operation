#include "instructions.hpp"

void loadInstructions(InstructionsMap * instructionsMap) {
  (*instructionsMap)[0x00] = &nop;
  (*instructionsMap)[0x01] = &aconst_null;
  (*instructionsMap)[0x02] = &iconst_m1;
  (*instructionsMap)[0x03] = &iconst_0;
  (*instructionsMap)[0x04] = &iconst_1;
  (*instructionsMap)[0x05] = &iconst_2;
  (*instructionsMap)[0x06] = &iconst_3;
  (*instructionsMap)[0x07] = &iconst_4;
  (*instructionsMap)[0x08] = &iconst_5;
  (*instructionsMap)[0x09] = &lconst_0;
  (*instructionsMap)[0x0a] = &lconst_1;
  (*instructionsMap)[0x0b] = &fconst_0;
  (*instructionsMap)[0x0c] = &fconst_1;
  (*instructionsMap)[0x0d] = &fconst_2;
  (*instructionsMap)[0x0e] = &dconst_0;
  (*instructionsMap)[0x0f] = &dconst_1;
  (*instructionsMap)[0x10] = &bipush;
  (*instructionsMap)[0x11] = &sipush;
  (*instructionsMap)[0x12] = &ldc;
  (*instructionsMap)[0x13] = &ldc_w;
  (*instructionsMap)[0x14] = &ldc2_w;
  (*instructionsMap)[0x15] = &iload;
  (*instructionsMap)[0x16] = &lload;
  (*instructionsMap)[0x17] = &fload;
  (*instructionsMap)[0x18] = &dload;
  (*instructionsMap)[0x19] = &aload;
  (*instructionsMap)[0x1a] = &iload_0;
  (*instructionsMap)[0x1b] = &iload_1;
  (*instructionsMap)[0x1c] = &iload_2;
  (*instructionsMap)[0x1d] = &iload_3;
  (*instructionsMap)[0x1e] = &lload_0;
  (*instructionsMap)[0x1f] = &lload_1;
  (*instructionsMap)[0x20] = &lload_2;
  (*instructionsMap)[0x21] = &lload_3;
  (*instructionsMap)[0x22] = &fload_0;
  (*instructionsMap)[0x23] = &fload_1;
  (*instructionsMap)[0x24] = &fload_2;
  (*instructionsMap)[0x25] = &fload_3;
  (*instructionsMap)[0x26] = &dload_0;
  (*instructionsMap)[0x27] = &dload_1;
  (*instructionsMap)[0x28] = &dload_2;
  (*instructionsMap)[0x29] = &dload_3;
  (*instructionsMap)[0x2a] = &aload_0;
  (*instructionsMap)[0x2b] = &aload_1;
  (*instructionsMap)[0x2c] = &aload_2;
  (*instructionsMap)[0x2d] = &aload_3;
  (*instructionsMap)[0x2e] = &iaload;
  (*instructionsMap)[0x2f] = &laload;
  (*instructionsMap)[0x30] = &faload;
  (*instructionsMap)[0x31] = &daload;
  (*instructionsMap)[0x32] = &aaload;
  (*instructionsMap)[0x33] = &baload;
  (*instructionsMap)[0x34] = &caload;
  (*instructionsMap)[0x35] = &saload;
  (*instructionsMap)[0x36] = &istore;
  (*instructionsMap)[0x37] = &lstore;
  (*instructionsMap)[0x38] = &fstore;
  (*instructionsMap)[0x39] = &dstore;
  (*instructionsMap)[0x3a] = &astore;
  (*instructionsMap)[0x3b] = &istore_0;
  (*instructionsMap)[0x3c] = &istore_1;
  (*instructionsMap)[0x3d] = &istore_2;
  (*instructionsMap)[0x3e] = &istore_3;
  (*instructionsMap)[0x3f] = &lstore_0;
  (*instructionsMap)[0x40] = &lstore_1;
  (*instructionsMap)[0x41] = &lstore_2;
  (*instructionsMap)[0x42] = &lstore_3;
  (*instructionsMap)[0x43] = &fstore_0;
  (*instructionsMap)[0x44] = &fstore_1;
  (*instructionsMap)[0x45] = &fstore_2;
  (*instructionsMap)[0x46] = &fstore_3;
  (*instructionsMap)[0x47] = &dstore_0;
  (*instructionsMap)[0x48] = &dstore_1;
  (*instructionsMap)[0x49] = &dstore_2;
  (*instructionsMap)[0x4a] = &dstore_3;
  (*instructionsMap)[0x4b] = &astore_0;
  (*instructionsMap)[0x4c] = &astore_1;
  (*instructionsMap)[0x4d] = &astore_2;
  (*instructionsMap)[0x4e] = &astore_3;
  (*instructionsMap)[0x4f] = &iastore;
  (*instructionsMap)[0x50] = &lastore;
  (*instructionsMap)[0x51] = &fastore;
  (*instructionsMap)[0x52] = &dastore;
  (*instructionsMap)[0x53] = &aastore;
  (*instructionsMap)[0x54] = &bastore;
  (*instructionsMap)[0x55] = &castore;
  (*instructionsMap)[0x56] = &sastore;
  (*instructionsMap)[0x57] = &pop;
  (*instructionsMap)[0x58] = &pop2;
  (*instructionsMap)[0x59] = &dup;
  (*instructionsMap)[0x5a] = &dup_x1;
  (*instructionsMap)[0x5b] = &dup_x2;
  (*instructionsMap)[0x5c] = &dup2;
  (*instructionsMap)[0x5d] = &dup2_x1;
  (*instructionsMap)[0x5e] = &dup2_x2;
  (*instructionsMap)[0x5f] = &swap;
  (*instructionsMap)[0x60] = &iadd;
  (*instructionsMap)[0x61] = &ladd;
  (*instructionsMap)[0x62] = &fadd;
  (*instructionsMap)[0x63] = &dadd;
  (*instructionsMap)[0x64] = &isub;
  (*instructionsMap)[0x65] = &lsub;
  (*instructionsMap)[0x66] = &fsub;
  (*instructionsMap)[0x67] = &dsub;
  (*instructionsMap)[0x68] = &imul;
  (*instructionsMap)[0x69] = &lmul;
  (*instructionsMap)[0x6a] = &fmul;
  (*instructionsMap)[0x6b] = &dmul;
  (*instructionsMap)[0x6c] = &idiv;
  (*instructionsMap)[0x6d] = &ldiv;
  (*instructionsMap)[0x6e] = &fdiv;
  (*instructionsMap)[0x6f] = &ddiv;
  (*instructionsMap)[0x70] = &irem;
  (*instructionsMap)[0x71] = &lrem;
  (*instructionsMap)[0x72] = &frem;
  (*instructionsMap)[0x73] = &drem;
  (*instructionsMap)[0x74] = &ineg;
  (*instructionsMap)[0x75] = &lneg;
  (*instructionsMap)[0x76] = &fneg;
  (*instructionsMap)[0x77] = &dneg;
  (*instructionsMap)[0x78] = &ishl;
  (*instructionsMap)[0x79] = &lshl;
  (*instructionsMap)[0x7a] = &ishr;
  (*instructionsMap)[0x7b] = &lshr;
  (*instructionsMap)[0x7c] = &iushr;
  (*instructionsMap)[0x7d] = &lushr;
  (*instructionsMap)[0x7e] = &iand;
  (*instructionsMap)[0x7f] = &land;
  (*instructionsMap)[0x80] = &ior;
  (*instructionsMap)[0x81] = &lor;
  (*instructionsMap)[0x82] = &ixor;
  (*instructionsMap)[0x83] = &lxor;
  (*instructionsMap)[0x84] = &iinc;
  (*instructionsMap)[0x85] = &i2l;
  (*instructionsMap)[0x86] = &i2f;
  (*instructionsMap)[0x87] = &i2d;
  (*instructionsMap)[0x88] = &l2i;
  (*instructionsMap)[0x89] = &l2f;
  (*instructionsMap)[0x8a] = &l2d;
  (*instructionsMap)[0x8b] = &f2i;
  (*instructionsMap)[0x8c] = &f2l;
  (*instructionsMap)[0x8d] = &f2d;
  (*instructionsMap)[0x8e] = &d2i;
  (*instructionsMap)[0x8f] = &d2l;
  (*instructionsMap)[0x90] = &d2f;
  (*instructionsMap)[0x91] = &i2b;
  (*instructionsMap)[0x92] = &i2c;
  (*instructionsMap)[0x93] = &i2s;
  (*instructionsMap)[0x94] = &lcmp;
  (*instructionsMap)[0x95] = &fcmpl;
  (*instructionsMap)[0x96] = &fcmpg;
  (*instructionsMap)[0x97] = &dcmpl;
  (*instructionsMap)[0x98] = &dcmpg;
  (*instructionsMap)[0x99] = &ifeq;
  (*instructionsMap)[0x9a] = &ifne;
  (*instructionsMap)[0x9b] = &iflt;
  (*instructionsMap)[0x9c] = &ifge;
  (*instructionsMap)[0x9d] = &ifgt;
  (*instructionsMap)[0x9e] = &ifle;
  (*instructionsMap)[0x9f] = &if_icmpeq;
  (*instructionsMap)[0xa0] = &if_icmpne;
  (*instructionsMap)[0xa1] = &if_icmplt;
  (*instructionsMap)[0xa2] = &if_icmpge;
  (*instructionsMap)[0xa3] = &if_icmpgt;
  (*instructionsMap)[0xa4] = &if_icmple;
  (*instructionsMap)[0xa5] = &if_acmpeq;
  (*instructionsMap)[0xa6] = &if_acmpne;
  (*instructionsMap)[0xa7] = &_goto;
  (*instructionsMap)[0xa8] = &jsr;
  (*instructionsMap)[0xa9] = &ret;
  (*instructionsMap)[0xaa] = &tableswitch;
  (*instructionsMap)[0xab] = &lookupswitch;
  (*instructionsMap)[0xac] = &ireturn;
  (*instructionsMap)[0xad] = &lreturn;
  (*instructionsMap)[0xae] = &freturn;
  (*instructionsMap)[0xaf] = &dreturn;
  (*instructionsMap)[0xb0] = &areturn;
  (*instructionsMap)[0xb1] = &_return;
  (*instructionsMap)[0xb2] = &getstatic;
  (*instructionsMap)[0xb3] = &putstatic;
  (*instructionsMap)[0xb4] = &getfield;
  (*instructionsMap)[0xb5] = &putfield;
  (*instructionsMap)[0xb6] = &invokevirtual;
  (*instructionsMap)[0xb7] = &invokespecial;
  (*instructionsMap)[0xb8] = &invokestatic;
  (*instructionsMap)[0xb9] = &invokeinterface;
  (*instructionsMap)[0xba] = &invokedynamic;
  (*instructionsMap)[0xbb] = &_new;
  (*instructionsMap)[0xbc] = &newarray;
  (*instructionsMap)[0xbd] = &anewarray;
  (*instructionsMap)[0xbe] = &arraylength;
  (*instructionsMap)[0xbf] = &athrow;
  (*instructionsMap)[0xc0] = &checkcast;
  (*instructionsMap)[0xc1] = &instanceof;
  (*instructionsMap)[0xc2] = &monitorenter;
  (*instructionsMap)[0xc3] = &monitorexit;
  (*instructionsMap)[0xc4] = &wide;
  (*instructionsMap)[0xc5] = &multianewarray;
  (*instructionsMap)[0xc6] = &ifnull;
  (*instructionsMap)[0xc7] = &ifnonnull;
  (*instructionsMap)[0xc8] = &goto_w;
  (*instructionsMap)[0xc9] = &jsr_w;
  (*instructionsMap)[0xca] = &breakpoint;
  (*instructionsMap)[0xfe] = &impdep1;
  (*instructionsMap)[0xff] = &impdep2;
};

#pragma region aux

#pragma region u4ToType

int32_t u4ToInt (u4 value) {
  return (int32_t) value;
}

int64_t u4ToLong (u4 low, u4 high) {
  return ((int64_t) high << 32) | (int64_t) low;
}

float u4ToFloat (u4 value) {
    int sinal = ((value >> 31) == 0) ? 1 : -1;
    int expon = ((value >> 23) & 0xff);
    int mant = (expon == 0) ? (value & 0x7fffff) << 1 : (value & 0x7fffff) | 0x800000;
    float result = (sinal) * (mant) * (pow(2, expon - 150));
    return result;
}

double u4ToDouble(u4 low, u4 high)
{
    uint64_t valor = ((uint64_t)high << 32) | (uint64_t)low;
    int sinal = ((valor >> 63) == 0) ? 1 : -1;
    int expon = ((valor >> 52) & 0x7ffL);
    long mant = (expon == 0) ? ((valor & 0xfffffffffffffL) << 1) : ((valor & 0xfffffffffffffL) | 0x10000000000000L);

    double retorno = sinal * mant * (pow(2, expon - 1075));
    return retorno;
}

#pragma endregion

#pragma region typeToU4

u4 intToU4(int32_t value) {
  return (u4) value;
}

pair<u4, u4> longToU8(int64_t value) {
  u4 low = (u4) value;
  u4 high = (u4) (value >> 32);


  pair<u4, u4> result;
  result.first = low;
  result.second = high;
  return result;
}

u4 floatToU4(float value) {
  u4 result = 0;
  int sinal = (value < 0) ? 1 : 0;
  int expoente = 0;
  float mantissa = 0;

  if (value == 0) {
    return 0;
  }

  if (value == INFINITY) {
    return 0x7f800000;
  }

  if (value == -INFINITY) {
    return 0xff800000;
  }

  if (isnan(value)) {
    return 0x7fc00000;
  }

  if (value < 0) {
    value = -value;
  }

  mantissa = frexp(value, &expoente);

  expoente += 126;
  mantissa *= 2;
  if (mantissa >= 1) {
    mantissa -= 1;
  }

  result = (sinal << 31) | (expoente << 23) | ((int) (mantissa * pow(2, 23)));

  return result;
}

pair<u4,u4> doubleToU8(double value) {

  int sinal = (value < 0) ? 1 : 0;
  int expoente = 0;
  double mantissa = 0;

  if (value == 0) {
    return {0, 0};
  }

  if (value == INFINITY) {
    return {0, 0x7ff00000}; // 0x7ff0000000000000
  }

  if (value == -INFINITY) {
    return {0, 0xfff00000}; // 0xfff0000000000000
  }

  if (isnan(value)) {
    return {0, 0x7ff80000}; // 0x7ff8000000000000
  }

  if (value < 0) {
    value = -value;
  }

  mantissa = frexp(value, &expoente);

  expoente += 1022;
  mantissa *= 2;
  if (mantissa >= 1) {
    mantissa -= 1;
  }

  u8 result = ((u8) sinal << 63) | ((u8) expoente << 52) | ((u8) (mantissa * pow(2, 52)));

  return {result & 0xffffffff, result >> 32};
}

#pragma endregion

void iconst(u4 value, Frame * frame) {
  
  JvmValue jvmValue;
  jvmValue.type = INT;
  jvmValue.data = value;
  frame->operandStack.push(jvmValue);
  
  //JvmValue jvmValueToPrint = frame->operandStack.top();
  // cout << "item no topo pilha " << jvmValueToPrint.data << endl;
}

void lconst(u4 value, Frame * frame){

  JvmValue jvmValue;
  jvmValue.type = LONG;
  jvmValue.data = value;
  frame->operandStack.push(jvmValue);

}

void fconst(u4 value, Frame * frame){

  JvmValue jvmValue;
  jvmValue.type = FLOAT;
  jvmValue.data = value;
  frame->operandStack.push(jvmValue);

}

void dconst(u4 value, Frame * frame){

  JvmValue jvmValue;
  jvmValue.type = DOUBLE;
  jvmValue.data = value;
  frame->operandStack.push(jvmValue);

}

void load(int index, Frame * frame) {
    // só functiona para itens q ocupam 1 slot
    frame->operandStack.push(frame->localVariables[index]);
}

void store(int index, Frame * frame) {
    // cout << "vendo o topo da pilha que é " << frame->operandStack.top().data << endl;
    
    JvmValue jvmValue = frame->operandStack.top();;
    jvmValue.type = INT;
    // Só funciona pra int

    frame->localVariables[index] = jvmValue;
    // cout << "o topo da pilha é " << frame->localVariables[index].data << endl;
    frame->operandStack.pop();
}

int getCategory(PrimitiveType type) {
  if (type == LONG || type == DOUBLE) {
    return 2;
  } else {
    return 1;
  }
}

#pragma endregion


#pragma region operations

void nop (Frame * frame) {
  cout << "nop" << endl;
  frame->pc += 1;
}

#pragma region const

void aconst_null (Frame * frame) {
  cout << "aconst_null" << endl;
  frame->pc += 1;
}

void iconst_m1 (Frame * frame) {
  cout << "iconst_m1" << endl;
  
  iconst(-1, frame);

  frame->pc += 1;
}

void iconst_0 (Frame * frame) {
  cout << "iconst_0" << endl;

  iconst(0, frame);
  
  frame->pc += 1;
}

void iconst_1 (Frame * frame) {
  cout << "iconst_1" << endl;

  iconst(1, frame);

  frame->pc += 1;
}

void iconst_2 (Frame * frame) {
  cout << "iconst_2" << endl;
  
  iconst(2, frame);
  
  frame->pc += 1;
}

void iconst_3 (Frame * frame) {
  cout << "iconst_3" << endl;

  iconst(3, frame);
  
  frame->pc += 1;
}

void iconst_4 (Frame * frame) {
  cout << "iconst_4" << endl;
  
  iconst(4, frame);
  
  frame->pc += 1; 
}

void iconst_5 (Frame * frame) {
  cout << "iconst_5" << endl;
  
  iconst(5, frame);
  
  frame->pc += 1;
}

void lconst_0 (Frame * frame) {
  cout << "lconst_0" << endl;

  //dar push primeiro no high
  lconst(0, frame);

  //depois no low
  lconst(0, frame);

  frame->pc += 1;
}

void lconst_1 (Frame * frame) {
  cout << "lconst_1" << endl;

  //dar push primeiro no high
  lconst(1, frame);

  //depois no low
  lconst(1, frame);

  frame->pc += 1;
}

void fconst_0 (Frame * frame) {
  cout << "fconst_0" << endl;

  fconst(0, frame);

  frame->pc += 1;
}

void fconst_1 (Frame * frame) {
  cout << "fconst_1" << endl;

  fconst(1, frame);

  frame->pc += 1;
}

void fconst_2 (Frame * frame) {
  cout << "fconst_2" << endl;
  
  fconst(2, frame);
  
  frame->pc += 1;
}

void dconst_0 (Frame * frame) {
  cout << "dconst_0" << endl;

  dconst(0, frame);
  
  dconst(0, frame);

  frame->pc += 1;
}

void dconst_1 (Frame * frame) {
  cout << "dconst_1" << endl;
  
  dconst(1, frame);

  dconst(1, frame);
  
  frame->pc += 1;
}

#pragma endregion

#pragma region push

void bipush (Frame * frame) {
  cout << "bipush" << endl;
  u1 bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  int8_t bytesSigned = bytes;

  JvmValue value;
  value.type = INT;
  value.data = bytesSigned;
  frame->operandStack.push(value);
  cout << "valor empilhado: " << frame->operandStack.top().data << endl;
  frame->pc += 2;
}

void sipush (Frame * frame) {
  cout << "sipush" << endl;
  u1 bytes1 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 bytes2 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  u2 bytes = (bytes1 << 8) | bytes2;
  int16_t bytesSigned = (int16_t) bytes;

  JvmValue value;
  value.type = INT;
  value.data = bytesSigned;
  frame->operandStack.push(value);
  cout << "valor empilhado: " << frame->operandStack.top().data << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region ldc

void ldc (Frame * frame) {
  cout << "ldc" << endl;
  u1 id = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  cp_info * c = frame->methodAreaItem->getConstantPoolItem(id);
  cout << "tipo da constante: " << c->tag << endl;

  JvmValue value;
  switch (c->tag) {
    case 3:
      cout << "int" << endl;
      value.type = INT;
      value.data = c->constant_type_union.Integer.bytes;
      break;
    case 4:
      cout << "float" << endl;
      value.type = FLOAT;
      value.data = c->constant_type_union.Float.bytes;
      break;
    case 8:
      cout << "string" << endl;
      value.type = STRING;
      value.data = c->constant_type_union.String.string_index;
      break;
    default:
      cout << "tipo não reconhecido" << endl;
      break;
  }
  frame->operandStack.push(value);
  cout << "valor empilhado: " << frame->operandStack.top().data << endl;
  frame->pc += 2;
}

void ldc_w (Frame * frame) {
  // esse é wide e só é usado para indice de constant pool grande
  cout << "ldc_w" << endl;

  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  u4 id = (high_bytes << 8) | low_bytes;

  cp_info * c = frame->methodAreaItem->getConstantPoolItem(id);
  cout << "tipo da constante: " << c->tag << endl;

  JvmValue value;
  switch (c->tag) {
    case 3:
      cout << "int" << endl;
      value.type = INT;
      value.data = c->constant_type_union.Integer.bytes;
      break;
    case 4:
      cout << "float" << endl;
      value.type = FLOAT;
      value.data = c->constant_type_union.Float.bytes;
      break;
    case 8:
      cout << "string" << endl;
      value.type = STRING;
      value.data = c->constant_type_union.String.string_index;
      break;
    default:
      cout << "tipo não reconhecido" << endl;
      break;
  }
  frame->operandStack.push(value);
  cout << "valor empilhado: " << frame->operandStack.top().data << endl;

  frame->pc += 3;
}

void ldc2_w (Frame * frame) {
  cout << "ldc2_w" << endl;

  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  u4 id = (high_bytes << 8) | low_bytes;

  cp_info * c = frame->methodAreaItem->getConstantPoolItem(id);
  cout << "tipo da constante: " << c->tag << endl;

  JvmValue high_value;
  JvmValue low_value;

  switch (c->tag) {
    case 6:
      cout << "double" << endl;
      high_value.type = DOUBLE;
      low_value.type = DOUBLE;
      high_value.data = c->constant_type_union.Double.high_bytes;
      low_value.data = c->constant_type_union.Double.low_bytes;
      break;
    case 5:
      cout << "long" << endl;
      high_value.type = LONG;
      low_value.type = LONG;
      high_value.data = c->constant_type_union.Long.high_bytes;
      low_value.data = c->constant_type_union.Long.low_bytes;
      break;
    default:
      cout << "tipo não reconhecido" << endl;
      break;
  }

  frame->operandStack.push(high_value);
  frame->operandStack.push(low_value);
  cout << "valor empilhado: " << frame->operandStack.top().data << endl;

  frame->pc += 3;
}

#pragma endregion

#pragma region load

void iload (Frame * frame) {
  cout << "iload" << endl;
  u1 immediate = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  load(immediate, frame);
  frame->pc += 2;
}

void lload (Frame * frame) {
  cout << "lload" << endl;

  

  frame->pc += 2;
}

void fload (Frame * frame) {
  cout << "fload" << endl;
  u1 immediate = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  load(immediate, frame);
  frame->pc += 2;
}

void dload (Frame * frame) {
  cout << "dload" << endl;
  // load de 2 bytes
  frame->pc += 2;
}

void aload (Frame * frame) {
  cout << "aload" << endl;
  u1 immediate = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  load(immediate, frame);
  frame->pc += 2;
}

void iload_0 (Frame * frame) {
  cout << "iload_0" << endl;
  load(0, frame);
  frame->pc += 1;
}

void iload_1 (Frame * frame) {
  cout << "iload_1" << endl;
  load(1, frame);
  cout << "topo da pilha é " << frame->operandStack.top().data << endl;
  frame->pc += 1;
}

void iload_2 (Frame * frame) {
  cout << "iload_2" << endl;
  load(2, frame);
  frame->pc += 1;
}

void iload_3 (Frame * frame) {
  cout << "iload_3" << endl;
  load(3, frame);
  frame->pc += 1;
}

void lload_0 (Frame * frame) {
  cout << "lload_0" << endl;
  frame->pc += 1;
}

void lload_1 (Frame * frame) {
  cout << "lload_1" << endl;
  frame->pc += 1;
}

void lload_2 (Frame * frame) {
  cout << "lload_2" << endl;
  frame->pc += 1;
}

void lload_3 (Frame * frame) {
  cout << "lload_3" << endl;
  frame->pc += 1;
}

void fload_0 (Frame * frame) {
  cout << "fload_0" << endl;
  load(0, frame);
  frame->pc += 1;
}

void fload_1 (Frame * frame) {
  cout << "fload_1" << endl;
  load(1, frame);
  frame->pc += 1;
}

void fload_2 (Frame * frame) {
  cout << "fload_2" << endl;
  load(2, frame);
  frame->pc += 1;
}

void fload_3 (Frame * frame) {
  cout << "fload_3" << endl;
  load(3, frame);
  frame->pc += 1;
}

void dload_0 (Frame * frame) {
  cout << "dload_0" << endl;
  frame->pc += 1;
}

void dload_1 (Frame * frame) {
  cout << "dload_1" << endl;
  frame->pc += 1;
}

void dload_2 (Frame * frame) {
  cout << "dload_2" << endl;
  frame->pc += 1;
}

void dload_3 (Frame * frame) {
  cout << "dload_3" << endl;
  frame->pc += 1;
}

void aload_0 (Frame * frame) {
  cout << "aload_0" << endl;
  load(0, frame);
  frame->pc += 1;
}

void aload_1 (Frame * frame) {
  cout << "aload_1" << endl;
  load(1, frame);
  frame->pc += 1;
}

void aload_2 (Frame * frame) {
  cout << "aload_2" << endl;
  load(2, frame);
  frame->pc += 1;
}

void aload_3 (Frame * frame) {
  cout << "aload_3" << endl;
  load(3, frame);
  frame->pc += 1;
}

void iaload (Frame * frame) {
  cout << "iaload" << endl;
  frame->pc += 1;
}

void laload (Frame * frame) {
  cout << "laload" << endl;
  frame->pc += 1;
}

void faload (Frame * frame) {
  cout << "faload" << endl;
  frame->pc += 1;
}

void daload (Frame * frame) {
  cout << "daload" << endl;
  frame->pc += 1;
}

void aaload (Frame * frame) {
  cout << "aaload" << endl;
  frame->pc += 1;
}

void baload (Frame * frame) {
  cout << "baload" << endl;
  frame->pc += 1;
}

void caload (Frame * frame) {
  cout << "caload" << endl;
  frame->pc += 1;
}

void saload (Frame * frame) {
  cout << "saload" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region store

void istore (Frame * frame) {
  cout << "istore" << endl;
  store(frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1], frame); 
  frame->pc += 2;
}

void lstore (Frame * frame) {
  cout << "lstore" << endl;
  frame->pc += 2;
}

void fstore (Frame * frame) {
  cout << "fstore" << endl;
  frame->pc += 2;
}

void dstore (Frame * frame) {
  cout << "dstore" << endl;
  frame->pc += 2;
}

void astore (Frame * frame) {
  cout << "astore" << endl;
  frame->pc += 2;
}

void istore_0 (Frame * frame) {
  cout << "istore_0" << endl;

  store(0, frame);

  frame->pc += 1;
}

void istore_1 (Frame * frame) {
  cout << "istore_1" << endl;

  store(1, frame);

  frame->pc += 1;
  cout << "vetor de variaveis de indice = 1 " << frame->localVariables[1].data << endl;  
}

void istore_2 (Frame * frame) {
  cout << "istore_2" << endl;
  
  store(2, frame);
  
  frame->pc += 1;
}

void istore_3 (Frame * frame) {
  cout << "istore_3" << endl;
  
  store(3, frame);
  
  frame->pc += 1;
}

void lstore_0 (Frame * frame) {
  cout << "lstore_0" << endl;
  frame->pc += 1;
}

void lstore_1 (Frame * frame) {
  cout << "lstore_1" << endl;
  frame->pc += 1;
}

void lstore_2 (Frame * frame) {
  cout << "lstore_2" << endl;
  frame->pc += 1;
}

void lstore_3 (Frame * frame) {
  cout << "lstore_3" << endl;
  frame->pc += 1;
}

void fstore_0 (Frame * frame) {
  cout << "fstore_0" << endl;
  frame->pc += 1;
}

void fstore_1 (Frame * frame) {
  cout << "fstore_1" << endl;
  frame->pc += 1;
}

void fstore_2 (Frame * frame) {
  cout << "fstore_2" << endl;
  frame->pc += 1;
}

void fstore_3 (Frame * frame) {
  cout << "fstore_3" << endl;
  frame->pc += 1;
}

void dstore_0 (Frame * frame) {
  cout << "dstore_0" << endl;
  frame->pc += 1;
}

void dstore_1 (Frame * frame) {
  cout << "dstore_1" << endl;
  frame->pc += 1;
}

void dstore_2 (Frame * frame) {
  cout << "dstore_2" << endl;
  frame->pc += 1;
}

void dstore_3 (Frame * frame) {
  cout << "dstore_3" << endl;
  frame->pc += 1;
}

void astore_0 (Frame * frame) {
  cout << "astore_0" << endl;
  frame->pc += 1;
}

void astore_1 (Frame * frame) {
  cout << "astore_1" << endl;
  frame->pc += 1;
}

void astore_2 (Frame * frame) {
  cout << "astore_2" << endl;
  frame->pc += 1;
}

void astore_3 (Frame * frame) {
  cout << "astore_3" << endl;
  frame->pc += 1;
}

void iastore (Frame * frame) {
  cout << "iastore" << endl;
  frame->pc += 1;
}

void lastore (Frame * frame) {
  cout << "lastore" << endl;
  frame->pc += 1;
}

void fastore (Frame * frame) {
  cout << "fastore" << endl;
  frame->pc += 1;
}

void dastore (Frame * frame) {
  cout << "dastore" << endl;
  frame->pc += 1;
}

void aastore (Frame * frame) {
  cout << "aastore" << endl;
  frame->pc += 1;
}

void bastore (Frame * frame) {
  cout << "bastore" << endl;
  frame->pc += 1;
}

void castore (Frame * frame) {
  cout << "castore" << endl;
  frame->pc += 1;
}

void sastore (Frame * frame) {
  cout << "sastore" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region pop

void pop (Frame * frame) {
  cout << "pop" << endl;
  JvmValue value = frame->operandStack.top();
  if (getCategory(value.type) == 1) {
    frame->operandStack.pop();
  } else {
    cout << "pop não ocorreu" << endl;
  }
  frame->pc += 1;
}

void pop2 (Frame * frame) {
  cout << "pop2" << endl;
  JvmValue value1 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value2 = frame->operandStack.top();
  if ( (getCategory(value1.type) == 1 && getCategory(value2.type) == 1) || (getCategory(value1.type) == 2 && getCategory(value2.type) == 2) ) {
    frame->operandStack.pop();
  } else {
    frame->operandStack.push(value1);
    cout << "pop2 não ocorreu" << endl;
  }
  frame->pc += 1;
}

#pragma endregion

#pragma region dup

void dup (Frame * frame) {
  cout << "dup" << endl;
  frame->pc += 1;
}

void dup_x1 (Frame * frame) {
  cout << "dup_x1" << endl;
  frame->pc += 1;
}

void dup_x2 (Frame * frame) {
  cout << "dup_x2" << endl;
  frame->pc += 1;
}

void dup2 (Frame * frame) {
  cout << "dup2" << endl;
  frame->pc += 1;
}

void dup2_x1 (Frame * frame) {
  cout << "dup2_x1" << endl;
  frame->pc += 1;
}

void dup2_x2 (Frame * frame) {
  cout << "dup2_x2" << endl;
  frame->pc += 1;
}

#pragma endregion

void swap (Frame * frame) {
  cout << "swap" << endl;
  frame->pc += 1;
}

#pragma region add

void iadd (Frame * frame) {
  JvmValue first = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue second = frame->operandStack.top();
  frame->operandStack.pop();

  int32_t sum = u4ToInt(first.data) + u4ToInt(second.data);

  cout << "Soma: " << sum << endl;

  JvmValue result;
  result.data = intToU4(sum);
  result.type = INT;

  frame->operandStack.push(result);
  cout << "iadd" << endl;
  frame->pc += 1;
}

void ladd (Frame * frame) {
  cout << "ladd" << endl;
  frame->pc += 1;
}

void fadd (Frame * frame) {
  cout << "fadd" << endl;
  frame->pc += 1;
}

void dadd (Frame * frame) {
  cout << "dadd" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region sub

void isub (Frame * frame) {
  cout << "isub" << endl;
  frame->pc += 1;
}

void lsub (Frame * frame) {
  cout << "lsub" << endl;
  frame->pc += 1;
}

void fsub (Frame * frame) {
  cout << "fsub" << endl;
  frame->pc += 1;
}

void dsub (Frame * frame) {
  cout << "dsub" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region mul

void imul (Frame * frame) {
  cout << "imul" << endl;
  frame->pc += 1;
}

void lmul (Frame * frame) {
  cout << "lmul" << endl;
  frame->pc += 1;
}

void fmul (Frame * frame) {
  cout << "fmul" << endl;
  frame->pc += 1;
}

void dmul (Frame * frame) {
  cout << "dmul" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region div

void idiv (Frame * frame) {
  cout << "idiv" << endl;
  frame->pc += 1;
}

void ldiv (Frame * frame) {
  cout << "ldiv" << endl;
  frame->pc += 1;
}

void fdiv (Frame * frame) {
  cout << "fdiv" << endl;
  frame->pc += 1;
}

void ddiv (Frame * frame) {
  cout << "ddiv" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region rem

void irem (Frame * frame) {
  cout << "irem" << endl;
  frame->pc += 1;
}

void lrem (Frame * frame) {
  cout << "lrem" << endl;
  frame->pc += 1;
}

void frem (Frame * frame) {
  cout << "frem" << endl;
  frame->pc += 1;
}

void drem (Frame * frame) {
  cout << "drem" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region neg

void ineg (Frame * frame) {
  cout << "ineg" << endl;
  frame->pc += 1;
}

void lneg (Frame * frame) {
  cout << "lneg" << endl;
  frame->pc += 1;
}

void fneg (Frame * frame) {
  cout << "fneg" << endl;
  frame->pc += 1;
}

void dneg (Frame * frame) {
  cout << "dneg" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region shift

void ishl (Frame * frame) {
  cout << "ishl" << endl;
  frame->pc += 1;
}

void lshl (Frame * frame) {
  cout << "lshl" << endl;
  frame->pc += 1;
}

void ishr (Frame * frame) {
  cout << "ishr" << endl;
  frame->pc += 1;
}

void lshr (Frame * frame) {
  cout << "lshr" << endl;
  frame->pc += 1;
}

void iushr (Frame * frame) {
  cout << "iushr" << endl;
  frame->pc += 1;
}

void lushr (Frame * frame) {
  cout << "lushr" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region and

void iand (Frame * frame) {
  cout << "iand" << endl;
  frame->pc += 1;
}

void land (Frame * frame) {
  cout << "land" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region or

void ior (Frame * frame) {
  cout << "ior" << endl;
  frame->pc += 1;
}

void lor (Frame * frame) {
  cout << "lor" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region xor

void ixor (Frame * frame) {
  cout << "ixor" << endl;
  frame->pc += 1;
}

void lxor (Frame * frame) {
  cout << "lxor" << endl;
  frame->pc += 1;
}

#pragma endregion

void iinc (Frame * frame) {
  cout << "iinc" << endl;
  frame->pc += 3;
}

#pragma region conversions

void i2l (Frame * frame) {
  cout << "i2l" << endl;
  frame->pc += 1;
}

void i2f (Frame * frame) {
  cout << "i2f" << endl;
  frame->pc += 1;
}

void i2d (Frame * frame) {
  cout << "i2d" << endl;
  frame->pc += 1;
}

void l2i (Frame * frame) {
  cout << "l2i" << endl;
  frame->pc += 1;
}

void l2f (Frame * frame) {
  cout << "l2f" << endl;
  frame->pc += 1;
}

void l2d (Frame * frame) {
  cout << "l2d" << endl;
  frame->pc += 1;
}

void f2i (Frame * frame) {
  cout << "f2i" << endl;
  frame->pc += 1;
}

void f2l (Frame * frame) {
  cout << "f2l" << endl;
  frame->pc += 1;
}

void f2d (Frame * frame) {
  cout << "f2d" << endl;
  frame->pc += 1;
}

void d2i (Frame * frame) {
  cout << "d2i" << endl;
  frame->pc += 1;
}

void d2l (Frame * frame) {
  cout << "d2l" << endl;
  frame->pc += 1;
}

void d2f (Frame * frame) {
  cout << "d2f" << endl;
  frame->pc += 1;
}

void i2b (Frame * frame) {
  cout << "i2b" << endl;
  frame->pc += 1;
}

void i2c (Frame * frame) {
  cout << "i2c" << endl;
  frame->pc += 1;
}

void i2s (Frame * frame) {
  cout << "i2s" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region compares

void lcmp (Frame * frame) {
  cout << "lcmp" << endl;
  frame->pc += 1;
}

void fcmpl (Frame * frame) {
  cout << "fcmpl" << endl;
  frame->pc += 1;
}

void fcmpg (Frame * frame) {
  cout << "fcmpg" << endl;
  frame->pc += 1;
}

void dcmpl (Frame * frame) {
  cout << "dcmpl" << endl;
  frame->pc += 1;
}

void dcmpg (Frame * frame) {
  cout << "dcmpg" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region if

void ifeq (Frame * frame) {
  cout << "ifeq" << endl;
  frame->pc += 3;
}

void ifne (Frame * frame) {
  cout << "ifne" << endl;
  frame->pc += 3;
}

void iflt (Frame * frame) {
  cout << "iflt" << endl;
  frame->pc += 3;
}

void ifge (Frame * frame) {
  cout << "ifge" << endl;
  frame->pc += 3;
}

void ifgt (Frame * frame) {
  cout << "ifgt" << endl;
  frame->pc += 3;
}

void ifle (Frame * frame) {
  cout << "ifle" << endl;
  frame->pc += 3;
}

void if_icmpeq (Frame * frame) {
  cout << "if_icmpeq" << endl;
  frame->pc += 3;
}

void if_icmpne (Frame * frame) {
  cout << "if_icmpne" << endl;
  frame->pc += 3;
}

void if_icmplt (Frame * frame) {
  cout << "if_icmplt" << endl;
  frame->pc += 3;
}

void if_icmpge (Frame * frame) {
  cout << "if_icmpge" << endl;
  frame->pc += 3;
}

void if_icmpgt (Frame * frame) {
  cout << "if_icmpgt" << endl;
  frame->pc += 3;
}

void if_icmple (Frame * frame) {
  cout << "if_icmple" << endl;
  frame->pc += 3;
}

void if_acmpeq (Frame * frame) {
  cout << "if_acmpeq" << endl;
  frame->pc += 3;
}

void if_acmpne (Frame * frame) {
  cout << "if_acmpne" << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region jump

void _goto (Frame * frame) {
  cout << "goto" << endl;
  
  u1 start_pc = frame->pc;
  
  frame->pc++;
  u1 first_brach_byte = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc];
  frame->pc++;
  u1 second_brach_byte = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc];

  u4 branchoffset = (first_brach_byte << 8) | second_brach_byte;

  // cout << "branchoffset " <<  branchoffset << endl;
  cout << "jumping to pc " << start_pc + branchoffset << endl;
  frame->pc += branchoffset;
}

void jsr (Frame * frame) {
  cout << "jsr" << endl;
  frame->pc += 3;
}

void ret (Frame * frame) {
  cout << "ret" << endl;
  frame->pc += 2;
}

#pragma endregion

#pragma region switch

//implementado pelo Piano 
void tableswitch (Frame * frame) {
  cout << "tableswitch" << endl;


  code_attribute codeAtt = frame->method_info->attributes->attribute_info_union.code_attribute;
  
  u1* code_arr = codeAtt.code;

  int aux_pc = frame->pc; 

  //acho que nao precisa, uma vez que a start position é o proprio pc
  // int start_position = aux_pc;

  //pulando padding
  int fator; 
  if(aux_pc < 4){
      fator = 4 - aux_pc;
  }
  else if(aux_pc > 4){
      fator = aux_pc % 4;
  }
  else if(aux_pc == 4){
      fator = 1;
  };
  for(int i=0; i < fator;i++){
      ++(aux_pc);
  }

  // int start_index = ((3 - (aux_pc % 4)) + aux_pc);

  // carregando bytes
  int defaultbyte1 = code_arr[aux_pc];
  ++(aux_pc); 
  int defaultbyte2 = code_arr[aux_pc];
  ++(aux_pc); 
  int defaultbyte3 = code_arr[aux_pc];
  ++(aux_pc); 
  int defaultbyte4 = code_arr[aux_pc];
  ++(aux_pc); 

  int lowbyte1 = code_arr[aux_pc];
  ++(aux_pc); 
  int lowbyte2 = code_arr[aux_pc];
  ++(aux_pc); 
  int lowbyte3 = code_arr[aux_pc];
  ++(aux_pc); 
  int lowbyte4 = code_arr[aux_pc];
  ++(aux_pc); 

  int highbyte1 = code_arr[aux_pc];
  ++(aux_pc); 
  int highbyte2 = code_arr[aux_pc];
  ++(aux_pc); 
  int highbyte3 = code_arr[aux_pc];
  ++(aux_pc); 
  int highbyte4 = code_arr[aux_pc];
  ++(aux_pc); 

  // int32_t default_bytes =  defaultbyte1 << 24 | defaultbyte2 << 16 | defaultbyte3 << 8 | defaultbyte4; 
  // int32_t low_bytes =  lowbyte1 << 24 | lowbyte2 << 16 | lowbyte3 << 8 | lowbyte4; 
  int32_t high_bytes =  highbyte1 << 24 | highbyte2 << 16 | highbyte3 << 8 | highbyte4;

  //logica do table switch levando em conta o index na pilha de operandos
  JvmValue index = frame->operandStack.top();
  cout << "table index = " << index.data << endl;
  cout << "high bytes = " <<high_bytes << endl;

  //iterar entre tamanho de high_bytes 
  for (int i = 0; i < high_bytes; i++){
      
      int byte1 = code_arr[aux_pc];
      ++(aux_pc); 
      int byte2 = code_arr[aux_pc];
      ++(aux_pc ); 
      int byte3 = code_arr[aux_pc];
      ++(aux_pc); 
      int byte4 = code_arr[aux_pc];
      ++(aux_pc); 
      

      int32_t bytes =  byte1 << 24 | byte2 << 16 | byte3 << 8 | byte4;
      
      int32_t jump_bytes = frame->pc + bytes;

      if(index.data == (u4) i + 1){
          cout << "table index == " << i+1 << " pulando para o endereço " << frame->pc + bytes <<endl;
          frame->pc += bytes;
          break;
      }
      
      printf("\t\t%d: %d (+%d)\n", i + 1, jump_bytes, bytes);
  };

}

void lookupswitch (Frame * frame) {
  cout << "lookupswitch" << endl;
  // FIXME: consertar os pulos
  frame->pc += 4;
  frame->pc += 4;
  frame->pc += 4;
  frame->pc += 4;
  frame->pc += 4;
}

#pragma endregion

#pragma region return

void ireturn (Frame * frame) {
  cout << "ireturn" << endl;
  frame->pc += 1;
}

void lreturn (Frame * frame) {
  cout << "lreturn" << endl;
  frame->pc += 1;
}

void freturn (Frame * frame) {
  cout << "freturn" << endl;
  frame->pc += 1;
}

void dreturn (Frame * frame) {
  cout << "dreturn" << endl;
  frame->pc += 1;
}

void areturn (Frame * frame) {
  cout << "areturn" << endl;
  frame->pc += 1;
}

void _return (Frame * frame) {
  cout << "return" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region class_fields

void getstatic (Frame * frame) {
  cout << "getstatic" << endl;

  u1 first_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 second_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];

  u2 index = (first_bytes << 8) | second_bytes;  

  //pegar o dentro do fieldref o class name

  cout << index <<endl ;
  cp_info * field_ref = frame->methodAreaItem->getConstantPoolItem(index);
  cout << field_ref->constant_type_union.Fieldref_info.class_index <<endl ;
  
  u1 class_index = field_ref->constant_type_union.Fieldref_info.class_index;


  //se o class name for <java/lang/System> pular o frame e continuar a vida
  if(frame->methodAreaItem->getUtf8(class_index) == "java/lang/System"){
    cout << "é um getstatic para o System.class " << endl;
    // nao fazer nada
  }
  else {
    // outras classes
    // Precisa procurar o nome da classe no pool de constantes, se não tiver, loadar a classe
    // precisa procurar o field estático na classe carregada
    // precisa colocar o field na pilha de operandos
  }
  frame->pc += 3;
}

void putstatic (Frame * frame) {
  cout << "putstatic" << endl;
  frame->pc += 3;
}

void getfield (Frame * frame) {
  cout << "getfield" << endl;
  frame->pc += 3;
}

void putfield (Frame * frame) {
  cout << "putfield" << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region invoke

void invokevirtual (Frame * frame) {
  cout << "invokevirtual" << endl;

  u1 first_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 second_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];

  u2 index = (first_bytes << 8) | second_bytes;  

  cp_info * method_ref = frame->methodAreaItem->getConstantPoolItem(index);
  string className = frame->methodAreaItem->getUtf8(method_ref->constant_type_union.Methodref_info.class_index);

  if(className == "java/io/PrintStream") {
    JvmValue value = frame->operandStack.top();
    frame->operandStack.pop();

    switch (value.type) {
      case INT:
        cout << (int32_t) value.data << endl;
        break;
      case FLOAT:
        // TODO: printar float
        cout << "u4: " << value.data << endl;
        break;
      case STRING:
      {
        string output = frame->methodAreaItem->getUtf8(value.data);
        cout << output << endl;
        break;
      }
      default:
        cout << "Tipo não suportado" << endl;
        break;
    }
  }

  frame->pc += 3;
}

void invokespecial (Frame * frame) {
  


  cout << "invokespecial" << endl;
  frame->pc += 3;
}

void invokestatic (Frame * frame) {
  cout << "invokestatic" << endl;
  frame->pc += 3;
}

void invokeinterface (Frame * frame) {
  cout << "invokeinterface" << endl;
  frame->pc += 5;
}

void invokedynamic (Frame * frame) {
  cout << "invokedynamic" << endl;
  frame->pc += 5;
}

#pragma endregion

#pragma region new

void _new (Frame * frame) {
  cout << "new" << endl;
  frame->pc += 3;
}

void newarray (Frame * frame) {
  cout << "newarray" << endl;
  frame->pc += 2;
}

void anewarray (Frame * frame) {
  cout << "anewarray" << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region common

void arraylength (Frame * frame) {
  cout << "arraylength" << endl;
  frame->pc += 1;
}

void athrow (Frame * frame) {
  cout << "athrow" << endl;
  frame->pc += 1;
}

void checkcast (Frame * frame) {
  cout << "checkcast" << endl;
  frame->pc += 3;
}

void instanceof (Frame * frame) {
  cout << "instanceof" << endl;
  frame->pc += 3;
}

#pragma endregion

void monitorenter (Frame * frame) {
  cout << "monitorenter" << endl;
  frame->pc += 1;
}

void monitorexit (Frame * frame) {
  cout << "monitorexit" << endl;
  frame->pc += 1;
}

void wide (Frame * frame) {
  cout << "wide" << endl;
  notSupported();
}

void multianewarray (Frame * frame) {
  cout << "multianewarray" << endl;
  frame->pc += 4;
}

#pragma region ifnull

void ifnull (Frame * frame) {
  cout << "ifnull" << endl;
  frame->pc += 3;
}

void ifnonnull (Frame * frame) {
  cout << "ifnonnull" << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region jump_w

void goto_w (Frame * frame) {
  cout << "goto_w" << endl;
  frame->pc += 5;
}

void jsr_w (Frame * frame) {
  cout << "jsr_w" << endl;
  frame->pc += 5;
}

#pragma endregion

void breakpoint (Frame * frame) {
  cout << "breakpoint" << endl;
  notSupported();
}

#pragma region impdep

void impdep1 (Frame * frame) {
  cout << "impdep1" << endl;
  notSupported();
}

void impdep2 (Frame * frame) {
  cout << "impdep2" << endl;
  notSupported();
}

#pragma endregion

void notSupported() {
  cout << "Instrução não suportada" << endl;
  exit(1);
}

#pragma endregion
