#pragma once

#include <boost/asio.hpp>
#include <core/Application.h>
#include <iostream>
#include <string>

#include <interface/console/Renderer.h>

class Controller { // is it service, huh?
  public:
    Controller(boost::asio::io_context* context)
        : context_(context) {}

    void run() {
        Renderer::renderStartScreen();

        while (true) {
            std::string input;

            Renderer::renderPrompt();
            std::cin >> input;

            if (input == "quit") {
                Application* app = application_;
                app->stop();
                break;
            } else if (input == "force quit") {
                Application* app = application_;
                app->forceStop();
                break;
            } else if (input == "help") {
                Renderer::renderMessage(std::string("quit - finishes tasks then quits\nforce quit - quits without finishing tasks"));
            }
        }
    }

  private:
    boost::asio::io_context* context_;
    Application* application_; // singleton instance
};
