#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

/**
 * @brief A class that provides logging functionality.
 */
class Logger {
public:
    /*
    * @brief A boolean value that determines if logging is enabled.
    */
    static const bool enabled = true;

    /**
     * @brief Log a message to the console.
     * 
     * @param message The message to log.
     */
    static void log(const std::string& message);
};

#endif // LOGGER_H
