#include "./common/index.hpp"
#include <iostream>
#include <stack>
#include "./FrameStack/frameStack.hpp"
#include "./MethodArea/methodArea.hpp"
#include "./Heap/heap.hpp"
using namespace std;



class JVM {
  private:
    FrameStack frameStack;
    Heap heap;
    MethodArea methodArea;
    void * pc;
  public:
    void initialize(string classPath);
    void run();
};


int main(int argc, char const *argv[])
{
  JVM * jvm = new JVM();
  jvm->initialize(argv[1]);
  jvm->run();
  return 0;
}