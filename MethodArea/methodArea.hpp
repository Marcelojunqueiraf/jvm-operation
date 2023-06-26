#include "../common/index.hpp"
#include "class-file.hpp"
#include <string>
#include <vector>
#include <algorithm>

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


#endif