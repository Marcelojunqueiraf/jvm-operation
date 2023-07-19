/**
 * @file classfile.hpp
 * @author Marcelo Piano
 * @author Marcelo Junqueira
 * @author Gabriel Borges
 * @author Maycon Vinnicyus
 * @author Edson Sales
 * @brief Arquivo com as classes e funções utilizadas no heap
*/

#pragma once

#include "../common/index.hpp"
#include "../MethodArea/methodArea.hpp"
#include "../FrameStack/frameStack.hpp"

/// @brief Classe que define a estrutura de um objeto no heap
class Object {
  private:
    /// @brief Informações sobre aos fields dinâmicos associados 
    map<string, JvmValue> fields;
    /// @brief Ponteiro para o methodAreaItem associado
    MethodAreaItem * methodAreaItem;
    /// @brief Ponteiro para a super classe associada
    Object * super;
  public:
    /// @brief Instanciador de classe
    /// @param methodAreaItem Ponteiro para o methodAreaItem associado
    Object(MethodAreaItem * methodAreaItem);
    /// @brief Função que retorna os dados do field requerido
    /// @param fieldName Nome do field
    /// @return Dados do field
    JvmValue getFieldValue(string fieldName);
    /// @brief Função que define um novo field associado ao objeto
    /// @param fieldName Nome do field
    /// @param value Dados do field
    void setFieldValue(string fieldName, JvmValue value);
};

/// @brief Classe que define a estrutura de um array no heap
class Array {
  private:
    /// @brief Vetor com os elementos que serão armazenados no array
    vector<JvmValue> array;
    /// @brief Tipo dos elementos que serão armazenados no array
    JVMType type; 
  public:
    /// @brief Instanciador de classe
    /// @param type Tipo dos elementos
    /// @param size Tamanho do array
    Array(JVMType type, u4 size);
    /// @brief Função que retorna um elemento do array através de um índice passado
    /// @param index Índice do array
    /// @return Elemento armazenado no índice passado
    JvmValue getArrayValue(u4 index);
    /// @brief Função que retorna o tamanho do array
    /// @return Tamanho como int32_t
    int32_t getArraySize();
    /// @brief Função que coloca o elemento passado no índice informado
    /// @param index Índice do array
    /// @param value Elemento a ser colocado no array
    void setArrayValue(u4 index, JvmValue value);
};

/// @brief Classe que define a estrutura do heap
class Heap {
  private:
    /// @brief Vetor que armazena os objetos instanciados
    vector<Object *> heapItems;
    /// @brief Vetor que armazena os arrays criados
    vector<Array *> arrayItems;
  public:
    /// @brief Instanciador de classe
    Heap();
    /// @brief Função que retorna um ponteiro para o objeto armazenado no índice informado
    /// @param index Índice para o vetor de objetos
    /// @return Ponteiro para o objeto
    Object * getHeapItem(u4 index);
    /// @brief Função que coloca um objeto instanciado no vetor de objetos e retorna seu tamanho
    /// @param heapItem Objeto a ser colocado no vetor de objetos
    /// @return Tamanho do vetor de objetos como u4
    u4 pushHeapItem(Object * heapItem);
    /// @brief Função que retorna um ponteiro para o array armazenado no índice informado
    /// @param index Índice para o vetor de arrays
    /// @return Ponteiro para o array
    Array * getArrayItem(u4 index);
    /// @brief Função que coloca um array criado no vetor de arrays e retorna seu tamanho
    /// @param arrayItem Array a ser colocado no vetor de arrays
    /// @return Tamanho do vetor de arrays como u4    
    u4 pushArrayItem(Array * arrayItem);
};
