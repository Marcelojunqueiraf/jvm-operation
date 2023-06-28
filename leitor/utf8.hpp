#include "../common/class-file.hpp"


#ifndef UTF8H
#define UTF8H

/// @brief Função que exibe os bytes em ascii que estão alocados no espaço de memória Bytes 
/// @param cp_info_pointer Ponteiro que aponta para o cp_info que representa um Utf8
char* Utf8_decoder(cp_info *);

#endif