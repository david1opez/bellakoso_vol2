#include "main.h"

bool activeShooterHigh = false;
bool activeShooterLow = false;
bool activeShooterMedium = false;


void HandleFlywheel() {
    if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
        if(activeShooterHigh == false) {
            Flywheel.move_voltage(0.86*12000);
            activeShooterHigh = true;
            activeShooterMedium = false;
            activeShooterLow = false;
        }
        else {
            Flywheel.move_voltage(0);
            activeShooterHigh = false;
        }
    }
    else if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B) == 1) {

        if(activeShooterMedium == false) {
            Flywheel.move_voltage(0.80*12000);
            activeShooterMedium = true;
            activeShooterHigh = false;
            activeShooterLow = false;
        }
        else {
            Flywheel.move_voltage(0);
            activeShooterMedium = false;
        }
    }
    else if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
        if(activeShooterLow == false) {
            Flywheel.move_voltage(0.70*12000);
            activeShooterLow = true;
            activeShooterHigh = false;
            activeShooterMedium = false;

        }
        else {
            Flywheel.move_voltage(0);
            activeShooterLow = false;
        }
    }

};



//86 r1
//70 r2 quitar macro
//80 b