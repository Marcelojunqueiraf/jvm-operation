#include "./common/index.hpp"
#include "./JVM/jvm.hpp"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
  // lógica de flags
  if(argc < 2) {
    cout << "Correct use: ./jvm <class-path>" << endl;
    return 1;
  }
  //cout << "Creating JVM" << endl;
  JVM * jvm = new JVM();
  cout << "Initializing JVM" << endl;
  jvm->initialize(argv[1]);
  cout << "Running JVM" << endl;
  jvm->run();
  cout << "Finishing JVM" << endl;
  return 0;
}