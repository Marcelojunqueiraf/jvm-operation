#include "jvm.hpp"


ClassFile * leitor (string path) {
  // string to char pointer
/*
  std::fstream file;
  file.open(path, std::ios::in); 
  if (!file.is_open()) {
    std::cout << "Erro ao abrir o arquivo" << endl;
    return NULL;
  }
  */
  return new ClassFile();
}

ClassFile * JVM::loadClassFromFile(string path) {
  ClassFile * classFile = leitor(path);
  return classFile;
}

void JVM::loadClass() {
  ClassFile * classFile = new ClassFile();
  this->methodArea.insert(classFile);
  MethodAreaItem * classe =  this->methodArea.getMethodAreaItem("className");
  std::cout << classe->getClassName() << endl;
  
  /*
  MethodAreaItem * methodAreaItem = new MethodAreaItem();
  ClassFile * classFile = loadClassFromFile("path");
  methodAreaItem->classfile = classFile;
  this->methodArea.insert(methodAreaItem);
  */
  // ver se já tem no methodArea. Se sim, retorne a referência
  // se não, carregue do arquivo e insira no methodArea
  // fazer load de todas as classes que forem referenciadas
}

void JVM::initialize(string classPath) {
  ClassFile * classFile = loadClassFromFile(classPath);
  this->methodArea.insert(classFile);

  // this->frameStack.push(this->methodArea.getMainMethod());
}

void JVM::run() {
  // while (this->frameStack.getStackSize() > 0) {
  //   this->frameStack.executeFrame();
  // }
}