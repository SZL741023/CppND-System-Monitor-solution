#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid);
  int Pid() const ;                               // TODO: See src/process.cpp
  std::string User() const;                      // TODO: See src/process.cpp
  std::string Command() const;                   // TODO: See src/process.cpp
  float CpuUtilization() const;                  // TODO: See src/process.cpp
  void CpuUtilization(long active_time, long system_time);
  long Jiffies() const;
  std::string Ram() const;                       // TODO: See src/process.cpp
  long int UpTime() const;                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  bool operator>(Process const& a) const;

  // TODO: Declare any necessary private members
 private:
  int pid_;
  float cpu_ {0};
  long active_time_ {0};
  long idle_time_ {0};
  long system_time_ {0};
};

#endif