#include "../common/class-file.hpp"


#ifndef UTF8H
#define UTF8H

/// @brief Função que retorna uma string a partir de um cp_info que representa um Utf8
/// @param cp_pointer Ponteiro que aponta para o cp_info que representa um Utf8
string utf8ToString(cp_info * cp_pointer);

#endif