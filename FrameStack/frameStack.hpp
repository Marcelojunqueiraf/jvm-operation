/**
 * @file classfile.hpp
 * @author Marcelo Piano
 * @author Marcelo Junqueira
 * @author Gabriel Borges
 * @author Maycon Vinnicyus
 * @author Edson Sales
 * @brief Arquivo com as classes e funções utilizadas na pilha de frames
*/

#pragma once

#include "../common/index.hpp"
#include "../MethodArea/methodArea.hpp"
#include <stack>
#include <vector>

using namespace std;
class MethodAreaItem;

/// @brief Classe que define a estrutura de um frame
struct Frame {
  /// @brief Pilha de operandos do frame
  stack<JvmValue> operandStack;
  /// @brief Vetor de variáveis locais do frame
  vector<JvmValue> localVariables;
  /// @brief Ponteiro para o method_info que fornece as informações do método associado
  Method_info * method_info;
  /// @brief Ponteiro para o methodAreaItem que fornece as informações contidas na área de métodos do método associado
  MethodAreaItem * methodAreaItem;
  /// @brief Contador de programa do frame
  int pc;
  /// @brief Instanciador de classe
  /// @param method_info Ponteiro para o method_info do método associado
  /// @param methodAreaItem Ponteiro para o methodAreaItem do método associado
  Frame(Method_info * method_info, MethodAreaItem * methodAreaItem);
  /// @brief Função que retira o último elemento da pilha de operandos
  /// @return Item retirado da pilha
  JvmValue popOperandStack();
  /// @brief Função que coloca um item no final da pilha de operandos
  /// @param value Item que será colocado na pilha
  void pushOperandStack(JvmValue value);
};

/// @brief Classe que manipula a pilha de frames
class FrameStack
{
private:
  /// @brief Pilha de frames
  static stack<Frame> data;
public:
  /// @brief Instanciador de classe
  FrameStack();
  /// @brief Retira o útimo frame da pilha
  void pop();
  /// @brief Retorna último frame da pilha sem retirar
  /// @return Ponteiro para o frame
  Frame * top();
  /// @brief Coloca o frame passado na pilha
  /// @param frame Frame que será colocado na pilha de frames
  void push(Frame frame);
  /// @brief Retorna o tamanho de pilha de frames
  /// @return Tamanho da pilha de frames como int
  int getStackSize(); 
  // criar invoke 
};