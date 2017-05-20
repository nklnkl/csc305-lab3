#include <vector>
#include <iostream>
#include <algorithm>
#include "process.cpp"
using namespace std;

#ifndef SCHEDULER
#define SCHEDULER

class Scheduler {
public:
  Scheduler ();
  ~Scheduler ();
  void add (Process);
  Process get (int);
  int getSize ();
  float getAverageTurnaround ();
  void schedule (int);
private:
  float averageTurnaround;
  std::vector<Process> queue;
  Process nullProcess;
  void fcfs ();
  void sjn ();
  void priority ();
  void calculate ();
};

#endif

Scheduler::Scheduler () {
  averageTurnaround = 0;
  return;
}
Scheduler::~Scheduler () {
  queue.clear();
  queue.swap(queue);
  return;
}

Process Scheduler::get (int i) {
  if (i < 0 || i > queue.size()) return nullProcess;
  return queue.at(i);
}

void Scheduler::add (Process process) {
  queue.push_back(process);
  return;
}

int Scheduler::getSize () {
  return queue.size();
}

float Scheduler::getAverageTurnaround () {
  return averageTurnaround;
}

/* int algorithm - 0: first come first serve, 1: shortest job next, 2: priority */
void Scheduler::schedule (int algorithm) {
  switch (algorithm) {
    case 0:
      fcfs ();
      break;
    case 1:
      sjn ();
      break;
    case 2:
      priority ();
      break;
    default:
      fcfs ();
  }
  calculate();
  return;
}

void Scheduler::fcfs () {
  for (int i = 0; i < queue.size(); i++) {
    for (int j = 0; j < queue.size() - 1; j++) {
      if ( queue.at(j).getArrivalTime() > queue.at(j+1).getArrivalTime() )
        std::iter_swap(queue.begin()+j, queue.begin()+j+1);
    }
  }
}

void Scheduler::sjn () {
}
void Scheduler::priority () {
  return;
}

void Scheduler::calculate () {
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
    endTime = startTime + queue.at(i).getBurstTime();\

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
