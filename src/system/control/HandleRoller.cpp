#include "main.h"

void HandleRoller() {
    if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
        Roller.move_voltage(8000);
    } else if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
        Roller.move_voltage(-8000);
    } else {
        Roller.move_voltage(0);
    }
}
