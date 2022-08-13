#include "Application.h"

#include <array>
#include <interface/console/Controller.h>
#include <thread>

Application::Application()
    : work_guard_(boost::asio::make_work_guard(execution_context_)) {
}

void Application::run() {
    boost::asio::io_context* context = &execution_context_;

    logger_.log("Starting execution_context in threads.", Record::DEBUG);

    std::array<std::thread, THREADS_COUNT> threads;

    for (size_t i = 0; i < THREADS_COUNT; ++i) {
        threads[i] = std::thread([context]() { context->run(); });
    }

    Controller console_controller(&execution_context_);
    boost::asio::post(execution_context_, [&console_controller]() { console_controller.run(); });

    for (auto& thread: threads) {
        thread.join();
    }
}

void Application::forceStop() {
    execution_context_.stop();
}

void Application::stop() {
    work_guard_.reset();
}
