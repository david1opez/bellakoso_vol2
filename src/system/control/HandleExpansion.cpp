#include "main.h"

// bool pistonActive = false;

void HandleExpansion() {
    if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A) == 1) {
        Expansion.move_absolute(300, 100);
    }

    if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP) == 1) {
        Expansion_Blocker.move_absolute(300, 100);
    }
}
