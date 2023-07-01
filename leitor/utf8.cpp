#include "utf8.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

string utf8ToString(cp_info * cp_pointer) {
  u2 len = cp_pointer->constant_type_union.Utf8.length;
  char * bytes = (char *) cp_pointer->constant_type_union.Utf8.bytes;
  return string(bytes, len);
}
