#include "attributes.h"
#include "../../common/get-utf8.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void readAttributes(cp_info * constant_pool, attribute_info * attributes, FILE * fp, u2 attributes_count) {
    for (u2 i = 0; i < attributes_count; i++) {
        readAttribute(constant_pool, &attributes[i], fp);
    }
}

void readAttribute(cp_info * constant_pool, attribute_info * attribute, FILE* fp) {
    attribute->attribute_name_index = readU2(fp);
    attribute->attribute_length = readU4(fp);

    attribute->info = malloc(sizeof(u1) * attribute->attribute_length);

    char * attributeType = getUtf8(constant_pool, attribute->attribute_name_index);

    if (!strcmp(attributeType, "Code")) {
        readCodeAttribute(constant_pool, (code_attribute *) attribute->info, fp);
    } else if (!strcmp(attributeType, "LineNumberTable")) {
        readLineNumberTableAttribute(constant_pool, (LineNumberTable_attribute *) attribute->info, fp);
    } else if (!strcmp(attributeType, "SourceFile")) {
        readSourceFileAttribute(constant_pool, (SourceFile_attribute *) attribute->info, fp);
    } else if (!strcmp(attributeType, "Exceptions")) {
        readExceptionsAttribute(constant_pool, (Exceptions_attribute *) attribute->info, fp);
    } else if (!strcmp(attributeType, "ConstantValue")) {
        readConstantValueAttribute(constant_pool, (ConstantValue_attribute *) attribute->info, fp);
    } else if (!strcmp(attributeType, "InnerClasses")) {
        readInnerClassesAttribute(constant_pool, (InnerClasses_attribute *) attribute->info, fp);
    } else if (!strcmp(attributeType, "LocalVariableTable")) {
        readLocalVariableTableAttribute(constant_pool, (LocalVariableTable_attribute *) attribute->info, fp);
    } else {
      for(u4 info_index = 0; info_index < attribute->attribute_length; info_index++){
        u1* info = &(attribute->info[info_index]);
        *info = readU1(fp);
      }
    }
}

void readExceptionsAttribute(cp_info * constant_pool, Exceptions_attribute * info, FILE* fp) {
    info->number_of_exceptions = readU2(fp);
    info->exception_index_table = malloc(sizeof(u2) * info->number_of_exceptions);
    for (u2 i = 0; i < info->number_of_exceptions; i++) {
        info->exception_index_table[i] = readU2(fp);
    }
}

void readConstantValueAttribute(cp_info * constant_pool, ConstantValue_attribute * info, FILE* fp) {
    info->constantvalue_index = readU2(fp);
}

void readInnerClassesAttribute(cp_info * constant_pool, InnerClasses_attribute * info, FILE* fp) {
    info->number_of_classes = readU2(fp);
    info->classes = malloc(sizeof(classes) * info->number_of_classes);
    for (u2 i = 0; i < info->number_of_classes; i++) {
        info->classes[i].inner_class_info_index = readU2(fp);
        info->classes[i].outer_class_info_index = readU2(fp);
        info->classes[i].inner_name_index = readU2(fp);
        info->classes[i].inner_class_access_flags = readU2(fp);
    }
}

void readLocalVariableTableAttribute(cp_info *constant_pool, LocalVariableTable_attribute *info, FILE *fp) {
    info->local_variable_table_length = readU2(fp);
    info->local_variable_table = malloc(sizeof(local_variable_table) * info->local_variable_table_length);
    for (u2 i = 0; i < info->local_variable_table_length; i++) {
        info->local_variable_table[i].start_pc = readU2(fp);
        info->local_variable_table[i].length = readU2(fp);
        info->local_variable_table[i].name_index = readU2(fp);
        info->local_variable_table[i].descriptor_index = readU2(fp);
        info->local_variable_table[i].index = readU2(fp);
    }
}
