#include "jvm.hpp"

void JVM::initClass(MethodAreaItem * methodAreaItem) {
  Method_info * staticBlock = methodAreaItem->getStaticBlock();
  Frame * frame = new Frame(staticBlock, methodAreaItem);
  if (staticBlock != NULL) this->frameStack.push(*frame);

  if (methodAreaItem->getClassName() == JAVA_OBJ_CLASSNAME) return;
  MethodAreaItem * superClass = this->methodArea.getMethodAreaItem(methodAreaItem->getSuper());

  this->initClass(superClass);
}

void JVM::initialize(string classPath) {
  cout << "initialize" << endl;
  MethodAreaItem * firstClass = this->methodArea.getMethodAreaItemFromFile(classPath);

  Method_info * mainMethod = firstClass->getMainMethod();
  Frame * frame = new Frame(mainMethod, firstClass);

  this->frameStack.push(*frame);
  this->initClass(firstClass);
  cout << "initialize end" << endl;
}

code_attribute * getCode(Method_info * method_info, MethodAreaItem * methodAreaItem) {
  for (int i = 0; i < method_info->attributes_count; i++) {
    Attribute_info * attribute = &method_info->attributes[i];
    u2 index = attribute->attribute_name_index;
    string name = methodAreaItem->getUtf8(index);
    if (name == "Code") {
      return &attribute->attribute_info_union.code_attribute;
    }
  }
  return NULL;
}

void JVM::executeInstruction(u1 * opcode, Frame * frame){
//  cout << "instruction: " << (int)*opcode << endl;
  this->instructionsMap[*opcode](frame);
}

void JVM::executeFrame(Frame * frame) {
  string methodName = frame->methodAreaItem->getUtf8(frame->method_info->name_index);
  cout << "executeFrame #" <<  frame->method_info->name_index << ' ' << methodName << endl;
  code_attribute * codeAtt = getCode(frame->method_info, frame->methodAreaItem);
  cout << "code len: " << codeAtt->code_length << endl;

  
  // realizar a lógica do PC aqui 
  while(frame->pc < codeAtt->code_length){
    u1 * opcode = codeAtt->code + frame->pc;
    this->executeInstruction(opcode, frame);
  };

  // verifica se o método acabou
  if (frame->pc >= codeAtt->code_length) return;
  cout << "verificou" << endl;
  u1 * instruction = codeAtt->code + frame->pc;
  cout << "pegou instruction" << endl;
  executeInstruction(instruction, frame);
  cout << "executou" << endl;
  frame->pc++;
}

void JVM::run() {
  while (this->frameStack.getStackSize() > 0) {
    cout << "run" << endl;
    Frame * frame = this->frameStack.top();
    cout << "frame" << endl;
    this->executeFrame(frame);
    cout << "executeFrame" << endl;
    this->frameStack.pop();
  }
}

JVM::JVM() {
  this->instructionsMap = vector <void(*)(Frame *)>(256);

  this->instructionsMap[0x00] = &nop;
  this->instructionsMap[0x01] = &aconst_null;
  this->instructionsMap[0x02] = &iconst_m1;
  this->instructionsMap[0x03] = &iconst_0;
  this->instructionsMap[0x04] = &iconst_1;
  this->instructionsMap[0x05] = &iconst_2;
  this->instructionsMap[0x06] = &iconst_3;
  this->instructionsMap[0x07] = &iconst_4;
  this->instructionsMap[0x08] = &iconst_5;
  this->instructionsMap[0x09] = &lconst_0;
  this->instructionsMap[0x0a] = &lconst_1;
  this->instructionsMap[0x0b] = &fconst_0;
  this->instructionsMap[0x0c] = &fconst_1;
  this->instructionsMap[0x0d] = &fconst_2;
  this->instructionsMap[0x0e] = &dconst_0;
  this->instructionsMap[0x0f] = &dconst_1;
  this->instructionsMap[0x10] = &bipush;
  this->instructionsMap[0x11] = &sipush;
  this->instructionsMap[0x12] = &ldc;
  this->instructionsMap[0x13] = &ldc_w;
  this->instructionsMap[0x14] = &ldc2_w;
  this->instructionsMap[0x15] = &iload;
  this->instructionsMap[0x16] = &lload;
  this->instructionsMap[0x17] = &fload;
  this->instructionsMap[0x18] = &dload;
  this->instructionsMap[0x19] = &aload;
  this->instructionsMap[0x1a] = &iload_0;
  this->instructionsMap[0x1b] = &iload_1;
  this->instructionsMap[0x1c] = &iload_2;
  this->instructionsMap[0x1d] = &iload_3;
  this->instructionsMap[0x1e] = &lload_0;
  this->instructionsMap[0x1f] = &lload_1;
  this->instructionsMap[0x20] = &lload_2;
  this->instructionsMap[0x21] = &lload_3;
  this->instructionsMap[0x22] = &fload_0;
  this->instructionsMap[0x23] = &fload_1;
  this->instructionsMap[0x24] = &fload_2;
  this->instructionsMap[0x25] = &fload_3;
  this->instructionsMap[0x26] = &dload_0;
  this->instructionsMap[0x27] = &dload_1;
  this->instructionsMap[0x28] = &dload_2;
  this->instructionsMap[0x29] = &dload_3;
  this->instructionsMap[0x2a] = &aload_0;
  this->instructionsMap[0x2b] = &aload_1;
  this->instructionsMap[0x2c] = &aload_2;
  this->instructionsMap[0x2d] = &aload_3;
  this->instructionsMap[0x2e] = &iaload;
  this->instructionsMap[0x2f] = &laload;
  this->instructionsMap[0x30] = &faload;
  this->instructionsMap[0x31] = &daload;
  this->instructionsMap[0x32] = &aaload;
  this->instructionsMap[0x33] = &baload;
  this->instructionsMap[0x34] = &caload;
  this->instructionsMap[0x35] = &saload;
  this->instructionsMap[0x36] = &istore;
  this->instructionsMap[0x37] = &lstore;
  this->instructionsMap[0x38] = &fstore;
  this->instructionsMap[0x39] = &dstore;
  this->instructionsMap[0x3a] = &astore;
  this->instructionsMap[0x3b] = &istore_0;
  this->instructionsMap[0x3c] = &istore_1;
  this->instructionsMap[0x3d] = &istore_2;
  this->instructionsMap[0x3e] = &istore_3;
  this->instructionsMap[0x3f] = &lstore_0;
  this->instructionsMap[0x40] = &lstore_1;
  this->instructionsMap[0x41] = &lstore_2;
  this->instructionsMap[0x42] = &lstore_3;
  this->instructionsMap[0x43] = &fstore_0;
  this->instructionsMap[0x44] = &fstore_1;
  this->instructionsMap[0x45] = &fstore_2;
  this->instructionsMap[0x46] = &fstore_3;
  this->instructionsMap[0x47] = &dstore_0;
  this->instructionsMap[0x48] = &dstore_1;
  this->instructionsMap[0x49] = &dstore_2;
  this->instructionsMap[0x4a] = &dstore_3;
  this->instructionsMap[0x4b] = &astore_0;
  this->instructionsMap[0x4c] = &astore_1;
  this->instructionsMap[0x4d] = &astore_2;
  this->instructionsMap[0x4e] = &astore_3;
  this->instructionsMap[0x4f] = &iastore;
  this->instructionsMap[0x50] = &lastore;
  this->instructionsMap[0x51] = &fastore;
  this->instructionsMap[0x52] = &dastore;
  this->instructionsMap[0x53] = &aastore;
  this->instructionsMap[0x54] = &bastore;
  this->instructionsMap[0x55] = &castore;
  this->instructionsMap[0x56] = &sastore;
  this->instructionsMap[0x57] = &pop;
  this->instructionsMap[0x58] = &pop2;
  this->instructionsMap[0x59] = &dup;
  this->instructionsMap[0x5a] = &dup_x1;
  this->instructionsMap[0x5b] = &dup_x2;
  this->instructionsMap[0x5c] = &dup2;
  this->instructionsMap[0x5d] = &dup2_x1;
  this->instructionsMap[0x5e] = &dup2_x2;
  this->instructionsMap[0x5f] = &swap;
  this->instructionsMap[0x60] = &iadd;
  this->instructionsMap[0x61] = &ladd;
  this->instructionsMap[0x62] = &fadd;
  this->instructionsMap[0x63] = &dadd;
  this->instructionsMap[0x64] = &isub;
  this->instructionsMap[0x65] = &lsub;
  this->instructionsMap[0x66] = &fsub;
  this->instructionsMap[0x67] = &dsub;
  this->instructionsMap[0x68] = &imul;
  this->instructionsMap[0x69] = &lmul;
  this->instructionsMap[0x6a] = &fmul;
  this->instructionsMap[0x6b] = &dmul;
  this->instructionsMap[0x6c] = &idiv;
  this->instructionsMap[0x6d] = &ldiv;
  this->instructionsMap[0x6e] = &fdiv;
  this->instructionsMap[0x6f] = &ddiv;
  this->instructionsMap[0x70] = &irem;
  this->instructionsMap[0x71] = &lrem;
  this->instructionsMap[0x72] = &frem;
  this->instructionsMap[0x73] = &drem;
  this->instructionsMap[0x74] = &ineg;
  this->instructionsMap[0x75] = &lneg;
  this->instructionsMap[0x76] = &fneg;
  this->instructionsMap[0x77] = &dneg;
  this->instructionsMap[0x78] = &ishl;
  this->instructionsMap[0x79] = &lshl;
  this->instructionsMap[0x7a] = &ishr;
  this->instructionsMap[0x7b] = &lshr;
  this->instructionsMap[0x7c] = &iushr;
  this->instructionsMap[0x7d] = &lushr;
  this->instructionsMap[0x7e] = &iand;
  this->instructionsMap[0x7f] = &land;
  this->instructionsMap[0x80] = &ior;
  this->instructionsMap[0x81] = &lor;
  this->instructionsMap[0x82] = &ixor;
  this->instructionsMap[0x83] = &lxor;
  this->instructionsMap[0x84] = &iinc;
  this->instructionsMap[0x85] = &i2l;
  this->instructionsMap[0x86] = &i2f;
  this->instructionsMap[0x87] = &i2d;
  this->instructionsMap[0x88] = &l2i;
  this->instructionsMap[0x89] = &l2f;
  this->instructionsMap[0x8a] = &l2d;
  this->instructionsMap[0x8b] = &f2i;
  this->instructionsMap[0x8c] = &f2l;
  this->instructionsMap[0x8d] = &f2d;
  this->instructionsMap[0x8e] = &d2i;
  this->instructionsMap[0x8f] = &d2l;
  this->instructionsMap[0x90] = &d2f;
  this->instructionsMap[0x91] = &i2b;
  this->instructionsMap[0x92] = &i2c;
  this->instructionsMap[0x93] = &i2s;
  this->instructionsMap[0x94] = &lcmp;
  this->instructionsMap[0x95] = &fcmpl;
  this->instructionsMap[0x96] = &fcmpg;
  this->instructionsMap[0x97] = &dcmpl;
  this->instructionsMap[0x98] = &dcmpg;
  this->instructionsMap[0x99] = &ifeq;
  this->instructionsMap[0x9a] = &ifne;
  this->instructionsMap[0x9b] = &iflt;
  this->instructionsMap[0x9c] = &ifge;
  this->instructionsMap[0x9d] = &ifgt;
  this->instructionsMap[0x9e] = &ifle;
  this->instructionsMap[0x9f] = &if_icmpeq;
  this->instructionsMap[0xa0] = &if_icmpne;
  this->instructionsMap[0xa1] = &if_icmplt;
  this->instructionsMap[0xa2] = &if_icmpge;
  this->instructionsMap[0xa3] = &if_icmpgt;
  this->instructionsMap[0xa4] = &if_icmple;
  this->instructionsMap[0xa5] = &if_acmpeq;
  this->instructionsMap[0xa6] = &if_acmpne;
  this->instructionsMap[0xa7] = &_goto;
  this->instructionsMap[0xa8] = &jsr;
  this->instructionsMap[0xa9] = &ret;
  this->instructionsMap[0xaa] = &tableswitch;
  this->instructionsMap[0xab] = &lookupswitch;
  this->instructionsMap[0xac] = &ireturn;
  this->instructionsMap[0xad] = &lreturn;
  this->instructionsMap[0xae] = &freturn;
  this->instructionsMap[0xaf] = &dreturn;
  this->instructionsMap[0xb0] = &areturn;
  this->instructionsMap[0xb1] = &_return;
  this->instructionsMap[0xb2] = &getstatic;
  this->instructionsMap[0xb3] = &putstatic;
  this->instructionsMap[0xb4] = &getfield;
  this->instructionsMap[0xb5] = &putfield;
  this->instructionsMap[0xb6] = &invokevirtual;
  this->instructionsMap[0xb7] = &invokespecial;
  this->instructionsMap[0xb8] = &invokestatic;
  this->instructionsMap[0xb9] = &invokeinterface;
  this->instructionsMap[0xba] = &invokedynamic;
  this->instructionsMap[0xbb] = &_new;
  this->instructionsMap[0xbc] = &newarray;
  this->instructionsMap[0xbd] = &anewarray;
  this->instructionsMap[0xbe] = &arraylength;
  this->instructionsMap[0xbf] = &athrow;
  this->instructionsMap[0xc0] = &checkcast;
  this->instructionsMap[0xc1] = &instanceof;
  this->instructionsMap[0xc2] = &monitorenter;
  this->instructionsMap[0xc3] = &monitorexit;
  this->instructionsMap[0xc4] = &wide;
  this->instructionsMap[0xc5] = &multianewarray;
  this->instructionsMap[0xc6] = &ifnull;
  this->instructionsMap[0xc7] = &ifnonnull;
  this->instructionsMap[0xc8] = &goto_w;
  this->instructionsMap[0xc9] = &jsr_w;
  this->instructionsMap[0xca] = &breakpoint;
  this->instructionsMap[0xfe] = &impdep1;
  this->instructionsMap[0xff] = &impdep2;
}