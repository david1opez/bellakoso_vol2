#include "main.h"

Status RestartComponents() {
    Status status;

    if(Inertial_Sensor.reset() == INT32_MAX) {
        std::cout << "Error resetting Inertial Sensor" << std::endl;
        status.IMU_Works = false;
    }
    if(Y_Axis_Encoder.reset() == INT32_MAX) {
        std::cout << "Error resetting Y Axis Encoder" << std::endl;
        status.Encoder_Works = false;
    }

    pros::delay(2000);

    if(std::isinf(Y_Axis_Encoder.get_value()) || std::isnan(Y_Axis_Encoder.get_value())) {
        std::cout << "Error reading Y Axis Encoder" << std::endl;
        status.Encoder_Works = false;
    }

    if(std::isinf(Inertial_Sensor.get_rotation()) || std::isnan(Inertial_Sensor.get_rotation())) {
        std::cout << "Error reading Inertial Sensor" << std::endl;
        status.IMU_Works = false;
    }
    
    return status;
};

Status CheckSensors(std::optional<bool> checkChange, std::optional<double> initialEncoderValue, std::optional<double> initialIMUValue) {
    Status status;
    
    if(std::isinf(Y_Axis_Encoder.get_value()) || std::isnan(Y_Axis_Encoder.get_value())) {
        std::cout << "Error reading Y Axis Encoder" << std::endl;
        status.Encoder_Works = false;
    } else {
        status.Encoder_Works = true;
    }

    if(std::isinf(Inertial_Sensor.get_rotation()) || std::isnan(Inertial_Sensor.get_rotation())) {
        std::cout << "Error reading Inertial Sensor" << std::endl;
        status.IMU_Works = false;
    } else {
        status.IMU_Works = true;
    }

    if(checkChange) {
        if(Y_Axis_Encoder.get_value() == initialEncoderValue) {
            std::cout << "Y Axis Encoder value hasn't changed" << std::endl;
            status.Encoder_Works = false;
        } else {
            status.Encoder_Works = true;
        }

        if(Inertial_Sensor.get_rotation() == initialIMUValue) {
            std::cout << "Inertial Sensor value hasn't changed" << std::endl;
            status.IMU_Works = false;
        } else {
            status.IMU_Works = true;
        }
    }
    
    return status;
};
