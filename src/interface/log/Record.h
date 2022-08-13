#pragma once

#include <boost/algorithm/string.hpp>
#include <chrono>
#include <iomanip>
#include <iosfwd>
#include <magic_enum.hpp>

class Record {
  public:
    enum Level {
        TRACE,  // Use for tracing something during development phase
        DEBUG,  // Use for information needed for diagnosing issues and troubleshooting etc
        INFO,   // Use for indicate that something normal happened
        WARN,   // Use for warn
        ERROR,  // Use for runtime errors (application logic level)
        FATAL,  // Use for fatal errors (application core level)
    };

    std::chrono::time_point<std::chrono::system_clock> time;
    Level level;
    std::string message;

    Record(Level level, const char* message)
        : level(level), message(message) {
        time = std::chrono::system_clock::now();
    }

    std::string toString() {
        std::ostringstream output;
        const time_t c_time = std::chrono::system_clock::to_time_t(time);

        output << std::put_time(std::localtime(&c_time), "%F %T%z") << " : "
               << "LOGGER [" << magic_enum::enum_name(level) << "] : "
               << message << std::endl;

        return output.str();
    }
};
