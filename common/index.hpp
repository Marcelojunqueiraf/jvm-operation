/**
 * @file classfile.hpp
 * @author Marcelo Piano
 * @author Marcelo Junqueira
 * @author Gabriel Borges
 * @author Maycon Vinnicyus
 * @author Edson Sales
 * @brief Arquivo que realiza os imports comuns
 */

#pragma once
// Todos os arquivos common devem ser importados aqui
#include "intTypes.hpp"
#include "primitiveTypes.hpp"
#include "class-file.hpp"
#include "converters.hpp"
#include <iostream>

extern bool DEBUG;
#define DCOUT if (DEBUG) std::cout << "DEBUG: "
