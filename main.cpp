#include "./common/index.hpp"
#include "./JVM/jvm.hpp"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
  JVM * jvm = new JVM();
  jvm->initialize(argv[1]);
  jvm->run();
  return 0;
}