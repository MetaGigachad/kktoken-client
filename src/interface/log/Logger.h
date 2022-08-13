#pragma once

#include "Record.h"
#include "interface/console/Renderer.h"

class Logger {
  public:
    Logger() = default;

    static void log(const char* message, Record::Level level) {
        Record record(level, message);
        Renderer::renderLog(record.toString());
    }
};
