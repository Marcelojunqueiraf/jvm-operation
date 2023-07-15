#ifndef METHOD_AREA_H
#define METHOD_AREA_H

#include "../common/index.hpp"
#include "../leitor/index.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class MethodArea;

class MethodAreaItem {
  private:
  ClassFile * classfile;
  map <string, JvmValue> staticFields;
  MethodArea * methodArea;
  public:
  MethodAreaItem(ClassFile * classfile, MethodArea * methodArea);
  string getClassName();
  Method_info * getMainMethod();
  Method_info * getInitMethod();
  Method_info * getStaticBlock();
  Method_info * getMethodByName(string name);
  cp_info * getConstantPoolItem(u2 index); 
  string getSuper();
  string getUtf8(u2 index);
  MethodArea * getMethodArea();
  vector<string> getMethodArgTypesByDescriptorIndex(u2 descriptorIndex, bool isField = false);
  vector<string> getMethodArgTypesByNameAndTypeIndex(u2 index, bool isField = false);
};

class MethodArea {
  private:
    vector<MethodAreaItem *> methodItems;
    // tabela de nomes e paths aqui
    ClassFile * loadClass(string className);
    ClassFile * loadClassFromPath(string className);
    void insert (MethodAreaItem * methodAreaItem);
  public:
    MethodAreaItem * getMethodAreaItem (string className);
    MethodAreaItem * getMethodAreaItemFromFile(string path);
};

pair<string, int> getArgType(string signature, int index);
int getArgSize(PrimitiveType argType);
int getArgSize(string argType);


#endif
