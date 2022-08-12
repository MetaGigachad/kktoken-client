#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include <interface/console/Renderer.h>

class Log {
  public:
    enum Level { Normal,
                 Debug,
                 Error,
                 CriticalError };

    std::time_t time;
    Level level;
    std::string message;

    Log(Level level, const char* message)
        : level(level), message(message) {
        time = std::time(nullptr);
    }

    std::string toString() {
        std::stringstream output;
        output << std::put_time(std::localtime(&time), "%F %T%z") << " : ";

        output << "LOGGER : ";

        switch (level) {
            case Log::Normal:
                output << "NORMAL        ";
                break;
            case Log::Debug:
                output << "DEBUG         ";
                break;
            case Log::Error:
                output << "ERROR         ";
                break;
            case Log::CriticalError:
                output << "CRITICAL_ERROR";
                break;
        }

        output << " : " << message << std::endl;
        return output.str();
    }
};

class Logger {
  public:
    Logger() {}

    void log(const char* message, Log::Level level) {
        Log log(level, message);
        Renderer log_renderer;
        log_renderer.renderLog(log.toString());
    }
};
