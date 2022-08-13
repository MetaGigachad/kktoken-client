#include "core/Application.h"
#include <stdexcept>

int main() {
    Application app;

    try {
        app.run();
    } catch (std::exception& e) {
        // TODO: logging
    } catch (...) {
        // same here
    }

    return 0;
}
