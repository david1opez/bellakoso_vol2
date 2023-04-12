#include "main.h"

void FlywheelMacro() {
    Flywheel.move_voltage(12000);

    for (int i = 0; i < 1700; i++) {
        Drive();
        pros::delay(1);
    }

    Shooter.move_voltage(12000);

    for (int i = 0; i < 1000; i++) {
        Drive();
        pros::delay(1);
    }

    Shooter.move_voltage(0);

    for (int i = 0; i < 500; i++) {
        Drive();
        pros::delay(1);
    }

    Shooter.move_voltage(12000);

    for (int i = 0; i < 500; i++) {
        Drive();
        pros::delay(1);
    }

    Shooter.move_voltage(0);
};

bool activeShooter80 = false;
bool activeShooter100 = false;

void HandleFlywheel() {
    if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
        activeShooter80 = !activeShooter80;
        activeShooter100 = false;
    }
    else if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B) == 1) {
        activeShooter100 = !activeShooter100;
        activeShooter80 = false;
    }
    else if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
        FlywheelMacro();
    }

    if(activeShooter80) {
        Flywheel.move_voltage(0.86*12000);
    }
    else if(activeShooter100) {
        Flywheel.move_voltage(12000);
    }
    else {
        Flywheel.move_voltage(0);
    }

};
