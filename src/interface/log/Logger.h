#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "interface/console/Renderer.h"
#include "Record.h"

class Logger {
  public:
    Logger() = default;

    static void log(const char* message, Record::Level level) {
        Record record(level, message);
        Renderer::renderLog(record.toString());
    }
};
