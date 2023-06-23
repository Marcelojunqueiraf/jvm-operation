#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>

void readSourceFileAttribute(cp_info * constant_pool, SourceFile_attribute * info, FILE* fp) {
    info->sourcefile_index = readU2(fp);
}
