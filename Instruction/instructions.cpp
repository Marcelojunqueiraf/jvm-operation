#include "instructions.hpp"
#include "../common/converters.hpp"

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

void iconst(u4 value, Frame * frame) {
  int32_t integer = u4ToInt(value);
  frame->pushOperandStack(JvmValue(INT, {.i = integer}));
}

void lconst(u4 value, Frame * frame) {
  long _long = u4ToLong(value, value);
  frame->pushOperandStack(JvmValue(INT, {.l = _long}));
}

void fconst(u4 value, Frame * frame) {
  float _float = u4ToFloat(value);
  frame->pushOperandStack(JvmValue(INT, {.f = _float}));
}

void dconst(u4 value, Frame * frame){
  double _double = u4ToDouble(value, value);
  frame->pushOperandStack(JvmValue(INT, {.d = _double}));
}

void load(u2 index, Frame * frame) {
  frame->pushOperandStack(frame->localVariables[index]);
}

void store(u2 index, Frame * frame) {
  JvmValue jvmValue = frame->popOperandStack();
  frame->localVariables[index] = jvmValue;
}

void javaPrintln(Frame * frame, vector<string> args) {
  string argType = args.size() == 0 ? "VOID" : args[0];

  DCOUT << "argType: " << argType << endl;

  if (argType == "INT")
  {
    // + "BYTE" jvm interpreta byte como int no print, não sei se em outros casos é assim
    // + "SHORT" jvm interpreta short como int no print, não sei se em outros casos é assim
    JvmValue value = frame->popOperandStack();
    int32_t integer = value.data.i;
    cout << integer << endl;
  }
  else if (argType == "FLOAT")
  {
    JvmValue value = frame->popOperandStack();
    float _float = value.data.f;
    cout << fixed << setprecision(7) << _float << endl;
  }
  else if (argType == "LONG")
  {
    JvmValue value = frame->popOperandStack();
    int64_t _long = value.data.l;
    cout << _long << endl;
  }
  else if (argType == "DOUBLE")
  {
    JvmValue value = frame->popOperandStack();
    double _double = value.data.d;
    cout << fixed << setprecision(15) << _double << endl;
  }
  else if (argType == JAVA_STRING_CLASSNAME)
  { // STRING
    JvmValue value = frame->popOperandStack();
    DCOUT << "ValueType: " << value.type << endl;
    DCOUT << "string: " << value.s << endl;

    if (value.type == REFERENCE) {
      cout << "null" << endl;
      return;
    }

    cout << value.s << endl;
  }
  else if (argType == "CHAR")
  {
    JvmValue value = frame->popOperandStack();
    char _char = value.data.u;
    cout << _char << endl;
  }
  else if (argType == "BOOL")
  {
    JvmValue value = frame->popOperandStack();
    bool _bool = value.data.u;
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

string getFieldName(Frame * frame, u2 index) {
  cp_info * fieldRef = frame->methodAreaItem->getConstantPoolItem(index);

  string classname = frame->methodAreaItem->getUtf8(fieldRef->constant_type_union.Fieldref_info.class_index);
  string fieldName = frame->methodAreaItem->getUtf8(fieldRef->constant_type_union.Fieldref_info.name_and_type_index);
  DCOUT << "field " << classname << "." << fieldName << endl;
  
  return fieldName;
}

pair<Frame *, vector<string>> createInvokedFrame(Frame * frame, u2 index, string methodName, string methodDescriptor) {
  cp_info * classRef = frame->methodAreaItem->getConstantPoolItem(index);
  string classname = frame->methodAreaItem->getUtf8(classRef->constant_type_union.Class_info.name_index);

  MethodArea  * methodAreaRef = frame->methodAreaItem->getMethodArea();
  MethodAreaItem * classMethodAreaItem = methodAreaRef->getMethodAreaItem(classname);
  Method_info * invokedMethod = classMethodAreaItem->getMethodByName(methodName, methodDescriptor);
  MethodAreaItem * invokedMethodAreaItem = classMethodAreaItem->getMethodItemByMethodName(methodName, methodDescriptor);

  // TODO: lidar com as exceções que a especificação diz que podem acontecer

  vector<string> argTypes = invokedMethodAreaItem->getMethodArgTypesByDescriptorIndex(invokedMethod->descriptor_index);
  // string returnType = argTypes.back(); caso precise, é assim que pega o tipo do retorno
  argTypes.pop_back(); // tira o tipo do retorno
  
  DCOUT << "method " << classname << '.' << methodName << ", nargs " << argTypes.size() << endl;
  for (string argType : argTypes) DCOUT << "argType " << argType << endl;

  Frame * invokedFrame = new Frame(invokedMethod, invokedMethodAreaItem);

  return {invokedFrame, argTypes};
}

void setInvokedLocalVars(Frame * actualFrame, Frame * invokedFrame, vector<string> args, bool isStatic = false) {
  int localVariableIndex = isStatic ? 0 : 1;
  reverse(args.begin(), args.end());

  vector<JvmValue> argsValues;

  for (string argType : args) {
    JvmValue value = actualFrame->popOperandStack();
    argsValues.push_back(value);

    DCOUT << "pop argType: " << argType << ' ' << value.type << endl;
  }

  reverse(argsValues.begin(), argsValues.end());

  for (JvmValue argsValue : argsValues) {
    invokedFrame->localVariables[localVariableIndex++] = argsValue;

    if (argsValue.type == LONG || argsValue.type == DOUBLE) localVariableIndex++;
  }
  if (!isStatic) invokedFrame->localVariables[0] = actualFrame->popOperandStack(); // Objectref
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

  frame->pushOperandStack({REFERENCE, 0});
  
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

  frame->pushOperandStack(JvmValue(INT, {.i = bytesSigned}));
  DCOUT << "valor empilhado: " << (int) bytesSigned << endl;
  frame->pc += 2;
}

void sipush (Frame * frame, JVM * jvm) {
  DCOUT << "sipush" << endl;
  u1 bytes1 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 bytes2 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  u2 bytes = (bytes1 << 8) | bytes2;
  int16_t bytesSigned = (int16_t) bytes;

  frame->pushOperandStack(JvmValue(INT, {.i = bytesSigned}));
  DCOUT << "valor empilhado: " << (int) bytesSigned << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region ldc

void ldcGeneric(Frame * frame, JVM * jvm, u2 id) {
  cp_info * c = frame->methodAreaItem->getConstantPoolItem(id);
  DCOUT << "tipo da constante: " << (int) c->tag << endl;
  JvmValue value;
  switch (c->tag) {
    case 3:
      DCOUT << "int" << endl;
      value.type = INT;
      value.data.i =  u4ToInt(c->constant_type_union.Integer.bytes);
      break;
    case 4:
      DCOUT << "float" << endl;
      value.type = FLOAT;
      value.data.f = u4ToFloat(c->constant_type_union.Float.bytes);
      break;
    case 8:
    {
      DCOUT << "string" << endl;
      value.type = STRING;
      string s = frame->methodAreaItem->getUtf8(c->constant_type_union.String.string_index);
      value.s = s;
      break;
    }
    case 6:
      DCOUT << "double" << endl;
      value.type = DOUBLE;
      value.data.d = u4ToDouble(c->constant_type_union.Double.low_bytes, c->constant_type_union.Double.high_bytes);
      break;
    case 5:
      DCOUT << "long" << endl;
      value.type = LONG;
      value.data.l = u4ToLong(c->constant_type_union.Long.low_bytes, c->constant_type_union.Long.high_bytes);
      break;
    default:
      throw std::runtime_error("tipo não reconhecido");
  }
  frame->pushOperandStack(value);

  if (value.type == STRING)
 {
    DCOUT << "valor empilhado: " << value.s << endl;
  }
  else {
    DCOUT << "valor empilhado: " << value.data.i << endl;
  }
}

void ldc (Frame * frame, JVM * jvm) {
  DCOUT << "ldc" << endl;
  u1 id = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  ldcGeneric(frame, jvm, id);
  frame->pc += 2;
}

void ldc_w (Frame * frame, JVM * jvm) {
  DCOUT << "ldc_w" << endl;

  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];
  u2 id = (high_bytes << 8) | low_bytes;

  ldcGeneric(frame, jvm, id);

  frame->pc += 3;
}

void ldc2_w (Frame * frame, JVM * jvm) {
  DCOUT << "ldc2_w" << endl;

  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];
  u2 id = (high_bytes << 8) | low_bytes;
  
  ldcGeneric(frame, jvm, id);

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
  load(index, frame);
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
  load(immediate, frame);
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
  DCOUT << "topo da pilha é " << frame->operandStack.top().data.i << endl;
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
  load(0, frame);
  frame->pc += 1;
}

void lload_1 (Frame * frame, JVM * jvm) {
  DCOUT << "lload_1" << endl;
  load(1, frame);
  frame->pc += 1;
}

void lload_2 (Frame * frame, JVM * jvm) {
  DCOUT << "lload_2" << endl;
  load(2, frame);
  frame->pc += 1;
}

void lload_3 (Frame * frame, JVM * jvm) {
  DCOUT << "lload_3" << endl;
  load(3, frame);
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
  load(0, frame);
  frame->pc += 1;
}

void dload_1 (Frame * frame, JVM * jvm) {
  DCOUT << "dload_1" << endl;
  load(1, frame);
  frame->pc += 1;
}

void dload_2 (Frame * frame, JVM * jvm) {
  DCOUT << "dload_2" << endl;
  load(2, frame);
  frame->pc += 1;
}

void dload_3 (Frame * frame, JVM * jvm) {
  DCOUT << "dload_3" << endl;
  load(3, frame);
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

void loadFromArray(Frame * frame, JVM * jvm) {
  int32_t index = frame->popOperandStack().data.i;
  int32_t arrayref = frame->popOperandStack().data.i;
  DCOUT << "loadFrom " << arrayref << " " << index << endl;
  JvmValue value = jvm->getArrayValue(arrayref, index);

  frame->pushOperandStack(value);
}

void iaload (Frame * frame, JVM * jvm) {
  DCOUT << "iaload" << endl;
  loadFromArray(frame, jvm);
  DCOUT << frame->operandStack.top().data.i << endl;
  frame->pc += 1;
}

void laload (Frame * frame, JVM * jvm) {
  DCOUT << "laload" << endl;
  frame->pc += 1;
}

void faload (Frame * frame, JVM * jvm) {
  DCOUT << "faload" << endl;
  loadFromArray(frame, jvm);
  frame->pc += 1;
}

void daload (Frame * frame, JVM * jvm) {
  DCOUT << "daload" << endl;
  frame->pc += 1;
}

void aaload (Frame * frame, JVM * jvm) {
  DCOUT << "aaload" << endl;
  loadFromArray(frame, jvm);
  frame->pc += 1;
}

void baload (Frame * frame, JVM * jvm) {
  DCOUT << "baload" << endl;
  loadFromArray(frame, jvm);
  frame->pc += 1;
}

void caload (Frame * frame, JVM * jvm) {
  DCOUT << "caload" << endl;
  loadFromArray(frame, jvm);
  frame->pc += 1;
}

void saload (Frame * frame, JVM * jvm) {
  DCOUT << "saload" << endl;
  loadFromArray(frame, jvm);
  frame->pc += 1;
}

#pragma endregion

#pragma region store

void istore (Frame * frame, JVM * jvm) {
  DCOUT << "istore" << endl;
  
  u1 local_vector_index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  
  store(local_vector_index, frame);

  frame->pc += 2;
}

void lstore (Frame * frame, JVM * jvm) {
  DCOUT << "lstore" << endl;

  u1 local_vector_index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];

  store(local_vector_index, frame);

  frame->pc += 2;
}

void fstore (Frame * frame, JVM * jvm) {
  DCOUT << "fstore" << endl;

  u1 local_vector_index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];

  store(local_vector_index, frame);

  frame->pc += 2;
}

void dstore (Frame * frame, JVM * jvm) {
  DCOUT << "dstore" << endl;

  u1 local_vector_index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];

  store(local_vector_index, frame);

  frame->pc += 2;
}

void astore (Frame * frame, JVM * jvm) {
  DCOUT << "astore" << endl;
  u1 index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];

  store(index, frame);

  frame->pc += 2;
}

void istore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "istore_0" << endl;

  store(0, frame);

  frame->pc += 1;
}

void istore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "istore_1" << endl;

  store(1, frame);

  frame->pc += 1;
  DCOUT << "vetor de variaveis de indice = 1 " << frame->localVariables[1].data.i << endl;  
}

void istore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "istore_2" << endl;
  
  store(2, frame);
  
  frame->pc += 1;
}

void istore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "istore_3" << endl;
  store(3, frame);
  frame->pc += 1;
}

void lstore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "lstore_0" << endl;

  store(0, frame);

  frame->pc += 1;
}

void lstore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "lstore_1" << endl;

  store(1, frame);

  frame->pc += 1;
}

void lstore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "lstore_2" << endl;

  store(2, frame);

  frame->pc += 1;
}

void lstore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "lstore_3" << endl;

  store(3, frame);

  frame->pc += 1;
}

void fstore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "fstore_0" << endl;

  store(0, frame);

  frame->pc += 1;
}

void fstore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "fstore_1" << endl;

  store(1, frame);

  frame->pc += 1;
}

void fstore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "fstore_2" << endl;

  store(2, frame);

  frame->pc += 1;
}

void fstore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "fstore_3" << endl;

  store(3, frame);

  frame->pc += 1;
}

void dstore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "dstore_0" << endl;

  store(0, frame);

  frame->pc += 1;
}

void dstore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "dstore_1" << endl;

  store(1, frame);

  frame->pc += 1;
}

void dstore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "dstore_2" << endl;

  store(2, frame);

  frame->pc += 1;
}

void dstore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "dstore_3" << endl;

  store(3, frame);

  frame->pc += 1;
}

void astore_0 (Frame * frame, JVM * jvm) {
  DCOUT << "astore_0" << endl;
  store(0, frame);
  frame->pc += 1;
}

void astore_1 (Frame * frame, JVM * jvm) {
  DCOUT << "astore_1" << endl;
  store(1, frame);
  frame->pc += 1;
}

void astore_2 (Frame * frame, JVM * jvm) {
  DCOUT << "astore_2" << endl;
  store(2, frame);
  frame->pc += 1;
}

void astore_3 (Frame * frame, JVM * jvm) {
  DCOUT << "astore_3" << endl;
  store(3, frame);
  frame->pc += 1;
}


void storeOnArray(Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  int32_t index = frame->popOperandStack().data.i;
  int32_t arrayref = frame->popOperandStack().data.i;

  jvm->setArrayValue(arrayref, index, value);
}

void iastore (Frame * frame, JVM * jvm) {
  DCOUT << "iastore" << endl;
  storeOnArray(frame, jvm);
  frame->pc += 1;
}

void lastore (Frame * frame, JVM * jvm) {
  DCOUT << "lastore" << endl;
  storeOnArray(frame, jvm);
  frame->pc += 1;
}

void fastore (Frame * frame, JVM * jvm) {
  DCOUT << "fastore" << endl;
  storeOnArray(frame, jvm);
  frame->pc += 1;
}

void dastore (Frame * frame, JVM * jvm) {
  DCOUT << "dastore" << endl;
  storeOnArray(frame, jvm);
  frame->pc += 1;
}

void aastore (Frame * frame, JVM * jvm) {
  DCOUT << "aastore" << endl;
  storeOnArray(frame, jvm);
  frame->pc += 1;
}

void bastore (Frame * frame, JVM * jvm) {
  DCOUT << "bastore" << endl;
  storeOnArray(frame, jvm);
  frame->pc += 1;
}

void castore (Frame * frame, JVM * jvm) {
  DCOUT << "castore" << endl;
  storeOnArray(frame, jvm);
  frame->pc += 1;
}

void sastore (Frame * frame, JVM * jvm) {
  DCOUT << "sastore" << endl;
  storeOnArray(frame, jvm);
  frame->pc += 1;
}

#pragma endregion

#pragma region pop

void pop (Frame * frame, JVM * jvm) {
  DCOUT << "pop" << endl;
  frame->popOperandStack();
  frame->pc += 1;
}

void pop2 (Frame * frame, JVM * jvm) {
  DCOUT << "pop2" << endl;
  frame->popOperandStack();
  // talvez tenha que fazer isso aqui, não sei
  // if (value.type == LONG || value.type == DOUBLE)
  //   frame->popOperandStack();

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


void operate(Frame * frame, Operation op, JVMType type) {
  JvmValue second = frame->popOperandStack();
  JvmValue first = frame->popOperandStack();

  JvmValue resultValue;
  resultValue.type = type;
  switch (type) {
    case INT:
    {
      int32_t calc = calculate<int32_t>(first.data.i, second.data.i, op);
      resultValue.data.i = calc;
      DCOUT << "int result: " << calc << endl;
      break;
    }
    case FLOAT:
    {
      float calc = calculate<float>(first.data.f, second.data.f, op);
      resultValue.data.f = calc;
      DCOUT << "float result: " << calc << endl;
      break;
    }
    case LONG:
    {
      int64_t calc = calculate<int64_t>(first.data.l, second.data.l, op);
      resultValue.data.l = calc;
      DCOUT << "long result:" << calc << endl;
      break;
    }
    case DOUBLE:
    {
      double calc = calculate<double>(first.data.d, second.data.d, op);
      resultValue.data.d = calc;
      DCOUT << "double result:" << calc << endl;
      break;
    }
    default:
      throw std::runtime_error("tipo nao implementado");
  }

  frame->pushOperandStack(resultValue);
}


#pragma region add

void iadd (Frame * frame, JVM * jvm) {
  DCOUT << "iadd" << endl;
  operate(frame, ADD, INT);
  frame->pc += 1;
}

void ladd (Frame * frame, JVM * jvm) {
  DCOUT << "ladd" << endl;
  operate(frame, ADD, LONG);
  frame->pc += 1;
}

void fadd (Frame * frame, JVM * jvm) {
  DCOUT << "fadd" << endl;
  operate(frame, ADD, FLOAT);
  frame->pc += 1;
}

void dadd (Frame * frame, JVM * jvm) {
  DCOUT << "dadd" << endl;
  operate(frame, ADD, DOUBLE);
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
  operate(frame, SUB, LONG);
  frame->pc += 1;
}

void fsub (Frame * frame, JVM * jvm) {
  DCOUT << "fsub" << endl;
  operate(frame, SUB, FLOAT);
  frame->pc += 1;
}

void dsub (Frame * frame, JVM * jvm) {
  DCOUT << "dsub" << endl;
  operate(frame, SUB, DOUBLE);
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
  operate(frame, MUL, LONG);
  frame->pc += 1;
}

void fmul (Frame * frame, JVM * jvm) {
  DCOUT << "fmul" << endl;
  operate(frame, MUL, FLOAT);
  frame->pc += 1;
}

void dmul (Frame * frame, JVM * jvm) {
  DCOUT << "dmul" << endl;
  operate(frame, MUL, DOUBLE);
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
  operate(frame, DIV, LONG);
  frame->pc += 1;
}

void fdiv (Frame * frame, JVM * jvm) {
  DCOUT << "fdiv" << endl;
  operate(frame, DIV, FLOAT);
  frame->pc += 1;
}

void ddiv (Frame * frame, JVM * jvm) {
  DCOUT << "ddiv" << endl;
  operate(frame, DIV, DOUBLE);
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
  DCOUT << "ineg" << endl;
  JvmValue value = frame->operandStack.top();
  if (value.type == INT) {
    frame->operandStack.pop();
    int32_t neg = u4ToInt(value.data.u);
    neg *= -1;
    value.data.i = neg;
    frame->operandStack.push(value);
    DCOUT << "valor empilhado: " << neg << endl;
  } else {
    DCOUT << "falha na operação" << endl;
  }
  frame->pc += 1;
}

void lneg (Frame * frame, JVM * jvm) {
  DCOUT << "lneg" << endl;
  JvmValue value = frame->operandStack.top();

  frame->operandStack.pop();
  int64_t neg = value.data.l;
  neg *= -1;
  value.data.l = neg;
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << neg << endl;
  
  frame->pc += 1;
}

void fneg (Frame * frame, JVM * jvm) {
  DCOUT << "fneg" << endl;
  JvmValue value = frame->operandStack.top();

  frame->operandStack.pop();
  float neg = value.data.f;
  neg *= -1;
  value.data.f = neg;
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << neg << endl;
  
  frame->pc += 1;
}

void dneg (Frame * frame, JVM * jvm) {
  DCOUT << "dneg" << endl;
  JvmValue value = frame->operandStack.top();

  frame->operandStack.pop();
  double neg = value.data.d;
  neg *= -1;
  value.data.d = neg;
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << neg << endl;

  frame->pc += 1;
}

#pragma endregion

#pragma region shift

void ishl (Frame * frame, JVM * jvm) {
  DCOUT << "ishl" << endl;
  JvmValue shift = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value = frame->operandStack.top();
  frame->operandStack.pop();


  DCOUT << "Valor: " << value.data.i << " shift para a esquerda de: " << shift.data.i << endl;
  value.data.i <<= shift.data.i;
  
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << value.data.i << endl;

  frame->pc += 1;
}

void lshl (Frame * frame, JVM * jvm) {
  DCOUT << "lshl" << endl;
  JvmValue shift = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value = frame->operandStack.top();
  frame->operandStack.pop();


  DCOUT << "Valor: " << value.data.l << " shift para a esquerda de: " << shift.data.i << endl;
  value.data.l <<= shift.data.i;
  
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << value.data.l << endl;
  frame->pc += 1;
}

void ishr (Frame * frame, JVM * jvm) {
  DCOUT << "ishr" << endl;
  JvmValue shift = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value = frame->operandStack.top();
  frame->operandStack.pop();


  DCOUT << "Valor: " << value.data.i << " shift para a direita de: " << shift.data.i << endl;
  value.data.i >>= shift.data.i;
  
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << value.data.i << endl;

  frame->pc += 1;
}

void lshr (Frame * frame, JVM * jvm) {
  DCOUT << "lshr" << endl;
  JvmValue shift = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value = frame->operandStack.top();
  frame->operandStack.pop();


  DCOUT << "Valor: " << value.data.l << " shift para a direita de: " << shift.data.i << endl;
  value.data.l >>= shift.data.i;
  
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << value.data.l << endl;
  frame->pc += 1;
}

void iushr (Frame * frame, JVM * jvm) {
  DCOUT << "iushr" << endl;
  JvmValue shift = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value = frame->operandStack.top();
  frame->operandStack.pop();


  DCOUT << "Valor: " << value.data.i << " shift logico para a direita de: " << shift.data.i << endl;
  // TODO: aplicar lógica de (value1 >> s) + (2L << ~s) se for negativo
  value.data.i >>= shift.data.i;
  
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << value.data.i << endl;
  frame->pc += 1;
}

void lushr (Frame * frame, JVM * jvm) {
  DCOUT << "lushr" << endl;
  JvmValue shift = frame->operandStack.top();
  frame->operandStack.pop();
  JvmValue value = frame->operandStack.top();
  frame->operandStack.pop();
  
  // TODO: aplicar lógica de (value1 >> s) + (2L << ~s) se for negativo
  DCOUT << "Valor: " << value.data.l << " shift para a direita de: " << shift.data.i << endl;
  value.data.l >>= shift.data.i;
  
  frame->operandStack.push(value);
  DCOUT << "valor empilhado: " << value.data.l << endl;
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
  operate(frame, AND, LONG);
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
  operate(frame, OR, LONG);
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
  operate(frame, XOR, LONG);
  frame->pc += 1;
}

#pragma endregion

void iinc (Frame * frame, JVM * jvm) {
  u1 index = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 _const = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];

  int32_t _const_signed = (int8_t) _const;
  DCOUT << "iinc " << frame->localVariables[index].data.i << " += " << _const_signed << endl;
  frame->localVariables[index].data.i += _const_signed;
  
  frame->pc += 3;
}

#pragma region conversions

void i2l (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  int32_t integer = value.data.i;
  int64_t longInteger = integer;
  DCOUT << "i2l " << integer << " -> " << longInteger << endl;

  value.type = LONG;
  value.data.l = longInteger;
  frame->pushOperandStack(value);
  
  frame->pc += 1;
}

void i2f (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = value.data.i;
  float _float = integer;
  DCOUT << "i2f " << integer << " -> " << _float << endl;

  value.type = FLOAT;
  value.data.f = _float;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void i2d (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = value.data.i;
  double _double = integer;
  DCOUT << "i2d " << integer << " -> " << _double << endl;

  value.type = DOUBLE;
  value.data.d = _double;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void l2i (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int64_t longInteger = value.data.l;
  int32_t integer = longInteger;
  DCOUT << "l2i " << longInteger << " -> " << integer << endl;

  value.type = INT;
  value.data.i = integer;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void l2f (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int64_t longInteger = value.data.l;
  float _float = longInteger;
  DCOUT << "l2f " << longInteger << " -> " << _float << endl;

  value.type = FLOAT;
  value.data.f = _float;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void l2d (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int64_t longInteger = value.data.l;
  double _double = longInteger;
  DCOUT << "l2d " << longInteger << " -> " << _double << endl;

  value.type = DOUBLE;
  value.data.d = _double;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void f2i (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  float _float = value.data.f;
  int32_t integer = _float;
  DCOUT << "f2i " << ' ' << _float << " -> " << integer << endl;

  value.type = INT;
  value.data.i = integer;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void f2l (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  float _float = value.data.f;
  int64_t longInteger = _float;
  DCOUT << "f2l " << ' ' << _float << " -> " << longInteger << endl;

  value.type = LONG;
  value.data.l = longInteger;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void f2d (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  float _float = value.data.f;
  double _double = _float;
  DCOUT << "f2d " << _float << " (0x" << hex << value.data.f << dec << ") -> " << _double << " (0x" << hex << _double << dec << ")" << endl;

  value.type = DOUBLE;
  value.data.d = _double;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void d2i (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  double _double = value.data.d;
  int32_t integer = _double;
  DCOUT << "d2i " << fixed << setprecision(10) << _double << " -> " << integer << endl;

  value.type = INT;
  value.data.i = integer;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void d2l (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  double _double = value.data.d;
  int64_t longInteger = _double;
  DCOUT << "d2l " << _double << " -> " << longInteger << endl;

  value.type = LONG;
  value.data.l = longInteger;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void d2f (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  double _double = value.data.d;
  float _float = _double;
  DCOUT << "d2f " << _double << " -> " << _float << endl;

  value.type = FLOAT;
  value.data.f = _float;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void i2b (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = value.data.i;
  int8_t byte = integer; // truncate and sign extension to u4
  DCOUT << "i2b " << integer << " -> 0x" << hex << (int) byte << dec << endl;

  value.type = BYTE;
  value.data.i = byte;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void i2c (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = value.data.i;
  uint16_t _char = integer; // truncate and zero extension to u4
  DCOUT << "i2c " << integer << " -> '" << (char) _char << "'" << endl;

  value.type = CHAR;
  value.data.u = _char;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

void i2s (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();

  int32_t integer = value.data.i;
  int16_t _short = integer; // truncate and sign extension to u4
  DCOUT << "i2s " << integer << " -> " << _short << endl;

  value.type = SHORT;
  value.data.i = _short;
  frame->pushOperandStack(value);

  frame->pc += 1;
}

#pragma endregion

#pragma region compares

void lcmp (Frame * frame, JVM * jvm) {
  DCOUT << "lcmp" << endl;
  JvmValue first = frame->popOperandStack();
  JvmValue second = frame->popOperandStack();

  if (first.data.l > second.data.l) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 1}));
  } else if (first.data.l == second.data.l) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 0}));
  } else {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = -1}));
  }
  frame->pc += 1;
}

void fcmpl (Frame * frame, JVM * jvm) {
  DCOUT << "fcmpl" << endl;
  JvmValue first = frame->popOperandStack();
  JvmValue second = frame->popOperandStack();

  if(isnan(first.data.f) || isnan(second.data.f)) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = -1}));
  } else if (first.data.f > second.data.f) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 1}));
  } else if (first.data.f == second.data.f) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 0}));
  } else {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = -1}));
  } 

  frame->pc += 1;
}

void fcmpg (Frame * frame, JVM * jvm) {
  DCOUT << "fcmpg" << endl;
  JvmValue first = frame->popOperandStack();
  JvmValue second = frame->popOperandStack();

  if(isnan(first.data.f) || isnan(second.data.f)) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 1}));
  } else if (first.data.f > second.data.f) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 1}));
  } else if (first.data.f == second.data.f) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 0}));
  } else {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = -1}));
  }
}

void dcmpl (Frame * frame, JVM * jvm) {
  DCOUT << "dcmpl" << endl;
  JvmValue first = frame->popOperandStack();
  JvmValue second = frame->popOperandStack();

  if(isnan(first.data.d) || isnan(second.data.d)) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = -1}));
  } else if (first.data.d > second.data.d) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 1}));
  } else if (first.data.d == second.data.d) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 0}));
  } else {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = -1}));
  } 

  frame->pc += 1;
}

void dcmpg (Frame * frame, JVM * jvm) {
  DCOUT << "dcmpg" << endl;
  JvmValue first = frame->popOperandStack();
  JvmValue second = frame->popOperandStack();

  if(isnan(first.data.d) || isnan(second.data.d)) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 1}));
  } else if (first.data.d > second.data.d) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 1}));
  } else if (first.data.d == second.data.d) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 0}));
  } else {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = -1}));
  } 

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
  
  DCOUT << "ifeq " << value.data.i << " == " << 0 << endl;
  if (value.data.i == 0) branch(frame);
  else frame->pc += 3;
}

void ifne (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifne " << value.data.i << " != " << 0 << endl;
  if (value.data.i != 0) branch(frame);
  else frame->pc += 3;
}

void iflt (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "iflt " << value.data.i << " < " << 0 << endl;
  if (value.data.i < 0) branch(frame);
  else frame->pc += 3;
}

void ifge (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifge " << value.data.i << " >= " << 0 << endl;
  if (value.data.i >= 0) branch(frame);
  else frame->pc += 3;
}

void ifgt (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifgt " << value.data.i << " > " << 0 << endl;
  if (value.data.i > 0) branch(frame);
  else frame->pc += 3;
}

void ifle (Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  
  if (value.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }
  
  DCOUT << "ifle " << value.data.i << " <= " << 0 << endl;
  if (value.data.i <= 0) branch(frame);
  else frame->pc += 3;
}

void if_icmpeq (Frame * frame, JVM * jvm) {
  JvmValue second = frame->popOperandStack();
  JvmValue first = frame->popOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = first.data.i, v2 = second.data.i;
  DCOUT << "if_icmpeq " << v1 << " == " << v2 << endl;

  if (v1 == v2) branch(frame);
  else frame->pc += 3;
}

void if_icmpne (Frame * frame, JVM * jvm) {
  JvmValue second = frame->popOperandStack();
  JvmValue first = frame->popOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = first.data.i, v2 = second.data.i;
  DCOUT << "if_icmpne " << v1 << " != " << v2 << endl;

  if (v1 != v2) branch(frame);
  else frame->pc += 3;
}

void if_icmplt (Frame * frame, JVM * jvm) {
  JvmValue second = frame->popOperandStack();
  JvmValue first = frame->popOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = first.data.i, v2 = second.data.i;
  DCOUT << "if_icmplt " << v1 << " < " << v2 << endl;

  if (v1 < v2) branch(frame);
  else frame->pc += 3;
}

void if_icmpge (Frame * frame, JVM * jvm) {
  JvmValue second = frame->popOperandStack();
  JvmValue first = frame->popOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = first.data.i, v2 = second.data.i;
  DCOUT << "if_icmpge " << v1 << " >= " << v2 << endl;

  if (v1 >= v2) branch(frame);
  else frame->pc += 3;
}

void if_icmpgt (Frame * frame, JVM * jvm) {
  JvmValue second = frame->popOperandStack();
  JvmValue first = frame->popOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = first.data.i, v2 = second.data.i;
  DCOUT << "if_icmpgt " << v1 << " > " << v2 << endl;

  if (v1 > v2) branch(frame);
  else frame->pc += 3;
}

void if_icmple (Frame * frame, JVM * jvm) {
  JvmValue second = frame->popOperandStack();
  JvmValue first = frame->popOperandStack();

  if (first.type != INT || second.type != INT) {
    throw std::runtime_error("operand is not an integer");
  }

  int32_t v1 = first.data.i, v2 = second.data.i;
  DCOUT << "if_icmple " << v1 << " <= " << v2 << endl;

  if (v1 <= v2) branch(frame);
  else frame->pc += 3;
}

void if_acmpeq (Frame * frame, JVM * jvm) {
  DCOUT << "if_acmpeq" << endl;
  JvmValue value1 = frame->popOperandStack();
  JvmValue value2 = frame->popOperandStack();

  if (value1.data.i == value2.data.i) branch(frame);
  else frame->pc += 3;
}

void if_acmpne (Frame * frame, JVM * jvm) {
  DCOUT << "if_acmpne" << endl;
  JvmValue value1 = frame->popOperandStack();
  JvmValue value2 = frame->popOperandStack();
  
  if (value1.data.i != value2.data.i) branch(frame);
  else frame->pc += 3;
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
  u1 branchbyte1 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 branchbyte2 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];
  int16_t jump = (int16_t) (branchbyte1 << 8) | branchbyte2;
  JvmValue returnAddress = JvmValue(RETURNADDRESS, DataUnion {.u = frame->pc + (u4)3 });
  frame->operandStack.push(returnAddress);
  frame->pc += jump;
}

void ret (Frame * frame, JVM * jvm) {
  DCOUT << "ret" << endl;
  u1 localIndex = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  JvmValue ret = frame->localVariables[localIndex];
  frame->pc = ret.data.u;
}

#pragma endregion

#pragma region switch

//implementado pelo Piano 
void tableswitch (Frame * frame, JVM * jvm) {
  DCOUT << "tableswitch" << endl;

  u1* code_arr = frame->method_info->attributes->attribute_info_union.code_attribute.code;
  JvmValue index = frame->popOperandStack();

  int32_t aux_pc = frame->pc;
  int32_t padding = 4 - (aux_pc + 1) % 4;
  if (padding == 4) padding = 0;
  aux_pc += padding;

  // carregando bytes
  int32_t defaultbytes = code_arr[aux_pc+1] << 24 | code_arr[aux_pc+2] << 16 | code_arr[aux_pc+3] << 8 | code_arr[aux_pc+4];
  aux_pc += 4;
  int32_t lowbytes = code_arr[aux_pc+1] << 24 | code_arr[aux_pc+2] << 16 | code_arr[aux_pc+3] << 8 | code_arr[aux_pc+4];
  aux_pc += 4;
  int32_t highbytes = code_arr[aux_pc+1] << 24 | code_arr[aux_pc+2] << 16 | code_arr[aux_pc+3] << 8 | code_arr[aux_pc+4];
  aux_pc += 4;

  DCOUT << "table index: " << index.data.i << endl;
  DCOUT << "defaultbytes: " << defaultbytes << endl;
  DCOUT << "lowbytes: " << lowbytes << endl;
  DCOUT << "highbytes: " << highbytes << endl;

  if (index.data.i < lowbytes || index.data.i > highbytes) {
    DCOUT << "index " << index.data.i << " fora do range, pulando para o endereço " << frame->pc + defaultbytes << endl;
    frame->pc += defaultbytes;
    return;
  }

  // int32_t nOffsets = highbytes - lowbytes + 1;
  for (int32_t i = lowbytes; i <= highbytes; i++) {
    int32_t offset = code_arr[aux_pc+1] << 24 | code_arr[aux_pc+2] << 16 | code_arr[aux_pc+3] << 8 | code_arr[aux_pc+4];
    aux_pc += 4;

    DCOUT << "\t" << i << ": " << frame->pc + offset << " (+" << offset << ")" << endl;
    if (index.data.i == i) {
      DCOUT << "index == " << i << " pulando para o endereço " << frame->pc + offset <<endl;
      frame->pc += offset;
      return;
    }
  };
}

void lookupswitch (Frame * frame, JVM * jvm) {
  DCOUT << "lookupswitch" << endl;
  
  u1* code_arr = frame->method_info->attributes->attribute_info_union.code_attribute.code;
  JvmValue key = frame->popOperandStack();

  int32_t aux_pc = frame->pc;
  int32_t padding = 4 - (aux_pc + 1) % 4;
  if (padding == 4) padding = 0;
  aux_pc += padding;
  
  int32_t defaultbytes = code_arr[aux_pc+1] << 24 | code_arr[aux_pc+2] << 16 | code_arr[aux_pc+3] << 8 | code_arr[aux_pc+4];
  aux_pc += 4;
  int32_t npairs = code_arr[aux_pc+1] << 24 | code_arr[aux_pc+2] << 16 | code_arr[aux_pc+3] << 8 | code_arr[aux_pc+4];
  aux_pc += 4;

  DCOUT << "key: " << key.data.i << endl;
  DCOUT << "defaultbytes: " << defaultbytes << endl;
  DCOUT << "npairs: " << npairs << endl;

  for (int32_t i = 0; i < npairs; i++) {
    int32_t match = code_arr[aux_pc+1] << 24 | code_arr[aux_pc+2] << 16 | code_arr[aux_pc+3] << 8 | code_arr[aux_pc+4];
    aux_pc += 4;
    int32_t offset = code_arr[aux_pc+1] << 24 | code_arr[aux_pc+2] << 16 | code_arr[aux_pc+3] << 8 | code_arr[aux_pc+4];
    aux_pc += 4;

    DCOUT << "\t" << match << ": " << frame->pc + offset << " (+" << offset << ")" << endl;
    if (key.data.i == match) {
      DCOUT << "key == " << match << " pulando para o endereço " << frame->pc + offset <<endl;
      frame->pc += offset;
      return;
    }
  };

  DCOUT << "key " << key.data.i << " não encontrada, pulando para o endereço " << frame->pc + defaultbytes << endl;
  frame->pc += defaultbytes;
}

#pragma endregion

#pragma region return

void returnValue(Frame * frame, JVM * jvm) {
  JvmValue value = frame->popOperandStack();
  jvm->returnValue(value);
}

void ireturn (Frame * frame, JVM * jvm) {
  DCOUT << "ireturn" << endl;
  returnValue(frame, jvm);
}

void lreturn (Frame * frame, JVM * jvm) {
  DCOUT << "lreturn" << endl;
  returnValue(frame, jvm);
}

void freturn (Frame * frame, JVM * jvm) {
  DCOUT << "freturn" << endl;
  returnValue(frame, jvm);
}

void dreturn (Frame * frame, JVM * jvm) {
  DCOUT << "dreturn" << endl;
  returnValue(frame, jvm);
}

void areturn (Frame * frame, JVM * jvm) {
  DCOUT << "areturn" << endl;
  returnValue(frame, jvm);
}

void _return (Frame * frame, JVM * jvm) {
  DCOUT << "return" << endl;
  jvm->returnVoid();
}

#pragma endregion

#pragma region class_fields

void getstatic (Frame * frame, JVM * jvm) {
  DCOUT << "getstatic" << endl;
  u1 firstBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 secondBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  u2 index = (firstBytes << 8) | secondBytes;  

  cp_info * fieldRef = frame->methodAreaItem->getConstantPoolItem(index);
  string classname = frame->methodAreaItem->getUtf8(fieldRef->constant_type_union.Fieldref_info.class_index);
  string fieldName = getFieldName(frame, index);

  if (classname == JAVA_SYSTEM_CLASSNAME) {
    frame->pushOperandStack(JvmValue(INT, DataUnion {.i = 0})); // valor simbólico que vai ser ignorado
    frame->pc += 3;
    return;
  }

  JvmValue value = jvm->getStaticField(classname, fieldName);
  frame->pushOperandStack(value);
  frame->pc += 3;
}

void putstatic (Frame * frame, JVM * jvm) {
  DCOUT << "putstatic" << endl;
  u1 firstBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 secondBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  u2 index = (firstBytes << 8) | secondBytes;  

  cp_info * fieldRef = frame->methodAreaItem->getConstantPoolItem(index);
  string classname = frame->methodAreaItem->getUtf8(fieldRef->constant_type_union.Fieldref_info.class_index);
  string fieldName = getFieldName(frame, index);

  JvmValue value = frame->popOperandStack();
  DCOUT << "value 0x" << hex << value.data.u << dec << ' ' << value.type << endl;
  jvm->setStaticField(classname, fieldName, value);
  frame->pc += 3;
}

void getfield (Frame * frame, JVM * jvm) {
  DCOUT << "getfield" << endl;
  u1 highBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 lowBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  u2 index = (highBytes << 8) | lowBytes;
  
  string fieldName = getFieldName(frame, index);
  int32_t objectRef = frame->popOperandStack().data.i;
  JvmValue value = jvm->getField(objectRef, fieldName);

  frame->pushOperandStack(value);
  DCOUT << "objectRef " << objectRef << ", value 0x" << hex << value.data.u << dec << endl;

  frame->pc += 3;
}

void putfield (Frame * frame, JVM * jvm) {
  DCOUT << "putfield" << endl;
  u1 highBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 lowBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  u2 index = (highBytes << 8) | lowBytes;
  
  string fieldName = getFieldName(frame, index);
  JvmValue value = frame->popOperandStack();
  int32_t objectRef = frame->popOperandStack().data.i;

  jvm->setField(objectRef, fieldName, value);
  DCOUT << "objectRef " << objectRef << ", value 0x" << hex << value.data.u << dec << endl;

  frame->pc += 3;
}

#pragma endregion

#pragma region invoke

void invokevirtual (Frame * frame, JVM * jvm) {
  u1 highBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 lowBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  u2 index = (highBytes << 8) | lowBytes;
  DCOUT << "invokevirtual #" << index << endl;

  cp_info * methodRef = frame->methodAreaItem->getConstantPoolItem(index);
  cp_info * nameAndTypeRef = frame->methodAreaItem->getConstantPoolItem(methodRef->constant_type_union.Methodref_info.name_and_type_index);
  string methodName = frame->methodAreaItem->getUtf8(nameAndTypeRef->constant_type_union.NameAndType.name_index);
  string methodDescriptor = frame->methodAreaItem->getUtf8(nameAndTypeRef->constant_type_union.NameAndType.descriptor_index);

  string className = frame->methodAreaItem->getUtf8(methodRef->constant_type_union.Methodref_info.class_index);
  if (className == JAVA_PRINT_CLASSNAME) {
    DCOUT << className << "." << methodName << endl;

    vector<string> argTypes = frame->methodAreaItem->getMethodArgTypesByNameAndTypeIndex(methodRef->constant_type_union.Methodref_info.name_and_type_index);
    // argTypes.pop_back(); // remove o tipo de retorno
    for (auto arg : argTypes) DCOUT << "arg " << arg << ' ';
    DCOUT << endl;
    javaPrintln(frame, argTypes);

    frame->pc += 3;
    return;
  }
  
  auto [invokedFrame, args] = createInvokedFrame(frame, index, methodName, methodDescriptor);
  setInvokedLocalVars(frame, invokedFrame, args);
  jvm->invoke(*invokedFrame);

  frame->pc += 3;
}

void invokespecial (Frame * frame, JVM * jvm) {
  u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  u4 index = (high_bytes << 8) | low_bytes;
  DCOUT << "invokespecial #" << index << endl;

  cp_info * methodRef = frame->methodAreaItem->getConstantPoolItem(index);
  cp_info * nameAndTypeRef = frame->methodAreaItem->getConstantPoolItem(methodRef->constant_type_union.Methodref_info.name_and_type_index);
  string methodName = frame->methodAreaItem->getUtf8(nameAndTypeRef->constant_type_union.NameAndType.name_index);
  string methodDescriptor = frame->methodAreaItem->getUtf8(nameAndTypeRef->constant_type_union.NameAndType.descriptor_index);

  auto [initFrame, args] = createInvokedFrame(frame, index, methodName, methodDescriptor);
  setInvokedLocalVars(frame, initFrame, args);
  jvm->invoke(*initFrame);

  frame->pc += 3;
}

void invokestatic (Frame * frame, JVM * jvm) {
  DCOUT << "invokestatic" << endl;
  u1 highBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  u1 lowBytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  u2 index = (highBytes << 8) | lowBytes;
  
  cp_info * methodRef = frame->methodAreaItem->getConstantPoolItem(index);
  cp_info * nameAndTypeRef = frame->methodAreaItem->getConstantPoolItem(methodRef->constant_type_union.Methodref_info.name_and_type_index);
  string methodName = frame->methodAreaItem->getUtf8(nameAndTypeRef->constant_type_union.NameAndType.name_index);
  string methodDescriptor = frame->methodAreaItem->getUtf8(nameAndTypeRef->constant_type_union.NameAndType.descriptor_index);

  string classname = frame->methodAreaItem->getUtf8(methodRef->constant_type_union.Methodref_info.class_index);
  if (classname == JAVA_OBJ_CLASSNAME) {
    // se for java/lang/Object, não fazer nada
    DCOUT << "é um invokestatic para o Object.class IGNORADO!" << endl;
    frame->pc += 3;
    return;
  }


  auto [invokedFrame, args] = createInvokedFrame(frame, index, methodName, methodDescriptor);
  setInvokedLocalVars(frame, invokedFrame, args, true);
  jvm->invoke(*invokedFrame);

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

  MethodArea  * methodAreaRef = frame->methodAreaItem->getMethodArea();
  MethodAreaItem * classMethodAreaItem = methodAreaRef->getMethodAreaItem(classname);

  // TODO: lidar com as exceções que a especificação diz que podem acontecer

  // iniciar fields com os valores default, acontecerá no init
  Object * heapItem = new Object(classMethodAreaItem);
  int32_t heapIndex = jvm->pushObject(heapItem);

  frame->pushOperandStack(JvmValue(REFERENCE, {.i = heapIndex})); // Objectref será o índice da instância na heap
  DCOUT << "new " << classname << " -> " << heapIndex << endl;

  frame->pc += 3;
}

void newarray (Frame * frame, JVM * jvm) {
  DCOUT << "newarray" << endl;
  u1 atype = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  int32_t count = frame->popOperandStack().data.i;

  if (count < 0) {
    throw std::runtime_error("NegativeArraySizeException");
  }

  JVMType type;

  switch (atype) {
    case 4: // T_BOOLEAN
      type = BOOL;
      break;
    case 5: // T_CHAR
      type = CHAR;
      break;
    case 6: // T_FLOAT
      type = FLOAT;
      break;  
    case 7: // T_DOUBLE
      type = DOUBLE;
      break;
    case 8: // T_BYTE
      type = BYTE;
      break;
    case 9: // T_SHORT
      type = SHORT;
      break;
    case 10: // T_INT
      type = INT;
      break;
    case 11: // T_LONG
      type = LONG;
      break;
    default:
      throw std::runtime_error("Invalid array type");
  }

  Array * array = new Array(type, count);

  int32_t heapIndex = jvm->pushArray(array);
  frame->pushOperandStack(JvmValue(REFERENCE, {.i = heapIndex}));

  frame->pc += 2;
  DCOUT << "newarray type: "<< (int32_t) atype  << " size: " << count << " index: " << heapIndex << endl;
}

void anewarray (Frame * frame, JVM * jvm) {
  DCOUT << "anewarray" << endl;
  // u1 high_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+1];
  // u1 low_bytes = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc+2];
  // u2 index = (high_bytes << 8) | low_bytes;

  // cp_info * classRef = frame->methodAreaItem->getConstantPoolItem(index);

  // string classname = frame->methodAreaItem->getUtf8(classRef->constant_type_union.Class_info.name_index);

  // MethodArea  * methodAreaRef = frame->methodAreaItem->getMethodArea();
  // MethodAreaItem * classMethodAreaItem = methodAreaRef->getMethodAreaItem(classname);
  // não estamos fazendo nada com a classe


  int32_t count = frame->popOperandStack().data.i;

  if (count < 0) {
    throw std::runtime_error("NegativeArraySizeException");
  }

  Array * array = new Array(REFERENCE, count);

  int32_t heapIndex = jvm->pushArray(array);
  frame->pushOperandStack(JvmValue(REFERENCE, {.i = heapIndex}));

  DCOUT << "anewarray  " << " size: " << count << " index: " << heapIndex << endl;
  frame->pc += 3;
}

#pragma endregion

#pragma region common

void arraylength (Frame * frame, JVM * jvm) {
  DCOUT << "arraylength" << endl;
  JvmValue arrayref = frame->popOperandStack();
  if (arrayref.type != REFERENCE) {
    throw std::runtime_error("arrayref is not a reference");
  }
  if(arrayref.data.i == 0){
    throw std::runtime_error("NullPointerException");
  }

  int32_t size = jvm->getArraySize(arrayref.data.i);
  frame->pushOperandStack(JvmValue(INT, {.i = size}));
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
  JvmValue value = frame->popOperandStack();
  if (value.data.i == 0) branch(frame);
  else frame->pc += 3;
}

void ifnonnull (Frame * frame, JVM * jvm) {
  DCOUT << "ifnonnull" << endl;
  JvmValue value = frame->popOperandStack();
  if (value.data.i != 0) branch(frame);
  else frame->pc += 3;
  frame->pc += 3;
}

#pragma endregion

#pragma region jump_w

void goto_w (Frame * frame, JVM * jvm) {
  DCOUT << "goto_w" << endl;
  u1 branchbyte1 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 branchbyte2 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];
  u1 branchbyte3= frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 3];
  u1 branchbyte4 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 4];
  int32_t jump = (int32_t) (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4;
  DCOUT << "jump to pc " << frame->pc + jump << endl;
  frame->pc += jump;
}

void jsr_w (Frame * frame, JVM * jvm) {
  DCOUT << "jsr_w" << endl;
  u1 branchbyte1 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 1];
  u1 branchbyte2 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 2];
  u1 branchbyte3= frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 3];
  u1 branchbyte4 = frame->method_info->attributes->attribute_info_union.code_attribute.code[frame->pc + 4];
  int32_t jump = (int32_t) (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4;
  JvmValue returnAddress = JvmValue(RETURNADDRESS, DataUnion {.u = frame->pc + (u4)5});
  frame->operandStack.push(returnAddress);
  frame->pc += jump;
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
