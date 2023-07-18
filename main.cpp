#include "./common/index.hpp"
#include "./JVM/jvm.hpp"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
  // TODO: lógica de flags
  if (argc < 2 || argc > 3 || (argc == 3 && string(argv[2]) != "-r")) {
    cout << "Correct use: ./jvm <class-path> <only-read-flag>" << endl;
    cout << "only-read-flag: -r (optional)" << endl;
    return 1;
  }

  DCOUT << "----- JVM -----" << endl;
  JVM * jvm = new JVM();

  if (argc == 3) {
    DCOUT << "----- Showing Class -----" << endl;
    jvm->showClass(argv[1]);
    return 0;
  }

  DCOUT << "----- Initializing JVM -----" << endl;
  jvm->initialize(argv[1]);
  DCOUT << "------- Running JVM --------" << endl;
  jvm->run();
  DCOUT << "------ Finishing JVM -------" << endl;
  return 0;
}
