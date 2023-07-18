#include "./common/index.hpp"
#include "./JVM/jvm.hpp"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
  // TODO: lógica de flags
  if(argc < 2) {
    cout << "Correct use: ./jvm <class-path>" << endl;
    return 1;
  }


  DCOUT << "----- JVM -----" << endl;
  JVM * jvm = new JVM();

  DCOUT << "----- Showing Class -----" << endl;
  jvm->showClass(argv[1]);
  return 0;

  DCOUT << "----- Initializing JVM -----" << endl;
  jvm->initialize(argv[1]);
  DCOUT << "------- Running JVM --------" << endl;
  jvm->run();
  DCOUT << "------ Finishing JVM -------" << endl;
  return 0;
}
