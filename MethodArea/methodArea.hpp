/**
 * @file classfile.hpp
 * @author Marcelo Piano
 * @author Marcelo Junqueira
 * @author Gabriel Borges
 * @author Maycon Vinnicyus
 * @author Edson Sales
 * @brief Arquivo com as classes e funções utilizadas na área de métodos
*/

#pragma once

#include "../common/index.hpp"
#include "../leitor/index.hpp"
#include "../FrameStack/frameStack.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class MethodArea;
class FrameStack;

/// @brief Classe que representa um item da área de métodos, contendo as informações de uma classe
class MethodAreaItem {
  private:
  /// @brief Ponteiro para o classfile lido que contém as informações da classe
  ClassFile * classfile;
  /// @brief Hashmap que contém os fields estáticos da classe, onde a chave é o nome do field e o valor é o valor do field
  map <string, JvmValue> staticFields;
  /// @brief Ponteiro para a área de métodos
  MethodArea * methodArea;
  public:
  /// @brief Instanciador de classe
  /// @param classfile Ponteiro para o classfile lido que contém as informações da classe
  /// @param methodArea Ponteiro para a área de métodos
  MethodAreaItem(ClassFile * classfile, MethodArea * methodArea);

  /// @brief Retorna o nome da classe lido da constant pool
  /// @return String com o nome da classe
  string getClassName();

  /// @brief Retorna o cp_info da constant pool naquele index
  /// @param index Index da constant pool
  /// @return Ponteiro para o cp_info da constant pool
  cp_info * getConstantPoolItem(u2 index); 
  /// @brief Retorna a method area
  /// @return Ponteiro para a method area
  MethodArea * getMethodArea();
  /// @brief Retorna todos os fields da classe, com as informações de cada um
  /// @return Vetor com todos os fields da classe
  vector<field_info> getFieldInfos();
  /// @brief Obtém o nome da superclasse da classe
  /// @return String com o nome da superclasse
  string getSuper();
  /// @brief Obtém o nome relacionado ao index da constant pool, de forma iterativa acessando o name_index do cp_info
  /// @param index Index da constant pool
  /// @return String com o nome relacionado ao index da constant pool
  string getUtf8(u2 index);
  
  /// @brief Obtém o método main da classe
  /// @return Ponteiro para o method_info do método main
  /// @throws Caso não encontre o método main
  Method_info * getMainMethod();
  /// @brief Obtém o método init da classe
  /// @param descriptor Descritor do método
  /// @return Ponteiro para o method_info do método init
  /// @throws Caso não encontre o método init
  Method_info * getInitMethod(string descriptor);
  /// @brief Obtém o método estático da classe
  /// @return Ponteiro para o method_info do método estático
  /// @throws Caso não encontre o método estático
  Method_info * getStaticBlock();
  /// @brief Obtém o método da classe pelo nome e descritor
  /// @param methodName Nome do método
  /// @param descriptor Descritor do método
  /// @param onlyActualClass Flag que indica se deve procurar apenas na classe atual ou nas superclasses também
  /// @return Ponteiro para o method_info do método
  Method_info * getMethodByName(string methodName, string descriptor, bool onlyActualClass = false);
  /// @brief Obtém o method area item da classe pelo nome e descritor, útil quando o método faz parte de uma classe diferente da atual (super)
  /// @param methodName Nome do método
  /// @param descriptor Descritor do método
  /// @return Ponteiro para o method area item da classe que contém o método
  /// @throws Caso não encontre o method area item
  MethodAreaItem * getMethodItemByMethodName(string methodName, string descriptor);

  /// @brief Obtém o field da classe pelo nome
  /// @param fieldName Nome do field
  /// @return JvmValue com o valor do field
  /// @throws Caso não encontre o field
  JvmValue getStaticField(string fieldName);
  /// @brief Define o valor do field da classe pelo nome
  /// @param fieldName Nome do field
  /// @param value Valor do field
  /// @throws Caso não encontre o field
  void setStaticField(string fieldName, JvmValue value);

  /// @brief Parseia o descritor do método e retorna um vetor com os tipos dos argumentos, pelo index do descritor
  /// @example (Ljava/lang/String;I[C)V retorna { "Ljava/lang/String;", "INT", "CHAR[]" }
  /// @param descriptorIndex Index do descritor do field
  /// @param isField Flag que indica se o descritor é de um field ou de um método, para caso seja de um field, não considerar o tipo de retorno
  /// @return Vetor com os tipos dos argumentos, incluindo o tipo de retorno na última posição caso não seja um field
  vector<string> getMethodArgTypesByDescriptorIndex(u2 descriptorIndex, bool isField = false);

  /// @brief Parseia o descritor do método e retorna um vetor com os tipos dos argumentos, pelo name_and_type_index
  /// @example (Ljava/lang/String;I[C)V retorna { "Ljava/lang/String;", "INT", "CHAR[]" }
  /// @param index Index do descritor do field
  /// @param isField Flag que indica se o descritor é de um field ou de um método, para caso seja de um field, não considerar o tipo de retorno 
  /// @return Vetor com os tipos dos argumentos, incluindo o tipo de retorno na última posição caso não seja um field
  vector<string> getMethodArgTypesByNameAndTypeIndex(u2 nameAndTypeIndex, bool isField = false);
};

/// @brief Classe que representa a área de métodos, contendo as informações de todas as classes carregadas
class MethodArea {
  private:
    /// @brief Pilha de frames
    FrameStack * frameStack;
    /// @brief Vetor de ponteiros para os method area items
    vector<MethodAreaItem *> methodItems;
    /// @brief Lê a classe informada, é esperado que o nome da classe seja o nome do arquivo e esteja dentro da pasta `tests`
    /// @param className Nome da classe a ser lida
    /// @return Ponteiro para o classfile lido
    ClassFile * loadClass(string className);
    /// @brief Insere um method area item no vetor de method area
    /// @param methodAreaItem Ponteiro para o method area item a ser inserido
    void insert (MethodAreaItem * methodAreaItem);
  public:
    /// @brief Instanciador de classe
    MethodArea();
    /// @brief Instanciador de classe
    /// @param frameStack Ponteiro para a pilha de frames
    MethodArea(FrameStack * frameStack);

    /// @brief Insere o método estático da classe na pilha de frames, caso exista, e faz o mesmo para os métodos estáticos das superclasses
    /// @param methodAreaItem Ponteiro para o method area item da classe
    void pushStaticBlock(MethodAreaItem * methodAreaItem);

    /// @brief Lê a classe informada de acordo com o caminho informado
    /// @param className Caminho para a classe a ser lida
    /// @return Ponteiro para o classfile lido
    /// @throws Caso não encontre o arquivo
    ClassFile * loadClassFromPath(string path);

    /// @brief Obtém o method area item da classe pelo nome da classe, caso não encontre, tenta encontrar o arquivo na pasta `tests`, e caso encontrada lê a classe e retorna o method area item correspondente. E insere o bloco estático da classe e das superclasses
    /// @param className Nome da classe
    /// @return Ponteiro para o method area item da classe
    MethodAreaItem * getMethodAreaItem (string className);
    /// @brief Obtém o method area item da classe pelo caminho
    /// @param path Caminho para o arquivo da classe
    /// @return Ponteiro para o method area item da classe
    /// @throws Caso não encontre o arquivo
    MethodAreaItem * getMethodAreaItemFromFile(string path);
};

/// @brief Função auxiliar que retorna o tipo do argumento no descritor do método, pelo index da string do descritor. É usada pelo método `getMethodArgTypesByDescriptorIndex`
/// @param signature String do descritor do método
/// @param index Index do argumento
/// @return Pair com o tipo do argumento e o quanto deve ser incrementado no index para obter o próximo argumento
pair<string, int> getArgType(string signature, int index);
/// @brief Função auxiliar que cria um JVM Value com um valor default, de acordo com o descritor
/// @param descriptor Descritor com o tipo do valor
/// @return JvmValue com o valor default
/// @throws Caso o descritor não seja válido ou não suportado
JvmValue createInitialField(string descriptor);
