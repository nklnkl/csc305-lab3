#include <vector>
#include <iostream>
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
  float getAverageTurnaround ();
private:
  std::vector<Process> queue;
  Process nullProcess;
  void fcfs (std::vector<Process>);
  void sjn (std::vector<Process>);
  void priority (std::vector<Process>);
  void calculateTime ();
  float averageTurnaround;
};

#endif

Scheduler::Scheduler () {
  averageTurnaround = 0;
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

float Scheduler::getAverageTurnaround () {
  return averageTurnaround;
}

/* int algorithm - 0: first come first serve, 1: shortest job next, 2: priority */
void Scheduler::schedule (int algorithm, std::vector<Process> processes) {
  // Clear existing queue data.
  queue.clear();
  queue.swap(queue);
  averageTurnaround = 0;

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

  calculateTime();
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

void Scheduler::calculateTime () {
  int totalTurnaround = 0;
  for (int i = 0; i < queue.size(); i++) {
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
      waitTime = queue.at(i - 1).getEndTime() - queue.at(i).getArrivalTime();
      if (waitTime < 0) waitTime = 0;
    }

    /*  If first process, it is zero.
        Start time = arrival time + wait time.
    */
    if (i == 0) startTime = 0;
    else {
      startTime = queue.at(i).getArrivalTime() + waitTime;
    }

    /* End time = start time + burst time. */
    endTime = startTime + queue.at(i).getBurstTime();

    /* Turnaround time = end time - arrival time. */
    turnaround = endTime - queue.at(i).getArrivalTime();
    totalTurnaround += turnaround;

    queue.at(i).setStartTime(startTime);
    queue.at(i).setEndTime(endTime);
    queue.at(i).setWaitTime(waitTime);
    queue.at(i).setTurnaround(turnaround);
  }

  // Calculate average turn around time.
  averageTurnaround = (float) totalTurnaround / queue.size();
}
