#pragma once

#include <iostream>

class Renderer {
  public:
    void renderStartScreen() {
        std::cout << R"( /$$   /$$ /$$   /$$ /$$$$$$$$        /$$                                  /$$$$$$  /$$       /$$$$$$)"
                  << "\n"
                  << R"(| $$  /$$/| $$  /$$/|__  $$__/       | $$                                 /$$__  $$| $$      |_  $$_/)"
                  << "\n"
                  << R"(| $$ /$$/ | $$ /$$/    | $$  /$$$$$$ | $$   /$$  /$$$$$$  /$$$$$$$       | $$  \__/| $$        | $$  )"
                  << "\n"
                  << R"(| $$$$$/  | $$$$$/     | $$ /$$__  $$| $$  /$$/ /$$__  $$| $$__  $$      | $$      | $$        | $$  )"
                  << "\n"
                  << R"(| $$  $$  | $$  $$     | $$| $$  \ $$| $$$$$$/ | $$$$$$$$| $$  \ $$      | $$      | $$        | $$  )"
                  << "\n"
                  << R"(| $$\  $$ | $$\  $$    | $$| $$  | $$| $$_  $$ | $$_____/| $$  | $$      | $$    $$| $$        | $$  )"
                  << "\n"
                  << R"(| $$ \  $$| $$ \  $$   | $$|  $$$$$$/| $$ \  $$|  $$$$$$$| $$  | $$      |  $$$$$$/| $$$$$$$$ /$$$$$$)"
                  << "\n"
                  << R"(|__/  \__/|__/  \__/   |__/ \______/ |__/  \__/ \_______/|__/  |__/       \______/ |________/|______/)"
                  << "\n"
                  << std::endl
                  << "You entered CLI mode. To learn commands use help.\n"
                  << std::endl;
    }

    void renderPrompt() {
        std::cout << "\n>>> ";
    }

    void renderLog(std::string log_text) {
        std::cerr << log_text << std::endl;
    }

    void renderMessage(std::string message_text) {
        std::cout << message_text << std::endl;
    }
};
