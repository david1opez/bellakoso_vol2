#include "main.h"

bool pistonActive = false;

void HandleExpansion() {
    if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP) == 1 || Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP) == 1) {
        pistonActive = !pistonActive;
    }

    if(pistonActive == true) {
        Expansion_Piston.set_value(true);
    }
    else{
        Expansion_Piston.set_value(false);
    }
}
