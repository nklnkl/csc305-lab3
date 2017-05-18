#include <iostream>
#include "process.cpp"

using namespace std;

int main () {
  cout << endl;

  Process process;
  process.setNumber(1);
  cout << "Process @ " << & process << ", number: " << process.getNumber();

  cout << endl;
  return 0;
}
