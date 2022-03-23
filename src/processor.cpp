#include <vector>
#include <string>

#include "linux_parser.h"
#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    float utilization {0};
    long active_time = LinuxParser::ActiveJiffies();
    long idel_time = LinuxParser::IdleJiffies();
    long duration_active {active_time - cached_active_time_};
    long duration_idle {idel_time - cached_idle_time_};
    long duration {duration_active + duration_idle};
    utilization = static_cast<float>(duration_active) / duration;
    cached_active_time_ = active_time;
    cached_idle_time_ = idel_time;
    return utilization;
}