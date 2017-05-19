#include <vector>
#include "process.cpp"
using namespace std;

#ifndef SCHEDULER
#define SCHEDULER

class Scheduler {
public:
  Scheduler ();
  ~Scheduler ();
  void schedule (int, std::vector<Process>);
  Process get (int);
  int getSize ();
private:
  std::vector<Process> queue;
  Process nullProcess;
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

Process Scheduler::get (int i) {
  if (i < 0 || i > queue.size()) return nullProcess;
  return queue.at(i);
}

int Scheduler::getSize () {
  return queue.size();
}

/* int algorithm - 0: first come first serve, 1: shortest job next, 2: priority */
void Scheduler::schedule (int algorithm, std::vector<Process> processes) {
  queue.clear();
  queue.swap(queue);
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
  // Loop to add processes.
  int processesSize = processes.size();
  for (int i = 0; i < processesSize; i++) {

    int earliest = -1;
    // Loop to find earliest process.
    for (int j = 0; j < processes.size(); j++) {
      // If we just started or if the current process has earlier arrival time then the previous earliest.
      if (earliest == -1 || processes.at(j).getArrivalTime() < processes.at(earliest).getArrivalTime())
        earliest = j;
    }

    int waitTime;
    int startTime;
    int endTime;
    int turnaround;

    /*  If first process, it becomes zero.
        Wait Time = Previous process end time - arrival time.
        If negative, it becomes zero.
    */
    if (i == 0) waitTime = 0;
    else {
      waitTime = queue.at(i - 1).getEndTime() - processes.at(earliest).getArrivalTime();
      if (waitTime < 0) waitTime = 0;
    }

    /*  If first process, it is zero.
        Start time = arrival time + wait time.
    */
    if (i == 0) startTime = 0;
    else {
      startTime = processes.at(earliest).getArrivalTime() + waitTime;
    }

    /* End time = start time + burst time. */
    endTime = startTime + processes.at(earliest).getBurstTime();

    /* Turnaround time = end time - arrival time. */
    turnaround = endTime - processes.at(earliest).getArrivalTime();

    processes.at(earliest).setStartTime(startTime);
    processes.at(earliest).setEndTime(endTime);
    processes.at(earliest).setWaitTime(waitTime);
    processes.at(earliest).setTurnaround(turnaround);

    // Add to queue, remove from pending list.
    queue.push_back( processes.at(earliest) );
    processes.erase( processes.begin() + earliest );
  }
  return;
}
void Scheduler::sjn (std::vector<Process> processes) {
  return;
}
void Scheduler::priority (std::vector<Process> processes) {
  return;
}
