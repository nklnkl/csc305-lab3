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
static int columnSize = 13;

void displaySchedule (Scheduler &, bool);

int main () {
  cout << endl;

  Scheduler scheduler;
  Process p0;
  Process p1;
  Process p2;
  Process p3;
  Process p4;

  /* Pending Processes*/
  p0.setNumber(0);
  p0.setBurstTime(3);
  p0.setArrivalTime(0);
  p0.setPriority(0);

  p1.setNumber(1);
  p1.setBurstTime(5);
  p1.setArrivalTime(8);
  p1.setPriority(0);

  p2.setNumber(2);
  p2.setBurstTime(3);
  p2.setArrivalTime(2);
  p2.setPriority(0);

  p3.setNumber(3);
  p3.setBurstTime(2);
  p3.setArrivalTime(1);
  p3.setPriority(0);

  p4.setNumber(4);
  p4.setBurstTime(7);
  p4.setArrivalTime(9);
  p4.setPriority(0);
  scheduler.add(p0);
  scheduler.add(p1);
  scheduler.add(p2);
  scheduler.add(p3);
  scheduler.add(p4);
  /* Pending Processes*/

  /* Display processes */
  cout << setfill('-');
  displaySchedule(scheduler, false);

  /* Send processes to scheduler */
  scheduler.schedule(algorithm);
  /* Display algorithm */
  cout << endl;
  switch (algorithm) {
    case 0:
      cout << "First come first serve - ";
      break;
    case 1:
      cout << "Shortest job next - ";
      break;
    case 2:
      cout << "Priority - ";
      break;
    default:
      cout << "No valid algorithm selected - ";
  }
  /* Display schedule queue */
  displaySchedule(scheduler, true);

  cout << endl;
  return 0;
}

void displaySchedule (Scheduler & scheduler, bool sorted) {
  if (sorted) cout << "Schedule - Queue in order" << endl;
  else cout << "Processes - Not in order" << endl;
  cout << setw(columnSize) << left << "#";
  cout << setw(columnSize) << left << "ID";
  cout << setw(columnSize) << left << "Arrival Time";
  cout << setw(columnSize) << left << "Burst Time";
  cout << setw(columnSize) << left << "Priority";
  if (sorted) cout << setw(columnSize) << left << "Wait Time";
  if (sorted) cout << setw(columnSize) << left << "Start Time";
  if (sorted) cout << setw(columnSize) << left << "End Time";
  if (sorted) cout << setw(columnSize) << left << "Turnaround";
  cout << endl;

  for (int i = 0; i < scheduler.getSize(); i++) {
    cout << setw(columnSize) << left << i;
    cout << setw(columnSize) << left << scheduler.get(i).getNumber();
    cout << setw(columnSize) << left << scheduler.get(i).getArrivalTime();
    cout << setw(columnSize) << left << scheduler.get(i).getBurstTime();
    cout << setw(columnSize) << left << scheduler.get(i).getPriority();
    if (sorted) cout << setw(columnSize) << left << scheduler.get(i).getWaitTime();
    if (sorted) cout << setw(columnSize) << left << scheduler.get(i).getStartTime();
    if (sorted) cout << setw(columnSize) << left << scheduler.get(i).getEndTime();
    if (sorted) cout << setw(columnSize) << left << scheduler.get(i).getTurnaround();
    cout << endl;
  }

  if (sorted) cout << endl << "Average turnaround time: " << scheduler.getAverageTurnaround() << endl;

}
