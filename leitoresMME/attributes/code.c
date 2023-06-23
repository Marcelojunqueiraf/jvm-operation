#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>

void readCodeAttribute(cp_info * constant_pool, code_attribute * info, FILE * fp) {
    info->max_stack = readU2(fp);
    info->max_locals = readU2(fp);
    info->code_length = readU4(fp);


    info->code = (u1 *) malloc(sizeof(u1) * info->code_length);
    for (u4 code_index = 0; code_index < info->code_length; code_index++) {
        info->code[code_index] = readU1(fp);
    }

    info->exception_table_length = readU2(fp);
    info->exception_table = (exception_table *) malloc(sizeof(exception_table) * info->exception_table_length);
    for (int i = 0; i < info->exception_table_length; i++) {
        info->exception_table[i].start_pc = readU2(fp);
        info->exception_table[i].end_pc = readU2(fp);
        info->exception_table[i].handler_pc = readU2(fp);
        info->exception_table[i].catch_type = readU2(fp);
    }
    info->attributes_count = readU2(fp);
    info->attributes = (attribute_info *) malloc(sizeof(attribute_info) * info->attributes_count);
    readAttributes(constant_pool, info->attributes, fp, info->attributes_count);
}