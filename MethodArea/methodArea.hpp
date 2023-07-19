#ifndef METHOD_AREA_H
#define METHOD_AREA_H

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

class MethodAreaItem {
  private:
  ClassFile * classfile;
  map <string, JvmValue> staticFields;
  MethodArea * methodArea;
  public:
  MethodAreaItem(ClassFile * classfile, MethodArea * methodArea);

  string getClassName();
  cp_info * getConstantPoolItem(u2 index); 
  MethodArea * getMethodArea();
  vector<field_info> getFieldInfos();
  string getSuper();
  string getUtf8(u2 index);
  
  Method_info * getMainMethod();
  Method_info * getInitMethod(string descriptor);
  Method_info * getStaticBlock();
  Method_info * getMethodByName(string methodName, string descriptor, bool onlyActualClass = false);
  MethodAreaItem * getMethodItemByMethodName(string methodName, string descriptor);

  JvmValue getStaticField(string fieldName);
  void setStaticField(string fieldName, JvmValue value);

  vector<string> getMethodArgTypesByDescriptorIndex(u2 descriptorIndex, bool isField = false);
  vector<string> getMethodArgTypesByNameAndTypeIndex(u2 index, bool isField = false);
};

class MethodArea {
  private:
    FrameStack * frameStack;
    vector<MethodAreaItem *> methodItems;
    // tabela de nomes e paths aqui
    ClassFile * loadClass(string className);
    void insert (MethodAreaItem * methodAreaItem);
  public:
    MethodArea();
    MethodArea(FrameStack * frameStack);

    void pushStaticBlock(MethodAreaItem * methodAreaItem);

    ClassFile * loadClassFromPath(string className);

    MethodAreaItem * getMethodAreaItem (string className);
    MethodAreaItem * getMethodAreaItemFromFile(string path);
};

pair<string, int> getArgType(string signature, int index);
JvmValue createInitialField(string descriptor);

#endif
