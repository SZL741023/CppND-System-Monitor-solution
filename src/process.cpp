#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {}
// TODO: Return this process's ID
int Process::Pid() const { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { return cpu_; }

void Process::CpuUtilization(long active_time, long system_time) {
    long duration_active {active_time - active_time_};
    long duration {system_time - system_time_};
    cpu_ = static_cast<float> (duration_active) / duration;
    active_time_ = active_time;
    system_time_ = system_time;
}

// TODO: Return the command that generated this process
string Process::Command() const { return LinuxParser::Command(Pid()); }

// TODO: Return this process's memory utilization
string Process::Ram() const { return LinuxParser::Ram(Pid()); }

// TODO: Return the user (name) that generated this process
string Process::User() const { return LinuxParser::User(Pid()); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const { return LinuxParser::UpTime(Pid()); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& x) const {
    return CpuUtilization() < x.CpuUtilization();
}

bool Process::operator>(Process const &x) const {
    return CpuUtilization() > x.CpuUtilization();
}