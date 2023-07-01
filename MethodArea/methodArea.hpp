#include "../common/index.hpp"
#include "../leitor/index.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#ifndef METHOD_AREA_H
#define METHOD_AREA_H

using namespace std;


class MethodAreaItem {
  private:
  ClassFile * classfile;
  map <string, JvmValue> staticFields;
  public:
  MethodAreaItem(ClassFile * classfile);
  string getClassName();
  Method_info * getMainMethod();
  Method_info * getStaticBlock();
  Method_info * getMethodByName(string name);
  cp_info * getConstantPoolItem(u2 index); 
  string getSuper();
  string getUtf8(u2 index);
};

class MethodArea {
  private:
    vector<MethodAreaItem *> data;
    // tabela de nomes e paths aqui
    ClassFile * loadClass(string className);
    ClassFile * loadClassFromPath(string className);
    void insert (MethodAreaItem * methodAreaItem);
  public:
    MethodAreaItem * getMethodAreaItem (string className);
    MethodAreaItem * getMethodAreaItemFromFile(string path);
};

// função que pega os arr de paths e cria um name_and_path map
// ["path1", "path2", "path3", ...]
/// @brief Função que pega um vetor com paths e cria um map [nome(chave), path] 



#endif