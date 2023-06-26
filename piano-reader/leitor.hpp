/**
 * @file leitor_exibidor.h
 * @author Marcelo Piano
 * @author Aluno 2
 * @author Aluno 3
 * @author Aluno 4
 * @author Aluno 5
 * @brief Arquivo com as funções utilizadas no leitor.
 * @details Declaração das funções de leitura.
 */
#include "../common/class-file.hpp"
#include "utf8.hpp"
#ifndef LEITORH
#define LEITORH

// sempre que tiver um INDEX é um indice do constant pool

// Funções de leitura de 8, 16, 32 e 64 bits

/// @brief lê o tipo de dado u1
/// @param fd Ponteiro para Byte do arquivo .Class lido
static u1 u1Read(FILE * fd);

/// @brief lê o tipo de dado u2
/// @param fd Ponteiro para Byte do arquivo .Class lido
static u2 u2Read(FILE * fd);

/// @brief lê o tipo de dado u4
/// @param fd Ponteiro para Byte do arquivo .Class lido
static u4 u4Read(FILE * fd);

/// @brief lê o tipo de dado u8
/// @param fd Ponteiro para Byte do arquivo .Class lido
static u8 u8Read(FILE * fd);


/// @brief lê do arquivo .class e preenche a tabela de excessoes do attributo code em questão.
/// @param fd Ponteiro para Byte do arquivo .Class lido
/// @param exception_table ponteiro para tabela de excessoes
/// @param exception_table_lenght tamanho da tabela
void read_attribute_code_exception_table(FILE *fd, exception_table * exception_table, u2 exception_table_lenght);

/// @brief Funçao que le a exception table 
/// @param fd Ponteiro para Byte do arquivo .Class lido
void read_exception_table(FILE *fd, exception_table *exception_table, u2 exception_table_length);


/// @brief Funçao que le o arquivo 
/// @param fd Ponteiro para Byte do arquivo .Class lido
/// @param attr_info Ponteiro para a lista de attributos
/// @param attr_count Quantidade de attributos
/// @param cp Ponteiro para o Constant Pool
void read_attributes(FILE *,attribute_info *, u2 ,cp_info *);

/// @brief Funçao que le o arquivo 
/// @param fd Ponteiro para Byte do arquivo .Class lido
/// @param cf Ponteiro para o Class File
void read_fields(FILE *,ClassFile *);

/// @brief Funçao que le o arquivo 
/// @param fd Ponteiro para Byte do arquivo .Class lido
/// @param cf Ponteiro para o Class File
void read_cp_info(FILE *,ClassFile *);

/// @brief Funçao que le o arquivo 
/// @param fd Ponteiro para Byte do arquivo .Class lido
/// @param cf Ponteiro para o Class File
void class_reader(FILE *,ClassFile *);


#endif