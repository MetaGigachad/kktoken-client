#include "Application.h"

#include <array>
#include <thread>

Application::Application()
    : work_guard_(boost::asio::make_work_guard(execution_context_)) {
}

void Application::run() {
    boost::asio::io_context* context = &execution_context_;

    logger_.log("Starting execution_context in threads.", Logger::Debug);

    std::array<std::thread, THREADS_COUNT> threads;

    for (size_t i = 0; i < THREADS_COUNT; ++i) {
        threads[i] = std::thread([context]() { context->run(); });
    }

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
