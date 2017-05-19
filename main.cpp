#include <iostream>
#include "scheduler.cpp"

using namespace std;

int main () {
  cout << endl;

  Process process;
  process.setNumber(1);
  cout << "Process @ " << & process << ", number: " << process.getNumber();
  
  cout << endl;

  Scheduler scheduler;
  std::vector<Process> queue;
  queue.push_back(process);
  scheduler.schedule(0, queue);

  cout << endl;
  return 0;
}
