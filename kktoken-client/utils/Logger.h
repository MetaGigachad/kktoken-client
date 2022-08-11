#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>

class Logger {
  public:
    enum Level { Normal,
                 Debug,
                 Error,
                 CriticalError };

    Logger() {}

    void log(const char* message, Level level) {
        auto time = std::time(nullptr);
        std::cerr << std::put_time(std::localtime(&time), "%F %T%z") << " : ";

        std::cerr << "LOGGER : ";

        switch (level) {
            case Normal:
                std::cerr << "NORMAL        ";
                break;
            case Debug:
                std::cerr << "DEBUG         ";
                break;
            case Error:
                std::cerr << "ERROR         ";
                break;
            case CriticalError:
                std::cerr << "CRITICAL_ERROR";
                break;
        }

        std::cerr << " : " << message << std::endl;
    }
};
