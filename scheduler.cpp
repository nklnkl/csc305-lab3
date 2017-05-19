#include <vector>
#include <iostream>
#include "process.cpp"
using namespace std;

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler {
public:
  Scheduler ();
  ~Scheduler ();
  void schedule (int, std::vector<Process>);
private:
  std::vector<Process> queue;
  void fcfs (std::vector<Process>);
  void sjn (std::vector<Process>);
  void priority (std::vector<Process>);
};

#endif

Scheduler::Scheduler () {
  return;
}
Scheduler::~Scheduler () {
  return;
}

/* int algorithm - 0: first come first serve, 1: shortest job next, 2: priority */
void Scheduler::schedule (int algorithm, std::vector<Process> processes) {
  queue.clear();
  queue.swap(queue);
  cout << "Address of incoming processes: " << & processes;
  switch (algorithm) {
    case 0:
      fcfs (processes);
      break;
    case 1:
      sjn (processes);
      break;
    case 2:
      priority (processes);
      break;
    default:
      fcfs (processes);
  }
  return;
}

void Scheduler::fcfs (std::vector<Process> processes) {
  return;
}
void Scheduler::sjn (std::vector<Process> processes) {
  return;
}
void Scheduler::priority (std::vector<Process> processes) {
  return;
}
