#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>

void readLineNumberTableAttribute(cp_info * constant_pool, LineNumberTable_attribute * info, FILE* fp) {
    info->line_number_table_length = readU2(fp);

    info->line_number_table = (line_number_table *) malloc(sizeof(line_number_table) * info->line_number_table_length);
    for (int i = 0; i < info->line_number_table_length; i++) {
        info->line_number_table[i].start_pc = readU2(fp);
        info->line_number_table[i].line_number = readU2(fp);
    }
}