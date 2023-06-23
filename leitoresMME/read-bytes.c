#include "read-bytes.h"

u1 readU1(FILE * fp){
  u1 target;
  if(fread(&target, sizeof(u1), 1, fp) != 1){
    return -1;
  }
  return target;
}

u2 readU2(FILE * fp){
  u2 target;
  u1 lowByte, highByte;
  highByte = readU1(fp);
  lowByte = readU1(fp);

  if((highByte == MAXU1) | (lowByte == MAXU1))
    return MAXU2;

  target = ((highByte)<<8) | ((lowByte));
  return target;
}

u4 readU4(FILE * fp) {
  u4 target;
  u1 b0, b1, b2, b3;
  b3 = readU1(fp);
  b2 = readU1(fp);
  b1 = readU1(fp);
  b0 = readU1(fp);
  //Tratar erros, todo
  if((b0 == MAXU1) | (b1 == MAXU1) | (b2 == MAXU1) | (b3 == MAXU1)) return MAXU4;

  target = (b3<<24) | (b2<<16) | (b1<<8) | (b0);
  return target;
}
