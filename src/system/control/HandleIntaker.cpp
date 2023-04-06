#include "main.h"

void HandleIntaker() {
    if(Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) < 0) {
        Intaker.move_voltage(12000);
        Shooter.move_voltage(-12000);
    }
    else if (Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) > 0) {
        Intaker.move_voltage(-12000);
        Shooter.move_voltage(12000);
    }
    else {
        Intaker.move_voltage(0);
        Shooter.move_voltage(0);
    }

    if(Controller.get_digital_new_press(DIGITAL_X) == 1) {
        Shooter.move_voltage(12000);
        for (int i = 0; i < 100; i++) {
            Drive();
            pros::delay(1);
        }
        Shooter.move_voltage(-12000);
        for (int i = 0; i < 100; i++) {
            Drive();
            pros::delay(1);
        }
        Shooter.move_voltage(0);
    }
}