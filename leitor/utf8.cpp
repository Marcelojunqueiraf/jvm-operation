#include "utf8.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

// essa função vai retornar um vetor de char
// pegar o cp info em questão usar o length para iterar e "concatenar" a string 
char * Utf8_decoder(cp_info *cp_info_pointer){
  return (char *) utf8ToString(cp_info_pointer).c_str();
}

string utf8ToString(cp_info * cp_pointer) {
  u2 len = cp_pointer->constant_type_union.Utf8.length;
  char * bytes = (char *) cp_pointer->constant_type_union.Utf8.bytes;
  return string(bytes, len);
}
