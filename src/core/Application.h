#pragma once

#include <array>
#include <boost/asio.hpp>

#include "interface/log/Logger.h"

#define THREADS_COUNT 1

class Application {
  public:
    Application();// i want singleton :[

    void run();
    void stop();
    void forceStop();

  private:
    boost::asio::io_context execution_context_;
    boost::asio::executor_work_guard<boost::asio::io_context::executor_type> work_guard_;

    Logger logger_;
};
