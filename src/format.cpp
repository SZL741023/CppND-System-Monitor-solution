#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    int hours, minutes;
    hours = seconds / ( 60 * 60 );
    seconds = seconds % ( 60 * 60 );
    minutes = seconds / 60;
    seconds = seconds % 60;
    
    return std::string(std::to_string(hours) + " : " + std::to_string(minutes) + " : " + std::to_string(seconds)); 
    }