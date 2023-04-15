#include "main.h"

void Shoot() {
    pros::delay(950);
    Shooter.move_voltage(12000);
    pros::delay(65);
    Shooter.move_voltage(0);
}

void ActivateSystem(std::string system, std::optional<int> miliseconds, std::optional<bool> activate) {
    std::transform(system.begin(), system.end(), system.begin(), ::tolower);

    if(system == "intaker") {
        if(activate.has_value()) {
            if(activate.value() == true) {
                Intaker.move_voltage(12000);
                Shooter.move_voltage(-12000);
            } else {
                Intaker.move_voltage(0);
                Shooter.move_voltage(0);
            }
        } else {
            Intaker.move_voltage(12000);
            Shooter.move_voltage(-12000);
            pros::delay(miliseconds.value());
            Intaker.move(0);
            Shooter.move(0);
        }
    }

    else if(system.find("flywheel") != std::string::npos) {
        char lastChar = system.back();
        int num = (int) lastChar;

        if(lastChar == 'l') {
            if(activate.has_value()) {
                if(activate.value() == true) {
                    Flywheel.move_voltage(12000);
                }
                else if (activate.value() == false) {
                    Flywheel.move(0);
                }
            }
        }
        else {
            Flywheel.move_voltage(11500);

            if(activate.value() == true) {
                pros::delay(2000);
            }

            for(int i = 1; i < num; i++) {
                Shoot();
            }

            Flywheel.move(0);
        }
    }

    else if(system.find("roller") != std::string::npos) {
        int voltage = 12000;

        if(system.find("backwards") != std::string::npos) {
            voltage = -12000;
        }

        if(activate.has_value()) {
            if(activate.value() == true) {
                Roller.move_voltage(voltage);
            } else {
                Roller.move(0);
            }
        } else {
            Roller.move_voltage(voltage);
            pros::delay(miliseconds.value());
            Roller.move(0);
        }
    }
    
    else if(system.find("shooter") != std::string::npos) {
        int voltage = 12000;

        if(system.find("backwards") != std::string::npos) {
            voltage = -12000;
        }

        if(activate.has_value()) {
            if(activate.value() == true) {
                Shooter.move_voltage(voltage);
            } else {
                Shooter.move(0);
            }
        } else {
            Shooter.move_voltage(voltage);
            pros::delay(miliseconds.value());
            Shooter.move(0);
        }
    }

    else if(system == "expansion") {
        Expansion_Piston.set_value(true);
    }
}
