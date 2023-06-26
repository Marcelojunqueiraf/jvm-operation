#include "../common/index.hpp"
#include "../piano-reader/index.hpp"
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
  public:
  MethodAreaItem(ClassFile * classfile);
  string getClassName();
  Method_info * getMainMethod();
  Method_info * getStaticBlock();
  string getSuper();
};

class MethodArea {
  private:
    vector<MethodAreaItem *> data;
    // tabela de nomes e paths aqui
    ClassFile * loadClass(string className);
    ClassFile * loadClassFromPath(string className);
    void insert (MethodAreaItem * methodAreaItem);
    map<string, string> name_and_path;
    map<string, string> path_to_name_and_path(char * path_arr);
  public:
    MethodAreaItem * getMethodAreaItem (string className);
    MethodAreaItem * getMethodAreaItemFromFile(string path);
};

// função que pega os arr de paths e cria um name_and_path map
// ["path1", "path2", "path3", ...]
/// @brief Função que pega um vetor com paths e cria um map [nome(chave), path] 



#endif