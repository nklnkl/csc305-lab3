#include <iostream>
#include <iomanip>
#include "scheduler.cpp"
using namespace std;

/*
  Algorithm for scheduling.
  0: first come first serve,
  1: shortest job next,
  2: priority
*/
static int algorithm = 0;

void displaySchedule (Scheduler &);

int main () {
  cout << endl;

  std::vector<Process> pending;
  Process p0;
  Process p1;
  Process p2;
  Process p3;
  Process p4;
  Scheduler scheduler;

  /* Pending Processes*/
  p0.setNumber(0);
  p0.setBurstTime(3);
  p0.setArrivalTime(0);
  p0.setPriority(0);
  p1.setNumber(1);
  p1.setBurstTime(5);
  p1.setArrivalTime(3);
  p1.setPriority(0);
  p2.setNumber(2);
  p2.setBurstTime(1);
  p2.setArrivalTime(5);
  p2.setPriority(0);
  p3.setNumber(3);
  p3.setBurstTime(2);
  p3.setArrivalTime(6);
  p3.setPriority(0);
  p4.setNumber(4);
  p4.setBurstTime(7);
  p4.setArrivalTime(9);
  p4.setPriority(0);
  pending.push_back(p0);
  pending.push_back(p1);
  pending.push_back(p2);
  pending.push_back(p3);
  pending.push_back(p4);
  /* Pending Processes*/

  /* Send processes to scheduler */
  scheduler.schedule(algorithm, pending);
  /* Display algorithm */
  switch (algorithm) {
    case 0:
      cout << "First come first serve";
      break;
    case 1:
      cout << "Shortest job next";
      break;
    case 2:
      cout << "Priority";
      break;
    default:
      cout << "No valid algorithm selected";
  }
  cout << endl;
  /* Display schedule queue */
  displaySchedule(scheduler);

  cout << endl;
  return 0;
}

void displaySchedule (Scheduler & scheduler) {
  int columnSize = 13;
  cout << setw(columnSize) << left << "Queue #";
  cout << setw(columnSize) << left << "Arrival Time";
  cout << setw(columnSize) << left << "Burst Time";
  cout << setw(columnSize) << left << "Priority";
  cout << setw(columnSize) << left << "Wait Time";
  cout << setw(columnSize) << left << "Start Time";
  cout << setw(columnSize) << left << "Turnaround";
  cout << setw(columnSize) << left << "End Time";
  cout << endl;



  for (int i = 0; i < scheduler.getSize(); i++) {
    cout << setfill('-');
    cout << setw(columnSize) << left << i;
    cout << setw(columnSize) << left << scheduler.get(i).getArrivalTime();
    cout << setw(columnSize) << left << scheduler.get(i).getBurstTime();
    cout << setw(columnSize) << left << scheduler.get(i).getPriority();
    cout << setw(columnSize) << left << scheduler.get(i).getWaitTime();
    cout << setw(columnSize) << left << scheduler.get(i).getStartTime();
    cout << setw(columnSize) << left << scheduler.get(i).getTurnaround();
    cout << setw(columnSize) << left << scheduler.get(i).getEndTime();
    cout << endl;
  }

}
