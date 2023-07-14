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

double u4ToDouble(u4 low, u4 high) {
    uint64_t valor = ((uint64_t)high << 32) | (uint64_t)low;
    // int sinal = ((valor >> 63) == 0) ? 1 : -1;
    // int expon = ((valor >> 52) & 0x7ffL);
    // long mant = (expon == 0) ? ((valor & 0xfffffffffffffL) << 1) : ((valor & 0xfffffffffffffL) | 0x10000000000000L);

    // double retorno = sinal * mant * (pow(2, expon - 1075));
    // return retorno;

    double d;
    memcpy(&d, &valor, sizeof(d));
    return d;
}

#pragma endregion

#pragma region typeToU4

u4 intToU4(int32_t value) {
  return (u4) value;
}

pair<u4, u4> longToU8(int64_t value) {
  u4 low = (u4) value;
  u4 high = (u4) (value >> 32);

  return {low, high};
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

  u4 low = result & 0xffffffff;
  u4 high = result >> 32;
  return {low, high};
}

#pragma endregion

void iconst(u4 value, Frame * frame) {
  
  JvmValue jvmValue;
  jvmValue.type = INT;
  jvmValue.data = value;
  frame->pushOperandStack(jvmValue);
  
  // FIXME: não sei pq isso ta comentado, mas chequem (maycon)
  //JvmValue jvmValueToPrint = frame->operandStack.top();
  // cout << "item no topo pilha " << jvmValueToPrint.data << endl;
}

void lconst(u4 value, Frame * frame){

  JvmValue jvmValue;
  jvmValue.type = LONG;
  jvmValue.data = value;
  frame->pushOperandStack(jvmValue);

}

void fconst(u4 value, Frame * frame){

  JvmValue jvmValue;
  jvmValue.type = FLOAT;
  jvmValue.data = value;
  frame->pushOperandStack(jvmValue);

}

void dconst(u4 value, Frame * frame){

  JvmValue jvmValue;
  jvmValue.type = DOUBLE;
  jvmValue.data = value;
  frame->pushOperandStack(jvmValue);

}

void load(int index, Frame * frame) {
  frame->pushOperandStack(frame->localVariables[index]);
}

void loadWide(int index, Frame * frame) {
  JvmValue jvmValueHighBytes = frame->localVariables[index];
  JvmValue jvmValueLowBytes = frame->localVariables[index + 1];
  frame->pushWideOperandStack(jvmValueLowBytes, jvmValueHighBytes);
}

void store(int index, Frame * frame, JvmValue jvmValue) {
    frame->localVariables[index] = jvmValue;
}

void storeFromStack(int index, Frame * frame) {
  JvmValue jvmValue = frame->popOperandStack();

  store(index, frame, jvmValue);
}

void storeFromStackWide(int index, Frame * frame) {
  auto [jvmValueLowBytes, jvmValueHighBytes] = frame->popWideOperandStack();

  store(index, frame, jvmValueHighBytes);
  store(index + 1, frame, jvmValueLowBytes);
}

int getCategory(PrimitiveType type) {
  if (type == LONG || type == DOUBLE) {
    return 2;
  } else {
    return 1;
  }
}

void javaPrintln(Frame * frame, vector<string> argTypes) {
  string argType = argTypes[0];

  if (argType == "INT")
  {
    // + "BYTE" jvm interpreta byte como int no print, não sei se em outros casos é assim
    // + "SHORT" jvm interpreta short como int no print, não sei se em outros casos é assim
    JvmValue value = frame->popOperandStack();
    int32_t integer = u4ToInt(value.data);
    cout << integer << endl;
  }
  else if (argType == "FLOAT")
  {
    JvmValue value = frame->popOperandStack();
    float _float = u4ToFloat(value.data);
    cout << fixed << setprecision(7) << _float << endl;
  }
  else if (argType == "LONG")
  {
    auto [low, high] = frame->popWideOperandStack();
    int64_t _long = u4ToLong(low.data, high.data);
    cout << _long << endl;
  }
  else if (argType == "DOUBLE")
  {
    auto [low, high] = frame->popWideOperandStack();
    double _double = u4ToDouble(low.data, high.data);
    cout << fixed << setprecision(15) << _double << endl;
  }
  else if (argType == "Ljava/lang/String;")
  { // STRING
    JvmValue value = frame->popOperandStack();
    string _string = frame->methodAreaItem->getUtf8(value.data);
    cout << _string << endl;
  }
  else if (argType == "CHAR")
  {
    JvmValue value = frame->popOperandStack();
    char _char = value.data;
    cout << _char << endl;
  }
  else if (argType == "BOOL")
  {
    JvmValue value = frame->popOperandStack();
    bool _bool = value.data;
    cout << (_bool ? "true" : "false") << endl;
  }
  else if (argType == "VOID")
  {
    cout << endl;
  }
  else
  {
  // TODO: print CHAR[]
  // TODO: print OBJECT
    throw std::runtime_error("Tipo não suportado (" + argType + ")");
  }
}

#pragma endregion


#pragma region operations

void nop (Frame * frame, JVM * jvm) {
  DCOUT << "nop" << endl;
  frame->pc += 1;
}

#pragma region const

void aconst_null (Frame * frame, JVM * jvm) {
  DCOUT << "aconst_null" << endl;
  frame->pc += 1;
}

void iconst_m1 (Frame * frame, JVM * jvm) {
  DCOUT << "iconst_m1" << endl;
  
  iconst(-1, frame);

  frame->pc += 1;
}

void iconst_0 (Frame * frame, JVM * jvm) {
  DCOUT << "iconst_0" << endl;

  iconst(0, frame);
  
  frame->pc += 1;
}

void iconst_1 (Frame * frame, JVM * jvm) {
  DCOUT << "iconst_1" << endl;

  iconst(1, frame);

  frame->pc += 1;
}

void iconst_2 (Frame * frame, JVM * jvm) {
  DCOUT << "iconst_2" << endl;
  
  iconst(2, frame);
  
  frame->pc += 1;
}

void iconst_3 (Frame * frame, JVM * jvm) {
  DCOUT << "iconst_3" << endl;

  iconst(3, frame);
  
  frame->pc += 1;
}

void iconst_4 (Frame * frame, JVM * jvm) {
  DCOUT << "iconst_4" << endl;
  
  iconst(4, frame);
  
  frame->pc += 1; 
}

void iconst_5 (Frame * frame, JVM * jvm) {
  DCOUT << "iconst_5" << endl;
  
  iconst(5, frame);
  
  frame->pc += 1;
}

void lconst_0 (Frame * frame, JVM * jvm) {
  DCOUT << "lconst_0" << endl;

  //dar push primeiro no high
  lconst(0, frame);

  //depois no low
  lconst(0, frame);

  frame->pc += 1;
}

void lconst_1 (Frame * frame, JVM * jvm) {
  DCOUT << "lconst_1" << endl;

  //dar push primeiro no high
  lconst(1, frame);

  //depois no low
  lconst(1, frame);

  frame->pc += 1;
}

void fconst_0 (Frame * frame, JVM * jvm) {
  DCOUT << "fconst_0" << endl;

  fconst(0, frame);

  frame->pc += 1;
}

void fconst_1 (Frame * frame, JVM * jvm) {
  DCOUT << "fconst_1" << endl;

  fconst(1, frame);

  frame->pc += 1;
}

void fconst_2 (Frame * frame, JVM * jvm) {
  DCOUT << "fconst_2" << endl;
  
  fconst(2, frame);
  
  frame->pc += 1;
}

void dconst_0 (Frame * frame, JVM * jvm) {
  DCOUT << "dconst_0" << endl;

  dconst(0, frame); // FIXME: checa se isso ta certo
  
  dconst(0, frame);

  frame->pc += 1;
}

void dconst_1 (Frame * frame, JVM * jvm) {
  DCOUT << "dconst_1" << endl;
  
  dconst(1, frame);

  dconst(1, frame);
  
  frame->pc += 1;
}

#pragma endregion

#pragma region push

void bipush (Frame * frame, JVM * jvm) {
  DCOUT << "bipush" << endl;
  u1 bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  int8_t bytesSigned = bytes;

  JvmValue value = {INT, bytesSigned};
  frame->pushOperandStack(value);
  DCOUT << "valor empilhado: " << bytesSigned << endl;
  frame->pc += 2;
}

void sipush (Frame * frame, JVM * jvm) {
  DCOUT << "sipush" << endl;
  u1 bytes1 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 bytes2 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  u2 bytes = (bytes1 << 8) | bytes2;
  int16_t bytesSigned = (int16_t) bytes;

  JvmValue value = {INT, bytesSigned};
  frame->pushOperandStack(value);
  DCOUT << "valor empilhado: " << bytesSigned << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region ldc

void ldc (Frame * frame, JVM * jvm) {
  DCOUT << "ldc" << endl;
  u1 id = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  cp_info * c = frame->methodAreaItem->getConstantPoolItem(id);
  DCOUT << "tipo da constante: " << (int) c->tag << endl;

  JvmValue value;
  switch (c->tag) {
    case 3:
      DCOUT << "int" << endl;
      value.type = INT;
      value.data = c->constant_type_union.Integer.bytes;
      break;
    case 4:
      DCOUT << "float" << endl;
      value.type = FLOAT;
      value.data = c->constant_type_union.Float.bytes;
      break;
    case 8:
      DCOUT << "string" << endl;
      value.type = STRING;
      value.data = c->constant_type_union.String.string_index;
      break;
    default:
      throw std::runtime_error("tipo não reconhecido");
  }
  frame->pushOperandStack(value);
  DCOUT << "valor empilhado: " << frame->operandStack.top().data << endl;
  frame->pc += 2;
}

void ldc_w (Frame * frame, JVM * jvm) {
  // esse é wide e só é usado para indice de constant pool grande
  DCOUT << "ldc_w" << endl;

  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  u2 id = (high_bytes << 8) | low_bytes;

  cp_info * c = frame->methodAreaItem->getConstantPoolItem(id);
  DCOUT << "tipo da constante: " << c->tag << endl;

  JvmValue value;
  switch (c->tag) {
    case 3:
      DCOUT << "int" << endl;
      value.type = INT;
      value.data = c->constant_type_union.Integer.bytes;
      break;
    case 4:
      DCOUT << "float" << endl;
      value.type = FLOAT;
      value.data = c->constant_type_union.Float.bytes;
      break;
    case 8:
      DCOUT << "string" << endl;
      value.type = STRING;
      value.data = c->constant_type_union.String.string_index;
      break;
    default:
      throw std::runtime_error("tipo não reconhecido");
      break;
  }
  frame->pushOperandStack(value);
  DCOUT << "valor empilhado: " << frame->operandStack.top().data << endl;

  frame->pc += 3;
}

void ldc2_w (Frame * frame, JVM * jvm) {
  DCOUT << "ldc2_w" << endl;

  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  u2 id = (high_bytes << 8) | low_bytes;

  cp_info * c = frame->methodAreaItem->getConstantPoolItem(id);
  DCOUT << "tipo da constante: " << c->tag << endl;

  JvmValue high_value;
  JvmValue low_value;

  switch (c->tag) {
    case 6:
      DCOUT << "double" << endl;
      high_value.type = DOUBLE;
      low_value.type = DOUBLE;
      high_value.data = c->constant_type_union.Double.high_bytes;
      low_value.data = c->constant_type_union.Double.low_bytes;
      break;
    case 5:
      DCOUT << "long" << endl;
      high_value.type = LONG;
      low_value.type = LONG;
      high_value.data = c->constant_type_union.Long.high_bytes;
      low_value.data = c->constant_type_union.Long.low_bytes;
      break;
    default:
      throw std::runtime_error("tipo não reconhecido");
      break;
  }

  frame->pushWideOperandStack(low_value, high_value);
  DCOUT << "valor empilhado: " << frame->operandStack.top().data << endl;

  frame->pc += 3;
}

#pragma endregion

#pragma region load

void iload (Frame * frame, JVM * jvm) {
  DCOUT << "iload" << endl;
  u1 immediate = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  load(immediate, frame);
  frame->pc += 2;
}

void lload (Frame * frame, JVM * jvm) {
  DCOUT << "lload" << endl;
  u1 index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  loadWide(index, frame);
  frame->pc += 2;
}

void fload (Frame * frame, JVM * jvm) {
  DCOUT << "fload" << endl;
  u1 immediate = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  load(immediate, frame);
  frame->pc += 2;
}

void dload (Frame * frame, JVM * jvm) {
  DCOUT << "dload" << endl;
  u1 immediate = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  loadWide(immediate, frame);
  frame->pc += 2;
}

void aload (Frame * frame, JVM * jvm) {
  DCOUT << "aload" << endl;
  u1 immediate = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  load(immediate, frame);
  frame->pc += 2;
}

void iload_0 (Frame * frame, JVM * jvm) {
  DCOUT << "iload_0" << endl;
  load(0, frame);
  frame->pc += 1;
}

void iload_1 (Frame * frame, JVM * jvm) {
  DCOUT << "iload_1" << endl;
  load(1, frame);
  DCOUT << "topo da pilha é " << frame->operandStack.top().data << endl;
  frame->pc += 1;
}

void iload_2 (Frame * frame, JVM * jvm) {
  DCOUT << "iload_2" << endl;
  load(2, frame);
  frame->pc += 1;
}

void iload_3 (Frame * frame, JVM * jvm) {
  DCOUT << "iload_3" << endl;
  load(3, frame);
  frame->pc += 1;
}

void lload_0 (Frame * frame, JVM * jvm) {
  DCOUT << "lload_0" << endl;
  loadWide(0, frame);
  frame->pc += 1;
}

void lload_1 (Frame * frame, JVM * jvm) {
  DCOUT << "lload_1" << endl;
  loadWide(1, frame);
  frame->pc += 1;
}

void lload_2 (Frame * frame, JVM * jvm) {
  DCOUT << "lload_2" << endl;
  loadWide(2, frame);
  frame->pc += 1;
}

void lload_3 (Frame * frame, JVM * jvm) {
  DCOUT << "lload_3" << endl;
  loadWide(3, frame);
  frame->pc += 1;
}

void fload_0 (Frame * frame, JVM * jvm) {
  DCOUT << "fload_0" << endl;
  load(0, frame);
  frame->pc += 1;
}

void fload_1 (Frame * frame, JVM * jvm) {
  DCOUT << "fload_1" << endl;
  load(1, frame);
  frame->pc += 1;
}

void fload_2 (Frame * frame, JVM * jvm) {
  DCOUT << "fload_2" << endl;
  load(2, frame);
  frame->pc += 1;
}

void fload_3 (Frame * frame, JVM * jvm) {
  DCOUT << "fload_3" << endl;
  load(3, frame);
  frame->pc += 1;
}

void dload_0 (Frame * frame, JVM * jvm) {
  DCOUT << "dload_0" << endl;
  loadWide(0, frame);
  frame->pc += 1;
}

void dload_1 (Frame * frame, JVM * jvm) {
  DCOUT << "dload_1" << endl;
  loadWide(1, frame);
  frame->pc += 1;
}

void dload_2 (Frame * frame, JVM * jvm) {
  DCOUT << "dload_2" << endl;
  loadWide(2, frame);
  frame->pc += 1;
}

void dload_3 (Frame * frame, JVM * jvm) {
  DCOUT << "dload_3" << endl;
  loadWide(3, frame);
  frame->pc += 1;
}

void aload_0 (Frame * frame, JVM * jvm) {
  DCOUT << "aload_0" << endl;
  load(0, frame);
  frame->pc += 1;
}

void aload_1 (Frame * frame, JVM * jvm) {
  DCOUT << "aload_1" << endl;
  load(1, frame);
  frame->pc += 1;
}

void aload_2 (Frame * frame, JVM * jvm) {
  DCOUT << "aload_2" << endl;
  load(2, frame);
  frame->pc += 1;
}

void aload_3 (Frame * frame, JVM * jvm) {
  DCOUT << "aload_3" << endl;
  load(3, frame);
  frame->pc += 1;
}

void iaload (Frame * frame, JVM * jvm) {
  DCOUT << "iaload" << endl;
  frame->pc += 1;
}

void laload (Frame * frame, JVM * jvm) {
  DCOUT << "laload" << endl;
  frame->pc += 1;
}

void faload (Frame * frame, JVM * jvm) {
  DCOUT << "faload" << endl;
  frame->pc += 1;
}

void daload (Frame * frame, JVM * jvm) {
  DCOUT << "daload" << endl;
  frame->pc += 1;
}

void aaload (Frame * frame, JVM * jvm) {
  DCOUT << "aaload" << endl;
  frame->pc += 1;
}

void baload (Frame * frame, JVM * jvm) {
  DCOUT << "baload" << endl;
  frame->pc += 1;
}

void caload (Frame * frame, JVM * jvm) {
  DCOUT << "caload" << endl;
  frame->pc += 1;
}

void saload (Frame * frame, JVM * jvm) {
  DCOUT << "saload" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region store

void istore (Frame * frame, JVM * jvm) {
  DCOUT << "istore" << endl;
  
  u1 local_vector_index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  
  storeFromStack(local_vector_index, frame);

  frame->pc += 2;
}

void lstore (Frame * frame, JVM * jvm) {
  DCOUT << "lstore" << endl;

  u1 local_vector_index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];

  storeFromStackWide(local_vector_index, frame);

  frame->pc += 2;
}

void fstore (Frame * frame, JVM * jvm) {
  DCOUT << "fstore" << endl;

  u1 local_vector_index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];

  storeFromStack(local_vector_index, frame);

  frame->pc += 2;
}

void dstore (Frame * frame, JVM * jvm) {
  DCOUT << "dstore" << endl;

  u1 local_vector_index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];

  storeFromStackWide(local_vector_index, frame);

  frame->pc += 2;
}

void astore (Frame * frame, JVM * jvm) {
  DCOUT << "astore" << endl;
  frame->pc += 2;
}

void istore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "istore_0" << endl;

  storeFromStack(0, frame);

  frame->pc += 1;
}

void istore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "istore_1" << endl;

  storeFromStack(1, frame);

  frame->pc += 1;
  DCOUT << "vetor de variaveis de indice = 1 " << frame->localVariables[1].data << endl;  
}

void istore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "istore_2" << endl;
  
  storeFromStack(2, frame);
  
  frame->pc += 1;
}

void istore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "istore_3" << endl;
  storeFromStack(3, frame);
  frame->pc += 1;
}

void lstore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "lstore_0" << endl;

  storeFromStackWide(0, frame);

  frame->pc += 1;
}

void lstore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "lstore_1" << endl;

  storeFromStackWide(1, frame);

  frame->pc += 1;
}

void lstore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "lstore_2" << endl;

  storeFromStackWide(2, frame);

  frame->pc += 1;
}

void lstore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "lstore_3" << endl;

  storeFromStackWide(3, frame);

  frame->pc += 1;
}

void fstore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "fstore_0" << endl;

  storeFromStack(0, frame);

  frame->pc += 1;
}

void fstore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "fstore_1" << endl;

  storeFromStack(1, frame);

  frame->pc += 1;
}

void fstore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "fstore_2" << endl;

  storeFromStack(2, frame);

  frame->pc += 1;
}

void fstore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "fstore_3" << endl;

  storeFromStack(3, frame);

  frame->pc += 1;
}

void dstore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "dstore_0" << endl;

  storeFromStackWide(0, frame);

  frame->pc += 1;
}

void dstore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "dstore_1" << endl;

  storeFromStackWide(1, frame);

  frame->pc += 1;
}

void dstore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "dstore_2" << endl;

  storeFromStackWide(2, frame);

  frame->pc += 1;
}

void dstore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "dstore_3" << endl;

  storeFromStackWide(3, frame);

  frame->pc += 1;
}

void astore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "astore_0" << endl;
  frame->pc += 1;
}

void astore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "astore_1" << endl;
  frame->pc += 1;
}

void astore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "astore_2" << endl;
  frame->pc += 1;
}

void astore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "astore_3" << endl;
  frame->pc += 1;
}

void iastore (Frame * frame, JVM * jvm) {
  DCOUT << "iastore" << endl;
  frame->pc += 1;
}

void lastore (Frame * frame, JVM * jvm) {
  DCOUT << "lastore" << endl;
  frame->pc += 1;
}

void fastore (Frame * frame, JVM * jvm) {
  DCOUT << "fastore" << endl;
  frame->pc += 1;
}

void dastore (Frame * frame, JVM * jvm) {
  DCOUT << "dastore" << endl;
  frame->pc += 1;
}

void aastore (Frame * frame, JVM * jvm) {
  DCOUT << "aastore" << endl;
  frame->pc += 1;
}

void bastore (Frame * frame, JVM * jvm) {
  DCOUT << "bastore" << endl;
  frame->pc += 1;
}

void castore (Frame * frame, JVM * jvm) {
  DCOUT << "castore" << endl;
  frame->pc += 1;
}

void sastore (Frame * frame, JVM * jvm) {
  DCOUT << "sastore" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region pop

void pop (Frame * frame, JVM * jvm) {
  DCOUT << "pop" << endl;
  JvmValue value = frame->operandStack.top();
  if (getCategory(value.type) == 1) {
    frame->operandStack.pop();
  } else {
      throw std::runtime_error("pop não aconteceu");
  }
  frame->pc += 1;
}

void pop2 (Frame * frame, JVM * jvm) {
  DCOUT << "pop2" << endl;
  JvmValue value1 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value2 = frame->operandStack.top();
  if ( (getCategory(value1.type) == 1 && getCategory(value2.type) == 1) || (getCategory(value1.type) == 2 && getCategory(value2.type) == 2) ) {
    frame->operandStack.pop();
  } else {
    frame->operandStack.push(value1);
    throw std::runtime_error("pop não aconteceu");
  }
  frame->pc += 1;
}

#pragma endregion

#pragma region dup

void dup (Frame * frame, JVM * jvm) {
  DCOUT << "dup" << endl;
  JvmValue value = frame->popOperandStack();
  frame->pushOperandStack(value);
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void dup_x1 (Frame * frame, JVM * jvm) {
  DCOUT << "dup_x1" << endl;
  notSupported();
  frame->pc += 1;
}

void dup_x2 (Frame * frame, JVM * jvm) {
  DCOUT << "dup_x2" << endl;
  notSupported();
  frame->pc += 1;
}

void dup2 (Frame * frame, JVM * jvm) {
  DCOUT << "dup2" << endl;
  notSupported();
  frame->pc += 1;
}

void dup2_x1 (Frame * frame, JVM * jvm) {
  DCOUT << "dup2_x1" << endl;
  notSupported();
  frame->pc += 1;
}

void dup2_x2 (Frame * frame, JVM * jvm) {
  DCOUT << "dup2_x2" << endl;
  notSupported();
  frame->pc += 1;
}

#pragma endregion

void swap (Frame * frame, JVM * jvm) {
  DCOUT << "swap" << endl;
  notSupported();
  frame->pc += 1;
}

enum Operation {
  ADD,
  SUB,
  MUL,
  DIV,
  AND,
  OR,
  XOR,
};

template<typename T>
T calculate(T first, T second, Operation op) {
    T result = 0;

    switch (op) {
        case ADD:
            result = first + second;
            break;
        case SUB:
            result = first - second;
            break;
        case MUL:
            result = first * second;
            break;
        case DIV:
            result = first / second;
            break;
        case AND:
            if constexpr (std::is_integral_v<T>) {
                result = first & second;
                break;
            } else {
                throw std::runtime_error("operacao sem suporte para tipos nao inteiros");
            }
        case OR:
            if constexpr (std::is_integral_v<T>) {
                result = first | second;
                break;
            } else {
                throw std::runtime_error("operacao sem suporte para tipos nao inteiros");
            }
        case XOR:
            if constexpr (std::is_integral_v<T>) {
                result = first ^ second;
                break;
            } else {
                throw std::runtime_error("operacao sem suporte para tipos nao inteiros");
            }
        default:
            throw std::runtime_error("operacao nao implementada");
    }

    return result;
}


void operate(Frame * frame, Operation op, PrimitiveType type) {
  auto [second, first] = frame->popWideOperandStack();

  u4 result = 0;
  switch (type) {
    case INT:
    {
      int32_t calc = calculate<int32_t>(u4ToInt(first.data), u4ToInt(second.data), op);
      DCOUT << "int result: " << calc << endl;
      result = intToU4(calc);
      break;
    }
    case FLOAT:
    {
      float calc = calculate<float>(u4ToFloat(first.data), u4ToFloat(second.data), op);
      DCOUT << "float result: " << calc << endl;
      result = floatToU4(calc);
      break;
    }
  }

  JvmValue resultValue = {type, result};
  frame->pushOperandStack(resultValue);
}

void operateW(Frame * frame, Operation op, PrimitiveType type) {
  auto [secondLower, secondUpper] = frame->popWideOperandStack();
  auto [firstLower, firstUpper] = frame->popWideOperandStack();

  pair<u4, u4> result = {0,0};
  switch (type) {
    case LONG:
    {
      int64_t calc = calculate<int64_t>(u4ToLong(firstLower.data, firstUpper.data), u4ToLong(secondLower.data, secondUpper.data), op);
      DCOUT << "long result:" << calc << endl;
      result = longToU8(calc);
      break;
    }
    case DOUBLE:
    {
      double calc = calculate<double>(u4ToDouble(firstLower.data, firstUpper.data), u4ToDouble(secondLower.data, secondUpper.data), op);
      DCOUT << "double result:" << calc << endl;
      result = doubleToU8(calc);
      break;
    }
  }

  JvmValue resultLower = {type, result.first};
  JvmValue resultUpper = {type, result.second};

  frame->pushWideOperandStack(resultLower, resultUpper);
}


#pragma region add

void iadd (Frame * frame, JVM * jvm) {
  DCOUT << "iadd" << endl;
  operate(frame, ADD, INT);
  frame->pc += 1;
}

void ladd (Frame * frame, JVM * jvm) {
  DCOUT << "ladd" << endl;
  operateW(frame, ADD, LONG);
  frame->pc += 1;
}

void fadd (Frame * frame, JVM * jvm) {
  DCOUT << "fadd" << endl;
  operate(frame, ADD, FLOAT);
  frame->pc += 1;
}

void dadd (Frame * frame, JVM * jvm) {
  DCOUT << "dadd" << endl;
  operateW(frame, ADD, DOUBLE);
  frame->pc += 1;
}

#pragma endregion

#pragma region sub

void isub (Frame * frame, JVM * jvm) {
  DCOUT << "isub" << endl;
  operate(frame, SUB, INT);
  frame->pc += 1;
}

void lsub (Frame * frame, JVM * jvm) {
  DCOUT << "lsub" << endl;
  operateW(frame, SUB, LONG);
  frame->pc += 1;
}

void fsub (Frame * frame, JVM * jvm) {
  DCOUT << "fsub" << endl;
  operate(frame, SUB, FLOAT);
  frame->pc += 1;
}

void dsub (Frame * frame, JVM * jvm) {
  DCOUT << "dsub" << endl;
  operateW(frame, SUB, DOUBLE);
  frame->pc += 1;
}

#pragma endregion

#pragma region mul

void imul (Frame * frame, JVM * jvm) {
  DCOUT << "imul" << endl;
  operate(frame, MUL, INT);
  frame->pc += 1;
}

void lmul (Frame * frame, JVM * jvm) {
  DCOUT << "lmul" << endl;
  operateW(frame, MUL, LONG);
  frame->pc += 1;
}

void fmul (Frame * frame, JVM * jvm) {
  DCOUT << "fmul" << endl;
  operate(frame, MUL, FLOAT);
  frame->pc += 1;
}

void dmul (Frame * frame, JVM * jvm) {
  DCOUT << "dmul" << endl;
  operateW(frame, MUL, DOUBLE);
  frame->pc += 1;
}

#pragma endregion

#pragma region div

void idiv (Frame * frame, JVM * jvm) {
  DCOUT << "idiv" << endl;
  operate(frame, DIV, INT);
  frame->pc += 1;
}

void ldiv (Frame * frame, JVM * jvm) {
  DCOUT << "ldiv" << endl;
  operateW(frame, DIV, LONG);
  frame->pc += 1;
}

void fdiv (Frame * frame, JVM * jvm) {
  DCOUT << "fdiv" << endl;
  operate(frame, DIV, FLOAT);
  frame->pc += 1;
}

void ddiv (Frame * frame, JVM * jvm) {
  DCOUT << "ddiv" << endl;
  operateW(frame, DIV, DOUBLE);
  frame->pc += 1;
}

#pragma endregion

#pragma region rem

void irem (Frame * frame, JVM * jvm) {
  cout << "irem" << endl;
  frame->pc += 1;
}

void lrem (Frame * frame, JVM * jvm) {
  cout << "lrem" << endl;
  frame->pc += 1;
}

void frem (Frame * frame, JVM * jvm) {
  cout << "frem" << endl;
  frame->pc += 1;
}

void drem (Frame * frame, JVM * jvm) {
  cout << "drem" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region neg

void ineg (Frame * frame, JVM * jvm) {
  cout << "ineg" << endl;
  JvmValue value = frame->operandStack.top();
  if (value.type == INT) {
    frame->operandStack.pop();
    int32_t neg = u4ToInt(value.data);
    neg *= -1;
    value.data = neg;
    frame->operandStack.push(value);
    DCOUT << "valor empilhado: " << neg << endl;
  } else {
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void lneg (Frame * frame, JVM * jvm) {
  cout << "lneg" << endl;
  JvmValue value2 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value1 = frame->operandStack.top();
  if (value1.type == LONG && value2.type == LONG) {
    frame->operandStack.pop();
    int64_t neg = u4ToLong(value2.data, value1.data);
    neg *= -1;
    pair<u4, u4> result = longToU8(neg);
    value1.data = result.first;
    value2.data = result.second;
    frame->operandStack.push(value1);
    frame->operandStack.push(value2);
    DCOUT << "valor empilhado: " << neg << endl;
  } else {
    frame->operandStack.push(value2);
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void fneg (Frame * frame, JVM * jvm) {
  cout << "fneg" << endl;
  JvmValue value = frame->operandStack.top();
  if (value.type == FLOAT) {
    frame->operandStack.pop();
    float neg = u4ToFloat(value.data);
    neg *= -1;
    value.data = floatToU4(neg);
    frame->operandStack.push(value);
    DCOUT << "valor empilhado: " << neg << endl;
  } else {
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void dneg (Frame * frame, JVM * jvm) {
  cout << "dneg" << endl;
  JvmValue value2 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value1 = frame->operandStack.top();
  if (value1.type == DOUBLE && value2.type == DOUBLE) {
    frame->operandStack.pop();
    int64_t neg = u4ToDouble(value2.data, value1.data);
    neg *= -1;
    pair<u4, u4> result = doubleToU8(neg);
    value1.data = result.first;
    value2.data = result.second;
    frame->operandStack.push(value1);
    frame->operandStack.push(value2);
    DCOUT << "valor empilhado: " << neg << endl;
  } else {
    frame->operandStack.push(value2);
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

#pragma endregion

#pragma region shift

void ishl (Frame * frame, JVM * jvm) {
  cout << "ishl" << endl;
  JvmValue stack2 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack1 = frame->operandStack.top();
  if (stack1.type == INT && stack2.type == INT) {
    frame->operandStack.pop();
    int32_t value = u4ToInt(stack1.data);
    int32_t shiftby = u4ToInt(stack2.data);
    DCOUT << "Value:" << value << endl;
    DCOUT << "Shiftby: " << shiftby << endl;
    value <<= shiftby;
    stack1.data = value;
    frame->operandStack.push(stack1);
    DCOUT << "valor empilhado: " << value << endl;
  } else {
    frame->operandStack.push(stack2);
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void lshl (Frame * frame, JVM * jvm) {
  cout << "lshl" << endl;
  JvmValue stack3 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack2 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack1 = frame->operandStack.top();
  if (stack1.type == LONG && stack2.type == LONG && stack3.type == INT) {
    frame->operandStack.pop();
    int64_t value = u4ToLong(stack2.data, stack1.data);
    int32_t shiftby = u4ToInt(stack3.data);
    DCOUT << "Value:" << value << endl;
    DCOUT << "Shiftby: " << shiftby << endl;
    value <<= shiftby;
    pair<u4, u4> result = longToU8(value);
    stack1.data = result.first;
    stack2.data = result.second;
    frame->operandStack.push(stack1);
    frame->operandStack.push(stack2);
    DCOUT << "valor empilhado: " << value << endl;
  } else {
    frame->operandStack.push(stack2);
    frame->operandStack.push(stack3);
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void ishr (Frame * frame, JVM * jvm) {
  cout << "ishr" << endl;
  JvmValue stack2 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack1 = frame->operandStack.top();
  if (stack1.type == INT && stack2.type == INT) {
    frame->operandStack.pop();
    int32_t value = u4ToInt(stack1.data);
    int32_t shiftby = u4ToInt(stack2.data);
    DCOUT << "Value:" << value << endl;
    DCOUT << "Shiftby: " << shiftby << endl;    
    value >>= shiftby;
    stack1.data = value;
    frame->operandStack.push(stack1);
    DCOUT << "valor empilhado: " << value << endl;
  } else {
    frame->operandStack.push(stack2);
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void lshr (Frame * frame, JVM * jvm) {
  cout << "lshr" << endl;
  JvmValue stack3 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack2 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack1 = frame->operandStack.top();
  if (stack1.type == LONG && stack2.type == LONG && stack3.type == INT) {
    frame->operandStack.pop();
    int64_t value = u4ToLong(stack2.data, stack1.data);
    int32_t shiftby = u4ToInt(stack3.data);
    DCOUT << "Value:" << value << endl;
    DCOUT << "Shiftby: " << shiftby << endl;    
    value >>= shiftby;
    pair<u4, u4> result = longToU8(value);
    stack1.data = result.first;
    stack2.data = result.second;
    frame->operandStack.push(stack1);
    frame->operandStack.push(stack2);
    DCOUT << "valor empilhado: " << value << endl;
  } else {
    frame->operandStack.push(stack2);
    frame->operandStack.push(stack3);
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void iushr (Frame * frame, JVM * jvm) {
  cout << "iushr" << endl;
  JvmValue stack2 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack1 = frame->operandStack.top();
  if (stack1.type == INT && stack2.type == INT) {
    frame->operandStack.pop();
    DCOUT << "Value:" << stack1.data << endl;
    DCOUT << "Shiftby: " << stack2.data << endl;
    stack1.data >>= stack2.data;
    frame->operandStack.push(stack1);
    DCOUT << "valor empilhado: " << frame->operandStack.top().data << endl;
  } else {
    frame->operandStack.push(stack2);
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void lushr (Frame * frame, JVM * jvm) {
  cout << "lushr" << endl;
  JvmValue stack3 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack2 = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue stack1 = frame->operandStack.top();
  if (stack1.type == LONG && stack2.type == LONG && stack3.type == INT) {
    frame->operandStack.pop();
    u8 value = (stack1.data << 32) | stack2.data;
    DCOUT << "Value:" << value << endl;
    DCOUT << "Shiftby: " << stack3.data << endl;    
    value >>= stack3.data;
    stack1.data = (u4) value >> 32;
    stack2.data = (u4) value;
    frame->operandStack.push(stack1);
    frame->operandStack.push(stack2);
    DCOUT << "valor empilhado: " << value << endl;
  } else {
    frame->operandStack.push(stack2);
    frame->operandStack.push(stack3);
    DCOUT << "falha na operação" << endl;
  }  
  frame->pc += 1;
}

#pragma endregion

#pragma region and

void iand (Frame * frame, JVM * jvm) {
  DCOUT << "iand" << endl;
  operate(frame, AND, INT);
  frame->pc += 1;
}

void land (Frame * frame, JVM * jvm) {
  DCOUT << "land" << endl;
  operateW(frame, AND, LONG);
  frame->pc += 1;
}

#pragma endregion

#pragma region or

void ior (Frame * frame, JVM * jvm) {
  DCOUT << "ior" << endl;
  operate(frame, OR, INT);
  frame->pc += 1;
}

void lor (Frame * frame, JVM * jvm) {
  DCOUT << "lor" << endl;
  operateW(frame, OR, LONG);
  frame->pc += 1;
}

#pragma endregion

#pragma region xor

void ixor (Frame * frame, JVM * jvm) {
  DCOUT << "ixor" << endl;
  operate(frame, XOR, INT);
  frame->pc += 1;
}

void lxor (Frame * frame, JVM * jvm) {
  DCOUT << "lxor" << endl;
  operateW(frame, XOR, LONG);
  frame->pc += 1;
}

#pragma endregion

void iinc (Frame * frame, JVM * jvm) {
  u1 index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 _const = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  int32_t _const_signed = (int8_t) _const;
  DCOUT << "iinc " << u4ToInt(frame->localVariables[index].data) << " += " << _const_signed << endl;
  frame->localVariables[index].data += _const_signed;
  
  frame->pc += 3;
}

#pragma region conversions

void i2l (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  int32_t integer = u4ToInt(value.data);
  int64_t longInteger = integer;
  DCOUT << "i2l " << integer << " -> " << longInteger << endl;

  auto [low, high] = longToU8(longInteger);
  JvmValue highValue = {LONG, high};
  JvmValue lowValue = {LONG, low};

  frame->pushWideOperandStack(lowValue, highValue);
  
  frame->pc += 1;
}

void i2f (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = u4ToInt(value.data);
  float _float = integer;
  u4 floatBits = floatToU4(_float);
  DCOUT << "i2f " << integer << " -> " << _float << " (0x" << hex << floatBits << dec << ')' << endl;

  JvmValue new_value = {FLOAT, floatBits};
  frame->pushOperandStack(new_value);

  frame->pc += 1;
}

void i2d (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = u4ToInt(value.data);
  double _double = integer;
  auto [low, high] = doubleToU8(_double);
  DCOUT << "i2d " << integer << " -> " << _double << " (0x" << hex << high << low << dec << ")" << endl;

  JvmValue highValue = {DOUBLE, high};
  JvmValue lowValue = {DOUBLE, low};

  frame->pushWideOperandStack(lowValue, highValue);

  frame->pc += 1;
}

void l2i (Frame * frame, JVM * jvm) {
  auto [lowValue, highValue] = frame->popWideOperandStack();

  int64_t longInteger = u4ToLong(lowValue.data, highValue.data);
  int32_t integer = longInteger;
  DCOUT << "l2i " << longInteger << " -> " << integer << endl;

  JvmValue new_value = {INT, integer};
  frame->pushOperandStack(new_value);

  frame->pc += 1;
}

void l2f (Frame * frame, JVM * jvm) {
  auto [lowValue, highValue] = frame->popWideOperandStack();

  int64_t longInteger = u4ToLong(lowValue.data, highValue.data);
  float _float = longInteger;
  u4 floatBits = floatToU4(_float);
  DCOUT << "l2f " << longInteger << " -> " << _float << " (0x" << hex << floatBits << dec << ')' << endl;

  JvmValue value = {FLOAT, floatBits};
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void l2d (Frame * frame, JVM * jvm) {
  auto [lowValue, highValue] = frame->popWideOperandStack();

  int64_t longInteger = u4ToLong(lowValue.data, highValue.data);
  double _double = longInteger;
  auto [low, high] = doubleToU8(_double);
  DCOUT << "l2d " << longInteger << " -> " << _double << " (0x" << hex << high << low << dec << ")" << endl;

  JvmValue new_highValue = {DOUBLE, high};
  JvmValue new_lowValue = {DOUBLE, low};

  frame->pushWideOperandStack(new_lowValue, new_highValue);

  frame->pc += 1;
}

void f2i (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  float _float = u4ToFloat(value.data);
  int32_t integer = _float;
  DCOUT << "f2i " << ' ' << _float << " -> " << integer << endl;

  JvmValue new_value = {INT, intToU4(integer)};
  frame->pushOperandStack(new_value);

  frame->pc += 1;
}

void f2l (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  float _float = u4ToFloat(value.data);
  int64_t longInteger = _float;
  DCOUT << "f2l " << ' ' << _float << " -> " << longInteger << endl;

  auto [low, high] = longToU8(longInteger);
  JvmValue highValue = {LONG, high};
  JvmValue lowValue = {LONG, low};

  frame->pushWideOperandStack(lowValue, highValue);

  frame->pc += 1;
}

void f2d (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  float _float = u4ToFloat(value.data);
  double _double = _float;
  auto [low, high] = doubleToU8(_double);
  DCOUT << "f2d " << _float << " (0x" << hex << value.data << dec << ") -> " << _double << " (0x" << hex << high << low << dec << ")" << endl;

  JvmValue highValue = {DOUBLE, high};
  JvmValue lowValue = {DOUBLE, low};

  frame->pushWideOperandStack(lowValue, highValue);

  frame->pc += 1;
}

void d2i (Frame * frame, JVM * jvm) {
  auto [lowValue, highValue] = frame->popWideOperandStack();

  DCOUT << "d2i 0x" << hex << highValue.data << lowValue.data << dec << endl;
  double _double = u4ToDouble(lowValue.data, highValue.data);
  int32_t integer = _double;
  DCOUT << "d2i " << fixed << setprecision(10) << _double << " -> " << integer << endl;

  JvmValue new_value = {INT, intToU4(integer)};
  frame->pushOperandStack(new_value);

  frame->pc += 1;
}

void d2l (Frame * frame, JVM * jvm) {
  auto [lowValue, highValue] = frame->popWideOperandStack();

  double _double = u4ToDouble(lowValue.data, highValue.data);
  int64_t longInteger = _double;
  DCOUT << "d2l " << _double << " -> " << longInteger << endl;

  auto [low, high] = longToU8(longInteger);
  JvmValue new_highValue = {LONG, high};
  JvmValue new_lowValue = {LONG, low};

  frame->pushWideOperandStack(new_lowValue, new_highValue);

  frame->pc += 1;
}

void d2f (Frame * frame, JVM * jvm) {
  auto [lowValue, highValue] = frame->popWideOperandStack();

  double _double = u4ToDouble(lowValue.data, highValue.data);
  float _float = _double;
  u4 floatBits = floatToU4(_float);
  DCOUT << "d2f " << _double << " -> " << _float << " (0x" << hex << floatBits << dec << ')' << endl;

  JvmValue value = {FLOAT, floatBits};
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void i2b (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = u4ToInt(value.data);
  int8_t byte = integer; // truncate and sign extension to u4
  DCOUT << "i2b " << integer << " -> 0x" << hex << (int) byte << dec << endl;

  JvmValue new_value = {BYTE, (u4) byte};
  frame->pushOperandStack(new_value);

  frame->pc += 1;
}

void i2c (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = u4ToInt(value.data);
  uint16_t _char = integer; // truncate and zero extension to u4
  DCOUT << "i2c " << integer << " -> '" << (char) _char << "'" << endl;

  JvmValue new_value = {CHAR, (u4) _char};
  frame->pushOperandStack(new_value);

  frame->pc += 1;
}

void i2s (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = value.data;
  int16_t _short = integer; // truncate and sign extension to u4
  DCOUT << "i2s " << integer << " -> " << _short << endl;

  JvmValue new_value = {SHORT, (u4) _short};
  frame->pushOperandStack(new_value);

  frame->pc += 1;
}

#pragma endregion

#pragma region compares

void lcmp (Frame * frame, JVM * jvm) {
  DCOUT << "lcmp" << endl;
  frame->pc += 1;
}

void fcmpl (Frame * frame, JVM * jvm) {
  DCOUT << "fcmpl" << endl;
  frame->pc += 1;
}

void fcmpg (Frame * frame, JVM * jvm) {
  DCOUT << "fcmpg" << endl;
  frame->pc += 1;
}

void dcmpl (Frame * frame, JVM * jvm) {
  DCOUT << "dcmpl" << endl;
  frame->pc += 1;
}

void dcmpg (Frame * frame, JVM * jvm) {
  DCOUT << "dcmpg" << endl;
  frame->pc += 1;
}

#pragma endregion

#pragma region if

void branch (Frame * frame) {

  int16_t offset = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1] << 8 |
                   frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];
  frame->pc += offset;
}

void ifeq (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifeq " << u4ToInt(value.data) << " == " << 0 << endl;
  if (u4ToInt(value.data) == 0) branch(frame);
  else frame->pc += 3;
}

void ifne (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifne " << u4ToInt(value.data) << " != " << 0 << endl;
  if (u4ToInt(value.data) != 0) branch(frame);
  else frame->pc += 3;
}

void iflt (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "iflt " << u4ToInt(value.data) << " < " << 0 << endl;
  if (u4ToInt(value.data) < 0) branch(frame);
  else frame->pc += 3;
}

void ifge (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifge " << u4ToInt(value.data) << " >= " << 0 << endl;
  if (u4ToInt(value.data) >= 0) branch(frame);
  else frame->pc += 3;
}

void ifgt (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifgt " << u4ToInt(value.data) << " > " << 0 << endl;
  if (u4ToInt(value.data) > 0) branch(frame);
  else frame->pc += 3;
}

void ifle (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifle " << u4ToInt(value.data) << " <= " << 0 << endl;
  if (u4ToInt(value.data) <= 0) branch(frame);
  else frame->pc += 3;
}

void if_icmpeq (Frame * frame, JVM * jvm) {
  auto [second, first] = frame->popWideOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = u4ToInt(first.data), v2 = u4ToInt(second.data);
  DCOUT << "if_icmpeq " << v1 << " == " << v2 << endl;

  if (v1 == v2) branch(frame);
  else frame->pc += 3;
}

void if_icmpne (Frame * frame, JVM * jvm) {
  auto [second, first] = frame->popWideOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = u4ToInt(first.data), v2 = u4ToInt(second.data);
  DCOUT << "if_icmpne " << v1 << " != " << v2 << endl;

  if (v1 != v2) branch(frame);
  else frame->pc += 3;
}

void if_icmplt (Frame * frame, JVM * jvm) {
  auto [second, first] = frame->popWideOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = u4ToInt(first.data), v2 = u4ToInt(second.data);
  DCOUT << "if_icmplt " << v1 << " < " << v2 << endl;

  if (v1 < v2) branch(frame);
  else frame->pc += 3;
}

void if_icmpge (Frame * frame, JVM * jvm) {
  auto [second, first] = frame->popWideOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = u4ToInt(first.data), v2 = u4ToInt(second.data);
  DCOUT << "if_icmpge " << v1 << " >= " << v2 << endl;

  if (v1 >= v2) branch(frame);
  else frame->pc += 3;
}

void if_icmpgt (Frame * frame, JVM * jvm) {
  auto [second, first] = frame->popWideOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = u4ToInt(first.data), v2 = u4ToInt(second.data);
  DCOUT << "if_icmpgt " << v1 << " > " << v2 << endl;

  if (v1 > v2) branch(frame);
  else frame->pc += 3;
}

void if_icmple (Frame * frame, JVM * jvm) {
  auto [second, first] = frame->popWideOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = u4ToInt(first.data), v2 = u4ToInt(second.data);
  DCOUT << "if_icmple " << v1 << " <= " << v2 << endl;

  if (v1 <= v2) branch(frame);
  else frame->pc += 3;
}

void if_acmpeq (Frame * frame, JVM * jvm) {
  DCOUT << "if_acmpeq" << endl;
  frame->pc += 3;
}

void if_acmpne (Frame * frame, JVM * jvm) {
  DCOUT << "if_acmpne" << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region jump

void _goto (Frame * frame, JVM * jvm) {
  DCOUT << "goto" << endl;
  
  u1 start_pc = frame->pc;
  
  u1 first_brach_byte = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 second_brach_byte = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];

  u4 branchoffset = (first_brach_byte << 8) | second_brach_byte;

  // DCOUT << "branchoffset " <<  branchoffset << endl;
  DCOUT << "jumping to pc " << start_pc + branchoffset << endl;
  frame->pc += branchoffset;
}

void jsr (Frame * frame, JVM * jvm) {
  DCOUT << "jsr" << endl;
  frame->pc += 3;
}

void ret (Frame * frame, JVM * jvm) {
  DCOUT << "ret" << endl;
  frame->pc += 2;
}

#pragma endregion

#pragma region switch

//implementado pelo Piano 
void tableswitch (Frame * frame, JVM * jvm) {
  DCOUT << "tableswitch" << endl;


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
  JvmValue index = frame->popOperandStack();
  DCOUT << "table index = " << index.data << endl;
  DCOUT << "high bytes = " <<high_bytes << endl;

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
          DCOUT << "table index == " << i+1 << " pulando para o endereço " << frame->pc + bytes <<endl;
          frame->pc += bytes;
          break;
      }
      
      DCOUT << "\t\t" << i + 1 << ": " << jump_bytes << " (+" << bytes << ")" << endl;
  };

}

void lookupswitch (Frame * frame, JVM * jvm) {
  DCOUT << "lookupswitch" << endl;
  // FIXME: consertar os pulos
  frame->pc += 4;
  frame->pc += 4;
  frame->pc += 4;
  frame->pc += 4;
  frame->pc += 4;
}

#pragma endregion

#pragma region return

void returnValue(Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  jvm->returnValue(value);
}

void returnValueWide(Frame * frame, JVM * jvm) {
  auto [lowerValue, upperValue] = frame->popWideOperandStack();
  jvm->returnValueWide(lowerValue, upperValue);
}

void ireturn (Frame * frame, JVM * jvm) {
  DCOUT << "ireturn" << endl;
  returnValue(frame, jvm);
}

void lreturn (Frame * frame, JVM * jvm) {
  DCOUT << "lreturn" << endl;
  returnValueWide(frame, jvm);
}

void freturn (Frame * frame, JVM * jvm) {
  DCOUT << "freturn" << endl;
  returnValue(frame, jvm);
}

void dreturn (Frame * frame, JVM * jvm) {
  DCOUT << "dreturn" << endl;
  returnValueWide(frame, jvm);
}

void areturn (Frame * frame, JVM * jvm) {
  DCOUT << "areturn" << endl;
  frame->pc += 1;
}

void _return (Frame * frame, JVM * jvm) {
  DCOUT << "return" << endl;
  jvm->returnVoid();
}

#pragma endregion

#pragma region class_fields

void getstatic (Frame * frame, JVM * jvm) {
  DCOUT << "getstatic" << endl;

  u1 first_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 second_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];

  u2 index = (first_bytes << 8) | second_bytes;  

  //pegar o dentro do fieldref o class name

  DCOUT << index <<endl ;
  cp_info * field_ref = frame->methodAreaItem->getConstantPoolItem(index);
  DCOUT << field_ref->constant_type_union.Fieldref_info.class_index <<endl ;
  
  u1 class_index = field_ref->constant_type_union.Fieldref_info.class_index;


  //se o class name for <java/lang/System> pular o frame e continuar a vida
  if(frame->methodAreaItem->getUtf8(class_index) == "java/lang/System"){
    DCOUT << "é um getstatic para o System.class " << endl;
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

void putstatic (Frame * frame, JVM * jvm) {
  DCOUT << "putstatic" << endl;
  frame->pc += 3;
}

void getfield (Frame * frame, JVM * jvm) {
  DCOUT << "getfield" << endl;
  frame->pc += 3;
}

void putfield (Frame * frame, JVM * jvm) {
  DCOUT << "putfield" << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region invoke

void invokevirtual (Frame * frame, JVM * jvm) {
  DCOUT << "invokevirtual" << endl;

  u1 first_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 second_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];

  u2 index = (first_bytes << 8) | second_bytes;  

  cp_info * method_ref = frame->methodAreaItem->getConstantPoolItem(index);
  string className = frame->methodAreaItem->getUtf8(method_ref->constant_type_union.Methodref_info.class_index);
  string methodName = frame->methodAreaItem->getUtf8(method_ref->constant_type_union.Methodref_info.name_and_type_index);
  vector<string> argTypes = frame->methodAreaItem->getMethodArgTypes(method_ref->constant_type_union.Methodref_info.name_and_type_index);
  
  DCOUT << "methodName " << methodName << endl;

  if (className == "java/io/PrintStream") {
    javaPrintln(frame, argTypes);
  } else {
    throw std::runtime_error("invokevirtual not implemented for " + className + "." + methodName);
  }

  frame->pc += 3;
}

void invokespecial (Frame * frame, JVM * jvm) {
  DCOUT << "invokespecial" << endl;

  // Method_info * initMethod = methodAreaItem->getInitMethod();
  // Frame * initFrame = new Frame(initMethod, methodAreaItem);

  // MethodArea * methodArea = methodAreaItem->getMethodArea();
  // methodArea->invoke(*initFrame);

  frame->pc += 3;
}

void invokestatic (Frame * frame, JVM * jvm) {
  DCOUT << "invokestatic" << endl;
  // 1. fazer a checagem para ver se a classe ja foi carregada com base no nome
  //     1. foi? então acessa
  //     2. não foi? então carrega e depois acessa
  // 2. retira o metodo atual da pilha de frames e coloca o metodo do method_item criado na pilha 

  //pegar o index para o pool
  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];

  u2 index = (high_bytes << 8) | low_bytes;
  
  cp_info * method_ref = frame->methodAreaItem->getConstantPoolItem(index);

  //pegar nome da classe
  string static_class_name = frame->methodAreaItem->getUtf8(method_ref->constant_type_union.Methodref_info.class_index);
  
  //pegar nome do metodo
  string static_method_name = frame->methodAreaItem->getUtf8(method_ref->constant_type_union.Methodref_info.name_and_type_index); 

  // checar se a classe ja foi carregada na area de metodos, caso não existir, carregar
  
  MethodArea  * method_area_ref = frame->methodAreaItem->getMethodArea();

  MethodAreaItem * static_class_method_area_item = method_area_ref->getMethodAreaItem(static_class_name);

  Method_info * static_class_method =  static_class_method_area_item->getMethodByName(static_method_name);

  // com o method em maos, criar um frame e depois de readicionar o frame atual na pilha, adicionar o frame em questão...

  //fazer o invoke 
  // pular o pc desse frame
  // colocar esse frame devolta na pilha
  // colocar o novo frame estatico na pilha

  frame->pc += 3;
}

void invokeinterface (Frame * frame, JVM * jvm) {
  DCOUT << "invokeinterface" << endl;
  frame->pc += 5;
}

void invokedynamic (Frame * frame, JVM * jvm) {
  DCOUT << "invokedynamic" << endl;
  frame->pc += 5;
}

#pragma endregion

#pragma region new

void _new (Frame * frame, JVM * jvm) {
  DCOUT << "new" << endl;
  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  u4 index = (high_bytes << 8) | low_bytes;

  cp_info * classRef = frame->methodAreaItem->getConstantPoolItem(index);
  string classname = frame->methodAreaItem->getUtf8(classRef->constant_type_union.Class_info.name_index);

  DCOUT << classname << endl;

  MethodArea  * methodAreaRef = frame->methodAreaItem->getMethodArea();
  MethodAreaItem * classMethodAreaItem = methodAreaRef->getMethodAreaItem(classname);

  // iniciar fields com os valores default, acontecerá no init
  HeapItem * heapItem = new HeapItem(classMethodAreaItem);
  int heapIndex = jvm->pushHeapItem(heapItem);
  
  JvmValue value = {INT, intToU4(heapIndex)};
  frame->pushOperandStack(value); // Objectref será o índice da instância na heap
  DCOUT << "new " << classname << " -> " << heapIndex << endl;

  frame->pc += 3;
}

void newarray (Frame * frame, JVM * jvm) {
  DCOUT << "newarray" << endl;
  frame->pc += 2;
}

void anewarray (Frame * frame, JVM * jvm) {
  DCOUT << "anewarray" << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region common

void arraylength (Frame * frame, JVM * jvm) {
  DCOUT << "arraylength" << endl;
  frame->pc += 1;
}

void athrow (Frame * frame, JVM * jvm) {
  DCOUT << "athrow" << endl;
  notSupported();
  frame->pc += 1;
}

void checkcast (Frame * frame, JVM * jvm) {
  DCOUT << "checkcast" << endl;
  notSupported();
  frame->pc += 3;
}

void instanceof (Frame * frame, JVM * jvm) {
  DCOUT << "instanceof" << endl;
  notSupported();
  frame->pc += 3;
}

#pragma endregion

void monitorenter (Frame * frame, JVM * jvm) {
  DCOUT << "monitorenter" << endl;
  notSupported();
  frame->pc += 1;
}

void monitorexit (Frame * frame, JVM * jvm) {
  DCOUT << "monitorexit" << endl;
  notSupported();
  frame->pc += 1;
}

void wide (Frame * frame, JVM * jvm) {
  DCOUT << "wide" << endl;
  notSupported();
}

void multianewarray (Frame * frame, JVM * jvm) {
  DCOUT << "multianewarray" << endl;
  frame->pc += 4;
}

#pragma region ifnull

void ifnull (Frame * frame, JVM * jvm) {
  DCOUT << "ifnull" << endl;
  frame->pc += 3;
}

void ifnonnull (Frame * frame, JVM * jvm) {
  DCOUT << "ifnonnull" << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region jump_w

void goto_w (Frame * frame, JVM * jvm) {
  DCOUT << "goto_w" << endl;
  frame->pc += 5;
}

void jsr_w (Frame * frame, JVM * jvm) {
  DCOUT << "jsr_w" << endl;
  frame->pc += 5;
}

#pragma endregion

void breakpoint (Frame * frame, JVM * jvm) {
  DCOUT << "breakpoint" << endl;
  notSupported();
}

#pragma region impdep

void impdep1 (Frame * frame, JVM * jvm) {
  DCOUT << "impdep1" << endl;
  notSupported();
}

void impdep2 (Frame * frame, JVM * jvm) {
  DCOUT << "impdep2" << endl;
  notSupported();
}

#pragma endregion

void notSupported() {
  throw std::runtime_error("Instrução não suportada");
}

#pragma endregion
