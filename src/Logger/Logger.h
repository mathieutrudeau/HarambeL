#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

class Logger {
public:
    static const bool enabled = true;
    
    static void log(const std::string& message);
};

#endif // LOGGER_H
