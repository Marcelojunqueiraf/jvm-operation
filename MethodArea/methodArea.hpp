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

};


class MethodArea {
  private:
    vector<MethodAreaItem *> data; // vetor de classes e interfaces
  public:
    MethodArea();
    void insert (ClassFile * classfile);
    MethodAreaItem * getMethodAreaItem (string className);
};

#endif