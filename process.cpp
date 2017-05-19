#ifndef PROCESS
#define PROCESS
class Process {
private:
  int number;
  int burstTime;
  int arrivalTime;
  int priority;
  int startTime;
  int endTime;
  int waitTime;
  int turnaround;
public:
  Process();
  ~Process();
  int getNumber ();
  int getBurstTime ();
  int getArrivalTime ();
  int getPriority ();
  int getStartTime ();
  int getEndTime ();
  int getWaitTime ();
  int getTurnaround ();
  void setNumber (int);
  void setBurstTime (int);
  void setArrivalTime (int);
  void setPriority (int);
  void setStartTime (int);
  void setEndTime (int);
  void setWaitTime (int);
  void setTurnaround (int);
};
#endif

Process::Process () {}

Process::~Process () {}

int Process::getNumber () {
  return this->number;
}
int Process::getBurstTime () {
  return this->burstTime;
}
int Process::getArrivalTime () {
  return this->arrivalTime;
}
int Process::getPriority () {
  return this->priority;
}
int Process::getStartTime () {
  return this->startTime;
}
int Process::getEndTime () {
  return this->endTime;
}
int Process::getWaitTime () {
  return this->waitTime;
}
int Process::getTurnaround () {
  return this->turnaround;
}

void Process::setNumber (int number) {
  this->number = number;
  return;
}
void Process::setBurstTime (int burstTime) {
  this->burstTime = burstTime;
  return;
}
void Process::setArrivalTime (int arrivalTime) {
  this->arrivalTime = arrivalTime;
  return;
}
void Process::setPriority (int priority) {
  this->priority = priority;
  return;
}
void Process::setStartTime (int startTime) {
  this->startTime = startTime;
  return;
}
void Process::setEndTime (int endTime) {
  this->endTime = endTime;
  return;
}
void Process::setWaitTime (int waitTime) {
  this->waitTime = waitTime;
  return;
}
void Process::setTurnaround (int turnaround) {
  this->turnaround = turnaround;
  return;
}
