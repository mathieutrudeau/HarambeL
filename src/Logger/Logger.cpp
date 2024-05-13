#include "Logger.h"

void Logger::log(const std::string& message)
{
    if (enabled)
        std::cout << message << std::endl;
}