//
// Created by Inqognitoo on 13.08.2022.
//

#ifndef KKTOKEN_CLIENT_SRC_INTERFACE_LOG_RECORD_H_
#define KKTOKEN_CLIENT_SRC_INTERFACE_LOG_RECORD_H_

class Record {
  public:
    enum Level {
        Trace,      // Use for tracing something during development phase
        Debug,      // Use for information needed for diagnosing issues and troubleshooting etc
        Info,       // Use for indicate that something normal happened
        Warn,       // Use for warn
        Error,      // Use for runtime errors (application logic level)
        Fatal,      // Use for fatal errors (application core level)
    };

    std::time_t time;
    Level level;
    std::string message;

    Record(Level level, const char* message)
        : level(level), message(message) {
        time = std::time(nullptr); // todo: [?] std::chrono::time_point and std::chrono::system_clock::now() [?]
    }

    std::string toString() { // is it serializable, huh?
        std::ostringstream output;
        output << std::put_time(std::localtime(&time), "%F %T%z") << " : ";

        output << "LOGGER ["; // :[ sad

        switch (level) {
            case Record::Trace: output << "TRACE"; break;
            case Record::Debug: output << "DEBUG"; break;
            case Record::Info:  output << "INFO "; break;
            case Record::Warn:  output << "WARN "; break;
            case Record::Error: output << "ERROR"; break;
            case Record::Fatal: output << "FATAL"; break;
        }

        output << "]: " << message << std::endl; // ]: too sad because sad too
        return output.str();
    }
};

#endif//KKTOKEN_CLIENT_SRC_INTERFACE_LOG_RECORD_H_
