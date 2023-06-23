#include "../../common/class-file.h"
#include "../read-bytes.h"

#ifndef READ_ATTRIBUTES_H
#define READ_ATTRIBUTES_H

void readAttributes(cp_info * constant_pool, attribute_info * attributes, FILE * fp, u2 attributes_count);
void readAttribute(cp_info * constant_pool, attribute_info * attribute, FILE* fp);
void readCodeAttribute(cp_info * constant_pool, code_attribute * info, FILE* fp);
void readLineNumberTableAttribute(cp_info * constant_pool, LineNumberTable_attribute * info, FILE* fp);
void readSourceFileAttribute(cp_info * constant_pool, SourceFile_attribute * info, FILE* fp);
void readExceptionsAttribute(cp_info * constant_pool, Exceptions_attribute * info, FILE* fp);
void readConstantValueAttribute(cp_info * constant_pool, ConstantValue_attribute * info, FILE* fp);
void readInnerClassesAttribute(cp_info * constant_pool, InnerClasses_attribute * info, FILE* fp);
void readLocalVariableTableAttribute(cp_info * constant_pool, LocalVariableTable_attribute * info, FILE* fp);

#endif