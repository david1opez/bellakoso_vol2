#include "main.h"

void HandleExpansion() {
    if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1)
    {
        PistonExpansion.set_value(true);
    }
}
