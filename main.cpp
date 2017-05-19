#include <iostream>
#include "scheduler.cpp"
using namespace std;

void displaySchedule (Scheduler &);

int main () {
  cout << endl;

  std::vector<Process> pending;

  Process p0;
  p0.setNumber(0);
  p0.setBurstTime(3);
  p0.setArrivalTime(0);
  p0.setPriority(0);

  Process p1;
  p1.setNumber(1);
  p1.setBurstTime(5);
  p1.setArrivalTime(3);
  p1.setPriority(0);

  Process p2;
  p2.setNumber(2);
  p2.setBurstTime(1);
  p2.setArrivalTime(5);
  p2.setPriority(0);

  Process p3;
  p3.setNumber(3);
  p3.setBurstTime(2);
  p3.setArrivalTime(6);
  p3.setPriority(0);

  Process p4;
  p4.setNumber(4);
  p4.setBurstTime(7);
  p4.setArrivalTime(9);
  p4.setPriority(0);

  pending.push_back(p0);
  pending.push_back(p1);
  pending.push_back(p2);
  pending.push_back(p3);
  pending.push_back(p4);

  Scheduler scheduler;
  scheduler.schedule(0, pending);

  displaySchedule(scheduler);

  cout << endl;
  return 0;
}

void displaySchedule (Scheduler & scheduler) {
  for (int i = 0; i < scheduler.getSize(); i++) {
    cout << scheduler.get(i).getArrivalTime() << endl;
  }
}
