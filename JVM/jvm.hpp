/**
 * @file classfile.hpp
 * @author Marcelo Piano
 * @author Marcelo Junqueira
 * @author Gabriel Borges
 * @author Maycon Vinnicyus
 * @author Edson Sales
 * @brief Arquivo com as classes e funções utilizadas na execução da JVM
*/

#pragma once

#include "../common/index.hpp"
#include <stack>
#include "../FrameStack/frameStack.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../Heap/heap.hpp"
#include "../Instruction/instructions.hpp"
#include "../exibidor/exibidor.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class JVM;

/// @brief Função que retorna o atributo code do método informado
/// @param method_info Ponteiro para o method_info que contem as informações do método
/// @param methodAreaItem Ponteiro para o methodAreaItem que contem as informações sobre o método na área de métodos
code_attribute * getCode(Method_info * method_info, MethodAreaItem * methodAreaItem);

/// @brief Vetor que armazena ponteiros para as funções de cada instrução da JVM
typedef vector <void(*)(Frame *, JVM *)> InstructionsMap;

/// @brief Classe que define a estrutura da JVM
class JVM {
  private:
    /// @brief Pilha de frames
    FrameStack frameStack;
    /// @brief Heap
    Heap heap;
    /// @brief Área de métodos
    MethodArea methodArea;
    /// @brief Vetor de ponteiros para as funções de cada instrução
    InstructionsMap instructionsMap;
    /// @brief Função que executa o frame passado
    /// @param frame Ponteiro para o frame que será executado
    void executeFrame(Frame * frame);
    /// @brief Função que executa a instrução contida no frame passado
    /// @param instruction Ponteiro para o opcode da instrução
    /// @param frame Ponteiro para o frame que contem a instrução
    void executeInstruction(u1 * instruction, Frame * frame);

  public:
    /// @brief Instanciador de classe
    JVM();
    /// @brief Função que inicia a execução da JVM a partir do .class informado
    /// @param classPath Caminho para o .class que irá iniciar a execução da JVM
    void initialize(string classPath);
    /// @brief Função que chama o exibidor para o .class informado
    /// @param classPath Caminho para o .class que será exibido
    void showClass(string classPath);
    /// @brief Função que realiza a execução dos frames da JVM
    void run();

    /// @brief Função que coloca um novo frame na pilha de frames
    /// @param frame Frame a ser colocado na pilha
    void invoke(Frame frame);
    /// @brief Função que encerra um frame sem retorno de valor
    void returnVoid();
    /// @brief Função que encerra um frame com retorno de valor
    /// @param value Valor que será empilhado na pilha de operandos do frame imediatamente abaixo
    void returnValue(JvmValue value);
    
    /// @brief Função que coloca um novo objeto no vetor de objetos
    /// @param heapItem Objeto a ser colocado
    /// @return Tamanho do vetor de objetos como u4
    u4 pushObject(Object * heapItem);
    /// @brief Função que coloca um novo array no vetor de arrays
    /// @param arrayItem Array a ser colocado
    /// @return Tamanho do vetor de arrays como u4    
    u4 pushArray(Array * arrayItem);

    /// @brief Função que retorna um field dinâmico a partir de seu nome e índice no vetor de objetos
    /// @param heapItemIndex Índice para o vetor de objetos
    /// @param fieldName Nome do field
    /// @return Dados do field
    JvmValue getField(u4 heapItemIndex, string fieldName);
    /// @brief Função que retorna um field estático a partir de seu nome e de sua classe na área de métodos
    /// @param classname Nome da classe que contém o field estático
    /// @param fieldName Nome do field
    /// @return Dados do field
    JvmValue getStaticField(string classname, string fieldName);

    /// @brief Função que retorna um elemento do array informado 
    /// @param arrayItemIndex Índice para o vetor de arrays na heap
    /// @param index Índice para o elemento contido no array coletado
    /// @return Elemento do array
    JvmValue getArrayValue(u4 arrayItemIndex, u4 index);
    /// @brief Função que define o valor de um elemento do array informado
    /// @param arrayItemIndex Índice para o vetor de arrays na heap
    /// @param index Índice para o elemento contido no array coletado
    /// @param value Valor a ser definido
    void setArrayValue(u4 arrayItemIndex, u4 index, JvmValue value);
    /// @brief Função que retorna o tamanho de um array
    /// @param arrayItemIndex Índice para o vetor de arrays na heap
    /// @return Tamanho do array
    u4 getArraySize(u4 arrayItemIndex);

    /// @brief Função que define o valor de um field dinâmico a partir de seu nome e índice no vetor de objetos
    /// @param heapItemIndex Índice para o vetor de objetos
    /// @param fieldName Nome do field
    /// @param value Valor do field
    void setField(u4 heapItemIndex, string fieldName, JvmValue value);
    /// @brief Função que define o valor de um field estático a partir de seu nome e de sua classe na área de métodos
    /// @param classname Nome da classe que contem o field estático
    /// @param fieldName Nome do field
    /// @param value Valor do field
    void setStaticField(string classname, string fieldName, JvmValue value);
};
