#include "instructions.hpp"

// void loadInstructions (InstructionsMap * destiny) {
//   InstructionsMap instructionsMap;
//   instructionsMap[0x00] = &nop;
//   instructionsMap[0x01] = &aconst_null;
//   instructionsMap[0x02] = &iconst_m1;
//   instructionsMap[0x03] = &iconst_0;
//   instructionsMap[0x04] = &iconst_1;
//   instructionsMap[0x05] = &iconst_2;
//   instructionsMap[0x06] = &iconst_3;
//   instructionsMap[0x07] = &iconst_4;
//   instructionsMap[0x08] = &iconst_5;
//   instructionsMap[0x09] = &lconst_0;
//   instructionsMap[0x0a] = &lconst_1;
//   instructionsMap[0x0b] = &fconst_0;
//   instructionsMap[0x0c] = &fconst_1;
//   instructionsMap[0x0d] = &fconst_2;
//   instructionsMap[0x0e] = &dconst_0;
//   instructionsMap[0x0f] = &dconst_1;
//   instructionsMap[0x10] = &bipush;
//   instructionsMap[0x11] = &sipush;
//   instructionsMap[0x12] = &ldc;
//   instructionsMap[0x13] = &ldc_w;
//   instructionsMap[0x14] = &ldc2_w;
//   instructionsMap[0x15] = &iload;
//   instructionsMap[0x16] = &lload;
//   instructionsMap[0x17] = &fload;
//   instructionsMap[0x18] = &dload;
//   instructionsMap[0x19] = &aload;
//   instructionsMap[0x1a] = &iload_0;
//   instructionsMap[0x1b] = &iload_1;
//   instructionsMap[0x1c] = &iload_2;
//   instructionsMap[0x1d] = &iload_3;
//   instructionsMap[0x1e] = &lload_0;
//   instructionsMap[0x1f] = &lload_1;
//   instructionsMap[0x20] = &lload_2;
//   instructionsMap[0x21] = &lload_3;
//   instructionsMap[0x22] = &fload_0;
//   instructionsMap[0x23] = &fload_1;
//   instructionsMap[0x24] = &fload_2;
//   instructionsMap[0x25] = &fload_3;
//   instructionsMap[0x26] = &dload_0;
//   instructionsMap[0x27] = &dload_1;
//   instructionsMap[0x28] = &dload_2;
//   instructionsMap[0x29] = &dload_3;
//   instructionsMap[0x2a] = &aload_0;
//   instructionsMap[0x2b] = &aload_1;
//   instructionsMap[0x2c] = &aload_2;
//   instructionsMap[0x2d] = &aload_3;
//   instructionsMap[0x2e] = &iaload;
//   instructionsMap[0x2f] = &laload;
//   instructionsMap[0x30] = &faload;
//   instructionsMap[0x31] = &daload;
//   instructionsMap[0x32] = &aaload;
//   instructionsMap[0x33] = &baload;
//   instructionsMap[0x34] = &caload;
//   instructionsMap[0x35] = &saload;
//   instructionsMap[0x36] = &istore;
//   instructionsMap[0x37] = &lstore;
//   instructionsMap[0x38] = &fstore;
//   instructionsMap[0x39] = &dstore;
//   instructionsMap[0x3a] = &astore;
//   instructionsMap[0x3b] = &istore_0;
//   instructionsMap[0x3c] = &istore_1;
//   instructionsMap[0x3d] = &istore_2;
//   instructionsMap[0x3e] = &istore_3;
//   instructionsMap[0x3f] = &lstore_0;
//   instructionsMap[0x40] = &lstore_1;
//   instructionsMap[0x41] = &lstore_2;
//   instructionsMap[0x42] = &lstore_3;
//   instructionsMap[0x43] = &fstore_0;
//   instructionsMap[0x44] = &fstore_1;
//   instructionsMap[0x45] = &fstore_2;
//   instructionsMap[0x46] = &fstore_3;
//   instructionsMap[0x47] = &dstore_0;
//   instructionsMap[0x48] = &dstore_1;
//   instructionsMap[0x49] = &dstore_2;
//   instructionsMap[0x4a] = &dstore_3;
//   instructionsMap[0x4b] = &astore_0;
//   instructionsMap[0x4c] = &astore_1;
//   instructionsMap[0x4d] = &astore_2;
//   instructionsMap[0x4e] = &astore_3;
//   instructionsMap[0x4f] = &iastore;
//   instructionsMap[0x50] = &lastore;
//   instructionsMap[0x51] = &fastore;
//   instructionsMap[0x52] = &dastore;
//   instructionsMap[0x53] = &aastore;
//   instructionsMap[0x54] = &bastore;
//   instructionsMap[0x55] = &castore;
//   instructionsMap[0x56] = &sastore;
//   instructionsMap[0x57] = &pop;
//   instructionsMap[0x58] = &pop2;
//   instructionsMap[0x59] = &dup;
//   instructionsMap[0x5a] = &dup_x1;
//   instructionsMap[0x5b] = &dup_x2;
//   instructionsMap[0x5c] = &dup2;
//   instructionsMap[0x5d] = &dup2_x1;
//   instructionsMap[0x5e] = &dup2_x2;
//   instructionsMap[0x5f] = &swap;
//   instructionsMap[0x60] = &iadd;
//   instructionsMap[0x61] = &ladd;
//   instructionsMap[0x62] = &fadd;
//   instructionsMap[0x63] = &dadd;
//   instructionsMap[0x64] = &isub;
//   instructionsMap[0x65] = &lsub;
//   instructionsMap[0x66] = &fsub;
//   instructionsMap[0x67] = &dsub;
//   instructionsMap[0x68] = &imul;
//   instructionsMap[0x69] = &lmul;
//   instructionsMap[0x6a] = &fmul;
//   instructionsMap[0x6b] = &dmul;
//   instructionsMap[0x6c] = &idiv;
//   instructionsMap[0x6d] = &ldiv;
//   instructionsMap[0x6e] = &fdiv;
//   instructionsMap[0x6f] = &ddiv;
//   instructionsMap[0x70] = &irem;
//   instructionsMap[0x71] = &lrem;
//   instructionsMap[0x72] = &frem;
//   instructionsMap[0x73] = &drem;
//   instructionsMap[0x74] = &ineg;
//   instructionsMap[0x75] = &lneg;
//   instructionsMap[0x76] = &fneg;
//   instructionsMap[0x77] = &dneg;
//   instructionsMap[0x78] = &ishl;
//   instructionsMap[0x79] = &lshl;
//   instructionsMap[0x7a] = &ishr;
//   instructionsMap[0x7b] = &lshr;
//   instructionsMap[0x7c] = &iushr;
//   instructionsMap[0x7d] = &lushr;
//   instructionsMap[0x7e] = &iand;
//   instructionsMap[0x7f] = &land;
//   instructionsMap[0x80] = &ior;
//   instructionsMap[0x81] = &lor;
//   instructionsMap[0x82] = &ixor;
//   instructionsMap[0x83] = &lxor;
//   instructionsMap[0x84] = &iinc;
//   instructionsMap[0x85] = &i2l;
//   instructionsMap[0x86] = &i2f;
//   instructionsMap[0x87] = &i2d;
//   instructionsMap[0x88] = &l2i;
//   instructionsMap[0x89] = &l2f;
//   instructionsMap[0x8a] = &l2d;
//   instructionsMap[0x8b] = &f2i;
//   instructionsMap[0x8c] = &f2l;
//   instructionsMap[0x8d] = &f2d;
//   instructionsMap[0x8e] = &d2i;
//   instructionsMap[0x8f] = &d2l;
//   instructionsMap[0x90] = &d2f;
//   instructionsMap[0x91] = &i2b;
//   instructionsMap[0x92] = &i2c;
//   instructionsMap[0x93] = &i2s;
//   instructionsMap[0x94] = &lcmp;
//   instructionsMap[0x95] = &fcmpl;
//   instructionsMap[0x96] = &fcmpg;
//   instructionsMap[0x97] = &dcmpl;
//   instructionsMap[0x98] = &dcmpg;
//   instructionsMap[0x99] = &ifeq;
//   instructionsMap[0x9a] = &ifne;
//   instructionsMap[0x9b] = &iflt;
//   instructionsMap[0x9c] = &ifge;
//   instructionsMap[0x9d] = &ifgt;
//   instructionsMap[0x9e] = &ifle;
//   instructionsMap[0x9f] = &if_icmpeq;
//   instructionsMap[0xa0] = &if_icmpne;
//   instructionsMap[0xa1] = &if_icmplt;
//   instructionsMap[0xa2] = &if_icmpge;
//   instructionsMap[0xa3] = &if_icmpgt;
//   instructionsMap[0xa4] = &if_icmple;
//   instructionsMap[0xa5] = &if_acmpeq;
//   instructionsMap[0xa6] = &if_acmpne;
//   instructionsMap[0xa7] = &_goto;
//   instructionsMap[0xa8] = &jsr;
//   instructionsMap[0xa9] = &ret;
//   instructionsMap[0xaa] = &tableswitch;
//   instructionsMap[0xab] = &lookupswitch;
//   instructionsMap[0xac] = &ireturn;
//   instructionsMap[0xad] = &lreturn;
//   instructionsMap[0xae] = &freturn;
//   instructionsMap[0xaf] = &dreturn;
//   instructionsMap[0xb0] = &areturn;
//   instructionsMap[0xb1] = &_return;
//   instructionsMap[0xb2] = &getstatic;
//   instructionsMap[0xb3] = &putstatic;
//   instructionsMap[0xb4] = &getfield;
//   instructionsMap[0xb5] = &putfield;
//   instructionsMap[0xb6] = &invokevirtual;
//   instructionsMap[0xb7] = &invokespecial;
//   instructionsMap[0xb8] = &invokestatic;
//   instructionsMap[0xb9] = &invokeinterface;
//   instructionsMap[0xba] = &invokedynamic;
//   instructionsMap[0xbb] = &_new;
//   instructionsMap[0xbc] = &newarray;
//   instructionsMap[0xbd] = &anewarray;
//   instructionsMap[0xbe] = &arraylength;
//   instructionsMap[0xbf] = &athrow;
//   instructionsMap[0xc0] = &checkcast;
//   instructionsMap[0xc1] = &instanceof;
//   instructionsMap[0xc2] = &monitorenter;
//   instructionsMap[0xc3] = &monitorexit;
//   instructionsMap[0xc4] = &wide;
//   instructionsMap[0xc5] = &multianewarray;
//   instructionsMap[0xc6] = &ifnull;
//   instructionsMap[0xc7] = &ifnonnull;
//   instructionsMap[0xc8] = &goto_w;
//   instructionsMap[0xc9] = &jsr_w;
//   instructionsMap[0xca] = &breakpoint;
//   instructionsMap[0xfe] = &impdep1;
//   instructionsMap[0xff] = &impdep2;
// };

void nop (Frame * frame) {
  frame->pc++;
}

void aconst_null (Frame * frame) {
  
}

void iconst_m1 (Frame * frame) {
  
}

void iconst_0 (Frame * frame) {
  
}

void iconst_1 (Frame * frame) {
  
}

void iconst_2 (Frame * frame) {
  
}

void iconst_3 (Frame * frame) {
  
}

void iconst_4 (Frame * frame) {
  
}

void iconst_5 (Frame * frame) {
  
}

void lconst_0 (Frame * frame) {
  
}

void lconst_1 (Frame * frame) {
  
}

void fconst_0 (Frame * frame) {
  
}

void fconst_1 (Frame * frame) {
  
}

void fconst_2 (Frame * frame) {
  
}

void dconst_0 (Frame * frame) {
  
}

void dconst_1 (Frame * frame) {
  
}

void bipush (Frame * frame) {
  
}

void sipush (Frame * frame) {
  
}

void ldc (Frame * frame) {
  cout << "ldc" << endl;
}

void ldc_w (Frame * frame) {
  
}

void ldc2_w (Frame * frame) {
  
}

void iload (Frame * frame) {
  
}

void lload (Frame * frame) {
  
}

void fload (Frame * frame) {
  
}

void dload (Frame * frame) {
  
}

void aload (Frame * frame) {
  u1* instructions = frame->method_info->attributes->attribute_info_union.code_attribute.code;
  u1 index = instructions[frame->pc + 1];
  frame->operandStack.push(frame->localVariables[index]);
  frame->pc += 2;
}

void iload_0 (Frame * frame) {
  
}

void iload_1 (Frame * frame) {
  
}

void iload_2 (Frame * frame) {
  
}

void iload_3 (Frame * frame) {
  
}

void lload_0 (Frame * frame) {
  
}

void lload_1 (Frame * frame) {
  
}

void lload_2 (Frame * frame) {
  
}

void lload_3 (Frame * frame) {
  
}

void fload_0 (Frame * frame) {
  
}

void fload_1 (Frame * frame) {
  
}

void fload_2 (Frame * frame) {
  
}

void fload_3 (Frame * frame) {
  
}

void dload_0 (Frame * frame) {
  
}

void dload_1 (Frame * frame) {
  
}

void dload_2 (Frame * frame) {
  
}

void dload_3 (Frame * frame) {
  
}

void aload_0 (Frame * frame) {
  
  cout << "aload_0" << endl;
  
}

void aload_1 (Frame * frame) {
  
}

void aload_2 (Frame * frame) {
  
}

void aload_3 (Frame * frame) {
  
}

void iaload (Frame * frame) {
  
}

void laload (Frame * frame) {
  
}

void faload (Frame * frame) {
  
}

void daload (Frame * frame) {
  
}

void aaload (Frame * frame) {
  
}

void baload (Frame * frame) {
  
}

void caload (Frame * frame) {
  
}

void saload (Frame * frame) {
  
}

void istore (Frame * frame) {
  
}

void lstore (Frame * frame) {
  
}

void fstore (Frame * frame) {
  
}

void dstore (Frame * frame) {
  
}

void astore (Frame * frame) {
  
}

void istore_0 (Frame * frame) {
  
}

void istore_1 (Frame * frame) {
  
}

void istore_2 (Frame * frame) {
  
}

void istore_3 (Frame * frame) {
  
}

void lstore_0 (Frame * frame) {
  
}

void lstore_1 (Frame * frame) {
  
}

void lstore_2 (Frame * frame) {
  
}

void lstore_3 (Frame * frame) {
  
}

void fstore_0 (Frame * frame) {
  
}

void fstore_1 (Frame * frame) {
  
}

void fstore_2 (Frame * frame) {
  
}

void fstore_3 (Frame * frame) {
  
}

void dstore_0 (Frame * frame) {
  
}

void dstore_1 (Frame * frame) {
  
}

void dstore_2 (Frame * frame) {
  
}

void dstore_3 (Frame * frame) {
  
}

void astore_0 (Frame * frame) {
  
}

void astore_1 (Frame * frame) {
  
}

void astore_2 (Frame * frame) {
  
}

void astore_3 (Frame * frame) {
  
}

void iastore (Frame * frame) {
  
}

void lastore (Frame * frame) {
  
}

void fastore (Frame * frame) {
  
}

void dastore (Frame * frame) {
  
}

void aastore (Frame * frame) {
  
}

void bastore (Frame * frame) {
  
}

void castore (Frame * frame) {
  
}

void sastore (Frame * frame) {
  
}

void pop (Frame * frame) {
  
}

void pop2 (Frame * frame) {
  
}

void dup (Frame * frame) {
  
}

void dup_x1 (Frame * frame) {
  
}

void dup_x2 (Frame * frame) {
  
}

void dup2 (Frame * frame) {
  
}

void dup2_x1 (Frame * frame) {
  
}

void dup2_x2 (Frame * frame) {
  
}

void swap (Frame * frame) {
  
}

void iadd (Frame * frame) {
  
}

void ladd (Frame * frame) {
  
}

void fadd (Frame * frame) {
  
}

void dadd (Frame * frame) {
  
}

void isub (Frame * frame) {
  
}

void lsub (Frame * frame) {
  
}

void fsub (Frame * frame) {
  
}

void dsub (Frame * frame) {
  
}

void imul (Frame * frame) {
  
}

void lmul (Frame * frame) {
  
}

void fmul (Frame * frame) {
  
}

void dmul (Frame * frame) {
  
}

void idiv (Frame * frame) {
  
}

void ldiv (Frame * frame) {
  
}

void fdiv (Frame * frame) {
  
}

void ddiv (Frame * frame) {
  
}

void irem (Frame * frame) {
  
}

void lrem (Frame * frame) {
  
}

void frem (Frame * frame) {
  
}

void drem (Frame * frame) {
  
}

void ineg (Frame * frame) {
  
}

void lneg (Frame * frame) {
  
}

void fneg (Frame * frame) {
  
}

void dneg (Frame * frame) {
  
}

void ishl (Frame * frame) {
  
}

void lshl (Frame * frame) {
  
}

void ishr (Frame * frame) {
  
}

void lshr (Frame * frame) {
  
}

void iushr (Frame * frame) {
  
}

void lushr (Frame * frame) {
  
}

void iand (Frame * frame) {
  
}

void land (Frame * frame) {
  
}

void ior (Frame * frame) {
  
}

void lor (Frame * frame) {
  
}

void ixor (Frame * frame) {
  
}

void lxor (Frame * frame) {
  
}

void iinc (Frame * frame) {
  
}

void i2l (Frame * frame) {
  
}

void i2f (Frame * frame) {
  
}

void i2d (Frame * frame) {
  
}

void l2i (Frame * frame) {
  
}

void l2f (Frame * frame) {
  
}

void l2d (Frame * frame) {
  
}

void f2i (Frame * frame) {
  
}

void f2l (Frame * frame) {
  
}

void f2d (Frame * frame) {
  
}

void d2i (Frame * frame) {
  
}

void d2l (Frame * frame) {
  
}

void d2f (Frame * frame) {
  
}

void i2b (Frame * frame) {
  
}

void i2c (Frame * frame) {
  
}

void i2s (Frame * frame) {
  
}

void lcmp (Frame * frame) {
  
}

void fcmpl (Frame * frame) {
  
}

void fcmpg (Frame * frame) {
  
}

void dcmpl (Frame * frame) {
  
}

void dcmpg (Frame * frame) {
  
}

void ifeq (Frame * frame) {
  
}

void ifne (Frame * frame) {
  
}

void iflt (Frame * frame) {
  
}

void ifge (Frame * frame) {
  
}

void ifgt (Frame * frame) {
  
}

void ifle (Frame * frame) {
  
}

void if_icmpeq (Frame * frame) {
  
}

void if_icmpne (Frame * frame) {
  
}

void if_icmplt (Frame * frame) {
  
}

void if_icmpge (Frame * frame) {
  
}

void if_icmpgt (Frame * frame) {
  
}

void if_icmple (Frame * frame) {
  
}

void if_acmpeq (Frame * frame) {
  
}

void if_acmpne (Frame * frame) {
  
}

void _goto (Frame * frame) {
  
}

void jsr (Frame * frame) {
  
}

void ret (Frame * frame) {
  
}

void tableswitch (Frame * frame) {
  
}

void lookupswitch (Frame * frame) {
  
}

void ireturn (Frame * frame) {
  
}

void lreturn (Frame * frame) {
  
}

void freturn (Frame * frame) {
  
}

void dreturn (Frame * frame) {
  
}

void areturn (Frame * frame) {
  
}

void _return (Frame * frame) {
  cout << "return" << endl;
  frame->pc += 1;
}

void getstatic (Frame * frame) {
  cout << "getstatic" << endl;
}

void putstatic (Frame * frame) {
  
}

void getfield (Frame * frame) {
  
}

void putfield (Frame * frame) {
  
}

void invokevirtual (Frame * frame) {
  cout << "invokevirtual" << endl;
  exit(1);
}

void invokespecial (Frame * frame) {
  cout << "invokespecial" << endl;
  exit(1);
  
}

void invokestatic (Frame * frame) {
  cout << "static" << endl;
  frame->pc+= 3;
}

void invokeinterface (Frame * frame) {
  
}

void invokedynamic (Frame * frame) {
  
}

void _new (Frame * frame) {
  
}

void newarray (Frame * frame) {
  
}

void anewarray (Frame * frame) {
  
}

void arraylength (Frame * frame) {
  
}

void athrow (Frame * frame) {
  
}

void checkcast (Frame * frame) {
  
}

void instanceof (Frame * frame) {
  
}

void monitorenter (Frame * frame) {
  
}

void monitorexit (Frame * frame) {
  
}

void wide (Frame * frame) {
  
}

void multianewarray (Frame * frame) {
  
}

void ifnull (Frame * frame) {
  
}

void ifnonnull (Frame * frame) {
  
}

void goto_w (Frame * frame) {
  
}

void jsr_w (Frame * frame) {
  
}

void breakpoint (Frame * frame) {
  
}

void impdep1 (Frame * frame) {
  
}

void impdep2 (Frame * frame) {
  
}
