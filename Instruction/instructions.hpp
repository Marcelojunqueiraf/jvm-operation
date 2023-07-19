/**
 * @file classfile.hpp
 * @author Marcelo Piano
 * @author Marcelo Junqueira
 * @author Gabriel Borges
 * @author Maycon Vinnicyus
 * @author Edson Sales
 * @brief Arquivo com as funções utilizadas na execução das instruções
*/

#pragma once

#include "../JVM/jvm.hpp"
#include <math.h>
#include <iostream>
#include <iomanip> // std::setprecision
#include <cstring>
#include <cmath>

class JVM;


/// @brief Vetor com ponteiro para as funções que executam as instruções. O index de cada elemento corresponde ao opcode da instrução.
typedef vector <void(*)(Frame * frame, JVM * jvm)> InstructionsMap;

/// @brief Função que inicializa o vetor de instruções
/// @param instructionsMap Ponteiro para o vetor de instruções
void loadInstructions(InstructionsMap * instructionsMap);

/// @brief Função executada quando um elemento da InstructionsMap com index igual um opcode de uma instrução não suportada tenta ser acessado.
void notSupported();

/// @brief Função que não realiza nenhuma operação
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVMFunção que não realiza 
void nop (Frame * frame, JVM * jvm);


/// @brief Coloca uma referência para um valor nulo no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void aconst_null (Frame * frame, JVM * jvm);

/// @brief Coloca o valor inteiro -1 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iconst_m1 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor inteiro 0 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iconst_0 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor inteiro 1 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iconst_1 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor inteiro 2 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iconst_2 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor inteiro 3 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iconst_3 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor inteiro 4 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iconst_4 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor inteiro 5 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iconst_5 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor long 0 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lconst_0 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor long 1 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lconst_1 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor float 0 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fconst_0 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor float 1 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fconst_1 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor float 2 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fconst_2 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor double 0 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dconst_0 (Frame * frame, JVM * jvm);

/// @brief Coloca o valor double 1 no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dconst_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um byte como um Int na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void bipush (Frame * frame, JVM * jvm);

/// @brief Coloca dois bytes como um Short na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void sipush (Frame * frame, JVM * jvm);

/// @brief Coloca um valor do constant pool na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ldc (Frame * frame, JVM * jvm);

/// @brief Coloca um valor do constant pool na pilha de operandos (wide index)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ldc_w (Frame * frame, JVM * jvm);

/// @brief Coloca um long ou double do constant pool na pilha de operandos (wide index)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ldc2_w (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iload (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lload (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fload (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dload (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void aload (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iload_0 (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iload_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iload_2 (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iload_3 (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lload_0 (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lload_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lload_2 (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lload_3 (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fload_0 (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fload_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fload_2 (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fload_3 (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dload_0 (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dload_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dload_2 (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dload_3 (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void aload_0 (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void aload_1 (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void aload_2 (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void aload_3 (Frame * frame, JVM * jvm);

/// @brief Coloca um valor inteiro de um array na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iaload (Frame * frame, JVM * jvm);

/// @brief Coloca um valor long de um array na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void laload (Frame * frame, JVM * jvm);

/// @brief Coloca um valor float de um array na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void faload (Frame * frame, JVM * jvm);

/// @brief Coloca um valor double de um array na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void daload (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência de um array na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void aaload (Frame * frame, JVM * jvm);

/// @brief Coloca um valor booleano ou byte de um array na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void baload (Frame * frame, JVM * jvm);

/// @brief Coloca um valor char de um array na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void caload (Frame * frame, JVM * jvm);

/// @brief Coloca um valor short de um array na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void saload (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void istore (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lstore (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fstore (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dstore (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void astore (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void istore_0 (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void istore_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void istore_2 (Frame * frame, JVM * jvm);

/// @brief Coloca um inteiro do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void istore_3 (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lstore_0 (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lstore_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lstore_2 (Frame * frame, JVM * jvm);

/// @brief Coloca um long do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lstore_3 (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fstore_0 (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fstore_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fstore_2 (Frame * frame, JVM * jvm);

/// @brief Coloca um float do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fstore_3 (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dstore_0 (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dstore_1 (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dstore_2 (Frame * frame, JVM * jvm);

/// @brief Coloca um double do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dstore_3 (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos (index 0)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void astore_0 (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos (index 1)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void astore_1 (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos (index 2)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void astore_2 (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência do vetor de variáveis locais na pilha de operandos (index 3)
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void astore_3 (Frame * frame, JVM * jvm);

/// @brief Coloca um valor inteiro num array 
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iastore (Frame * frame, JVM * jvm);

/// @brief Coloca um valor long num array 
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lastore (Frame * frame, JVM * jvm);

/// @brief Coloca um valor float num array
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fastore (Frame * frame, JVM * jvm);

/// @brief Coloca um valor double num array
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dastore (Frame * frame, JVM * jvm);

/// @brief Coloca uma referência num array
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void aastore (Frame * frame, JVM * jvm);

/// @brief Coloca um valor booleano ou byte num array
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void bastore (Frame * frame, JVM * jvm);

/// @brief Coloca um valor char num array
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void castore (Frame * frame, JVM * jvm);

/// @brief Coloca um short num array
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void sastore (Frame * frame, JVM * jvm);

/// @brief Tira um valor do topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void pop (Frame * frame, JVM * jvm);

/// @brief Tira um ou dois valores do topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void pop2 (Frame * frame, JVM * jvm);

/// @brief Duplica o topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dup (Frame * frame, JVM * jvm);

/// @brief Não implementado
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dup_x1 (Frame * frame, JVM * jvm);

/// @brief Não implementado
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dup_x2 (Frame * frame, JVM * jvm);

/// @brief Não implementado
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dup2 (Frame * frame, JVM * jvm);

/// @brief Não implementado
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dup2_x1 (Frame * frame, JVM * jvm);

/// @brief Não implementado
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dup2_x2 (Frame * frame, JVM * jvm);

/// @brief Não implementado
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void swap (Frame * frame, JVM * jvm);

/// @brief soma dois valores inteiros da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iadd (Frame * frame, JVM * jvm);

/// @brief soma dois valores long da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ladd (Frame * frame, JVM * jvm);

/// @brief soma dois valores float da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fadd (Frame * frame, JVM * jvm);

/// @brief  soma dois valores double da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dadd (Frame * frame, JVM * jvm);

/// @brief subtrai dois valores inteiros da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void isub (Frame * frame, JVM * jvm);

/// @brief subtrai dois valores long da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lsub (Frame * frame, JVM * jvm);

/// @brief subtrai dois valores float da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fsub (Frame * frame, JVM * jvm);

/// @brief subtrai dois valores double da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dsub (Frame * frame, JVM * jvm);

/// @brief multiplica dois valores inteiros da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void imul (Frame * frame, JVM * jvm);

/// @brief multiplica dois valores long da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lmul (Frame * frame, JVM * jvm);

/// @brief multiplica dois valores float da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fmul (Frame * frame, JVM * jvm);

/// @brief multiplica dois valores double da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dmul (Frame * frame, JVM * jvm);

/// @brief divide dois valores inteiros da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void idiv (Frame * frame, JVM * jvm);

/// @brief divide dois valores long da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ldiv (Frame * frame, JVM * jvm);

/// @brief divide dois valores float da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fdiv (Frame * frame, JVM * jvm);

/// @brief divide dois valores double da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ddiv (Frame * frame, JVM * jvm);

/// @brief calcula o resto da divisao de dois valores inteiros da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void irem (Frame * frame, JVM * jvm);

/// @brief calcula o resto da divisao de dois valores long da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lrem (Frame * frame, JVM * jvm);

/// @brief calcula o resto da divisao de dois valores float da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void frem (Frame * frame, JVM * jvm);

/// @brief calcula o resto da divisao de dois valores double da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void drem (Frame * frame, JVM * jvm);

/// @brief Nega um valor inteiro da pilha de operandos e coloca o resultado na pilha de operandos. para todo x inteiro retorna (~x) + 1. Ou seja, complemento de 2 de x
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ineg (Frame * frame, JVM * jvm);

/// @brief Negativa um valor long da pilha de operandos e coloca o resultado na pilha de operandos. para todo x long retorna (~x) + 1
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lneg (Frame * frame, JVM * jvm);

/// @brief Negativa um valor float da pilha de operandos e coloca o resultado na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fneg (Frame * frame, JVM * jvm);

/// @brief Negativa um valor double da pilha de operandos e coloca o resultado na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dneg (Frame * frame, JVM * jvm);

/// @brief faz o shift para a esquerda de um inteiro da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ishl (Frame * frame, JVM * jvm);

/// @brief faz o shift para a esquerda de um long da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lshl (Frame * frame, JVM * jvm);

/// @brief faz o shift aritmético para a direita de um inteiro da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ishr (Frame * frame, JVM * jvm);

/// @brief faz o shift aritmético para a direita de um long e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lshr (Frame * frame, JVM * jvm);

/// @brief Faz o shift lógico para a direita de um inteiro da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iushr (Frame * frame, JVM * jvm);

/// @brief faz o shift lógico para a direita de um long da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lushr (Frame * frame, JVM * jvm);

/// @brief faz o and bit a bit de dois inteiros da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iand (Frame * frame, JVM * jvm);

/// @brief faz o and bit a bit de dois longs da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void land (Frame * frame, JVM * jvm);

/// @brief faz o or bit a bit de dois inteiros da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ior (Frame * frame, JVM * jvm);

/// @brief faz o or bit a bit de dois longs da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lor (Frame * frame, JVM * jvm);

/// @brief faz o xor bit a bit de dois inteiros da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ixor (Frame * frame, JVM * jvm);

/// @brief faz o xor bit a bit de dois longs da pilha de operandos e coloca o resultado na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lxor (Frame * frame, JVM * jvm);

/// @brief Pega um inteiro do vetor de variaveis locais, incrementa por uma constante e coloca o resultado no vetor de variaveis locais
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iinc (Frame * frame, JVM * jvm);

/// @brief Converte um inteiro da pilha de operandos para um long e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void i2l (Frame * frame, JVM * jvm);

/// @brief converte um inteiro da pilha de operandos para um float e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void i2f (Frame * frame, JVM * jvm);

/// @brief converte um inteiro da pilha de operandos para um double e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void i2d (Frame * frame, JVM * jvm);

/// @brief converte um long da pilha de operandos para um inteiro e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void l2i (Frame * frame, JVM * jvm);

/// @brief converte um long da pilha de operandos para um float e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void l2f (Frame * frame, JVM * jvm);

/// @brief converte um long da pilha de operandos para um double e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void l2d (Frame * frame, JVM * jvm);

/// @brief converte um float da pilha de operandos para um inteiro e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void f2i (Frame * frame, JVM * jvm);

/// @brief converte um float da pilha de operandos para um long e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void f2l (Frame * frame, JVM * jvm);

/// @brief converte um float da pilha de operandos para um double e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void f2d (Frame * frame, JVM * jvm);

/// @brief converte um double da pilha de operandos para um inteiro e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void d2i (Frame * frame, JVM * jvm);

/// @brief converte um double da pilha de operandos para um long e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void d2l (Frame * frame, JVM * jvm);

/// @brief converte um double da pilha de operandos para um float e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void d2f (Frame * frame, JVM * jvm);

/// @brief converte um inteiro da pilha de operandos para um byte e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void i2b (Frame * frame, JVM * jvm);

/// @brief converte um inteiro da pilha de operandos para um char e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void i2c (Frame * frame, JVM * jvm);

/// @brief converte um inteiro da pilha de operandos para um short e salva na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void i2s (Frame * frame, JVM * jvm);

/// @brief Compara dois longs da pilha de operandos e coloca o resultado na pilha de operandos.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lcmp (Frame * frame, JVM * jvm);

/// @brief Compara dois floats da pilha de operandos e coloca o resultado na pilha de operandos. Coloca -1 se houver NaN.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fcmpl (Frame * frame, JVM * jvm);

/// @brief Compara dois floats da pilha de operandos e coloca o resultado na pilha de operandos. Coloca 1 se houver NaN.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void fcmpg (Frame * frame, JVM * jvm);

/// @brief Compara dois doubles da pilha de operandos e coloca o resultado na pilha de operandos. Coloca -1 se houver NaN.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dcmpl (Frame * frame, JVM * jvm);

/// @brief Compara dois doubles da pilha de operandos e coloca o resultado na pilha de operandos. Coloca 1 se houver NaN.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dcmpg (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o valor do topo da pilha de operandos for 0
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ifeq (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o valor do topo da pilha de operandos for diferente de 0
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ifne (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o valor do topo da pilha de operandos for menor que 0
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void iflt (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o valor do topo da pilha de operandos for maior ou igual a 0
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ifge (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o valor do topo da pilha de operandos for maior que 0
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ifgt (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o valor do topo da pilha de operandos for menor ou igual a 0
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ifle (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o primeiro valor inteiro for igual ao segundo valor inteiro
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void if_icmpeq (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o primeiro valor inteiro for diferente do segundo valor inteiro
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void if_icmpne (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o primeiro valor inteiro for menor que o segundo valor inteiro
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void if_icmplt (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o primeiro valor inteiro for maior ou igual ao segundo valor inteiro
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void if_icmpge (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o primeiro valor inteiro for maior que o segundo valor inteiro
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void if_icmpgt (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se o primeiro valor inteiro for menor ou igual ao segundo valor inteiro
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void if_icmple (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se os dois primeiro valores do topo da pilha de operandos forem referências iguais
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void if_acmpeq (Frame * frame, JVM * jvm);

/// @brief Pula para uma instrução se os dois primeiro valores do topo da pilha de operandos forem referências diferentes
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void if_acmpne (Frame * frame, JVM * jvm);

/// @brief Pula para um instrução
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void _goto (Frame * frame, JVM * jvm);

/// @brief Salva o pc atual em um returnAddress na pilha de operandos e pula para uma instrução
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void jsr (Frame * frame, JVM * jvm);

/// @brief Pega um returnAddress na pilha de operandos e pula para a instrução indicada por ele
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ret (Frame * frame, JVM * jvm);

/// @brief De acordo com o valor que está no topo da pilha de operandos, compara com os indices indicados no code e caso encontre o valor pula para uma instrução usando o offset correspondente
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void tableswitch (Frame * frame, JVM * jvm);

/// @brief De acordo com o valor que está no topo da pilha de operandos, compara com os pares de valor do code, e caso encontre o valor pula para uma instrução usando o offset correspondente
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lookupswitch (Frame * frame, JVM * jvm);

/// @brief Desempilha um inteiro da pilha de operandos, salva na pilha de operandos do frame que chamou o método atual e passa o fluxo de execução para o ele.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ireturn (Frame * frame, JVM * jvm);

/// @brief desempilha um long da pilha de operandos, salva na pilha de operandos do frame que chamou o método atual e passa o fluxo de execução para o ele.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void lreturn (Frame * frame, JVM * jvm);

/// @brief desempilha um float da pilha de operandos, salva na pilha de operandos do frame que chamou o método atual e passa o fluxo de execução para o ele.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void freturn (Frame * frame, JVM * jvm);

/// @brief desempilha um double da pilha de operandos, salva na pilha de operandos do frame que chamou o método atual e passa o fluxo de execução para o ele.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void dreturn (Frame * frame, JVM * jvm);

/// @brief desempilha uma referência da pilha de operandos, salva na pilha de operandos do frame que chamou o método atual e passa o fluxo de execução para o ele.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void areturn (Frame * frame, JVM * jvm);

/// @brief passa o fluxo de execução para o frame que chamou o método atual sem retornar nada.
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void _return (Frame * frame, JVM * jvm);

/// @brief Busca o valor de um field estático de acordo com o nome e coloca o valor no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void getstatic (Frame * frame, JVM * jvm);

/// @brief Atualiza o valor de um field estático de acordo com o nome e coloca o valor no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void putstatic (Frame * frame, JVM * jvm);

/// @brief Busca o valor de um field de um objeto de acordo com o nome e coloca o valor no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void getfield (Frame * frame, JVM * jvm);

/// @brief Atualiza o valor de um field de um objeto de acordo com o nome e o objeto de referência, e coloca o valor no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void putfield (Frame * frame, JVM * jvm);

/// @brief Insere um novo frame com o bloco do método de acordo com o nome e descritor do método, e coloca a referência no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void invokevirtual (Frame * frame, JVM * jvm);

/// @brief Insere um novo frame com o bloco do método de acordo com o nome, descritor do método e seu objeto de referência, e coloca a referência no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void invokespecial (Frame * frame, JVM * jvm);

/// @brief Insere um novo frame com o bloco do método estático de acordo com o nome e descritor do método e coloca a referência no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void invokestatic (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void invokeinterface (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void invokedynamic (Frame * frame, JVM * jvm);

/// @brief Cria um novo objeto de uma classe, coloca na heap e coloca a referência no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void _new (Frame * frame, JVM * jvm);

/// @brief Cria um novo array de referências com o tamanho especificado na pilha de operandos e coloca a referência no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void newarray (Frame * frame, JVM * jvm);

/// @brief Cria um novo array com o tamanho especificado na pilha de operandos, o tipo especificado no argumento e coloca a referência no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void anewarray (Frame * frame, JVM * jvm);

/// @brief Pega a referência de um array da pilha de operandos e coloca o seu tamanho na pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void arraylength (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void athrow (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void checkcast (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void instanceof (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void monitorenter (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void monitorexit (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void wide (Frame * frame, JVM * jvm);

/// @brief Cria um novo array multidimensional com os tamanhos especificados na pilha de operandos e coloca a referência no topo da pilha de operandos
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void multianewarray (Frame * frame, JVM * jvm);

/// @brief Checa se o valor no topo da pilha de operandos é null, se sim, pula para o endereço indicado pelo argumento no code
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ifnull (Frame * frame, JVM * jvm);

/// @brief Checa se o valor no topo da pilha de operandos não é null, se sim, pula para o endereço indicado pelo argumento no code
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void ifnonnull (Frame * frame, JVM * jvm);

/// @brief Pula para o endereço indicado pelo argumento no code
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void goto_w (Frame * frame, JVM * jvm);

/// @brief Salva o próximo endereço de retorno na pilha de operandos e pula para o endereço indicado pelo argumento no code
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void jsr_w (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void breakpoint (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void impdep1 (Frame * frame, JVM * jvm);

/// @brief Não implementada
/// @param frame Ponteiro para o Frame sendo executado
/// @param jvm Ponteiro para a JVM
void impdep2 (Frame * frame, JVM * jvm);

