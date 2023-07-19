/**
 * @file classfile.hpp
 * @author Marcelo Piano
 * @author Marcelo Junqueira
 * @author Gabriel Borges
 * @author Maycon Vinnicyus
 * @author Edson Sales
 * @brief Arquivo com a função de conversão de utf8 para string
*/

#pragma once

#include "../common/class-file.hpp"

/// @brief Função que retorna uma string a partir de um cp_info que representa um Utf8
/// @param cp_pointer Ponteiro que aponta para o cp_info que representa um Utf8
string utf8ToString(cp_info * cp_pointer);
