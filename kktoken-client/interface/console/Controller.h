#pragma once

#include <boost/asio.hpp>
#include <core/Application.h>
#include <iostream>
#include <string>

#include <interface/console/Renderer.h>

class Controller {
  public:
    Controller(boost::asio::io_context* context)
        : context_(context) {}

    void run() {
        renderer_.renderStartScreen();

        while (true) {
            std::string input;

            renderer_.renderPrompt();
            std::cin >> input;

            if (input == "quit") {
                Application* app = application_;
                boost::asio::post(*context_, [app]() { app->stop(); });
                break;
            } else if (input == "force quit") {
                Application* app = application_;
                boost::asio::post(*context_, [app]() { app->forceStop(); });
                break;
            } else if (input == "help") {
                renderer_.renderMessage(std::string("quit - finishes tasks then quits\nforce quit - quits without finishing tasks"));
            }
        }
    }

  private:
    Renderer renderer_;
    boost::asio::io_context* context_;
    Application* application_;
};
