#ifndef PROCESS
#define PROCESS
class Process {
private:
  int number;
  int burstTime;
  int arrivalTime;
  int priority;
public:
  Process();
  ~Process();
  int getNumber ();
  int getBurstTime ();
  int getArrivalTime ();
  int getPriority ();
  void setNumber (int);
  void setBurstTime (int);
  void setArrivalTime (int);
  void setPriority (int);
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
