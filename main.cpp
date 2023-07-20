#include "./common/index.hpp"
#include "./JVM/jvm.hpp"
#include <iostream>
using namespace std;

bool DEBUG = false;

int main(int argc, char const *argv[])
{
  if (argc < 2) {
    cout << "Correct use: ./jvm <class-path> [flag]" << endl;
    cout << "flags: \n-leitor (leitor-exibidor) \n-debug (execução com debug) \nsem flag: execucao normal" << endl;
    return 1;
  }
  // caso leitor-exibidor
  if (argc == 3 && string(argv[2]) == "-leitor") {
    cout << "----- Leitor exibidor -----" << endl;
    JVM * jvm = new JVM();
    jvm->showClass(argv[1]);
    return 0;
  }
  
  if (argc == 3 && string(argv[2]) == "-debug")
    DEBUG = true;

  DCOUT << "----- JVM -----" << endl;
  JVM * jvm = new JVM();
  DCOUT << "----- Initializing JVM -----" << endl;
  jvm->initialize(argv[1]);
  DCOUT << "------- Running JVM --------" << endl;
  jvm->run();
  DCOUT << "------ Finishing JVM -------" << endl;
  return 0;
}
