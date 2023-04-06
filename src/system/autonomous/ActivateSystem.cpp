#include "main.h"

void ActivateSystem(std::string system, std::optional<int> miliseconds = std::nullopt) {
    std::transform(system.begin(), system.end(), system.begin(), ::tolower);

    if(system == "intaker") {
        if(miliseconds.has_value()) {
            Intaker.move(127);
            pros::delay(miliseconds.value());
            Intaker.move(0);
        } else {
            Intaker.move(127);
        }
    }
}
