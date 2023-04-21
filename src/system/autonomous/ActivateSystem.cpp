#include "main.h"

void Shoot() {
    Shooter.move_voltage(12000);
    pros::delay(65);
    Shooter.move_voltage(0);
}

void ActivateSystem(const ActivateSystemParams& params) {
    // Intaker
    if(params.system == "intaker") {
        if(params.simultaneous == true) {
            if(params.activate == true) {
                Intaker.move_voltage(12000);
                Shooter.move_voltage(-12000);
            } else {
                Intaker.move_voltage(0);
                Shooter.move_voltage(0);
            }
        }
        else {
            Intaker.move_voltage(12000);
            Shooter.move_voltage(-12000);
            pros::delay(params.miliseconds);
            Intaker.move_voltage(0);
            Shooter.move_voltage(0);
        }
    }

    // Flywheel
    else if(params.system.find("flywheel") != std::string::npos) {
        if(params.discs == 0) {
            if(params.activate) {
                if(params.activate == true) {
                    Flywheel.move_voltage(11000);
                }
                else if (params.activate == false) {
                    Flywheel.move_voltage(0);
                }
            }
        }
        else {
            int discsCount = 0;

            // Tal vez cambiar el primer while por un for loop y añadir un delay de casi nada
            while(discsCount <= params.discs){
                while((Rotation_Sensor.get_velocity() / 100) * 16.66666 <= params.flywheelRPMs + 10) {
                    Flywheel.move_voltage(FlywheelPID(params.flywheelRPMs));

                    if((Rotation_Sensor.get_velocity() / 100) * 16.66666 >= params.flywheelRPMs) {
                        Shoot();
                        discsCount++;
                    };
                }
            }

            Flywheel.move(0);
        }
    }

    // Roller
    else if(params.system.find("roller") != std::string::npos) {
        if(params.simultaneous) {
            if(params.activate == true) {
                Roller.move_voltage(params.backwards ? -12000 : 12000);
            } else {
                Roller.move_voltage(0);
            }
        } else {
            Roller.move_voltage(params.backwards ? -12000 : 12000);
            pros::delay(params.miliseconds);
            Roller.move(0);
        }
    }
    
    // Shooter
    else if(params.system.find("shooter") != std::string::npos) {
        if(params.simultaneous) {
            if(params.activate == true) {
                Shooter.move_voltage(params.backwards ? -12000 : 12000);
            } else {
                Shooter.move_voltage(0);
            }
        } else {
            Shooter.move_voltage(params.backwards ? -12000 : 12000);
            pros::delay(params.miliseconds);
            Shooter.move(0);
        }
    }

    // Intake
    else if(params.system == "expansion") {
        Expansion_Piston.set_value(true);
    }
}
