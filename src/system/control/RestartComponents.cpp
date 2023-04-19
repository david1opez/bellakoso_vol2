#include "main.h"

Status RestartComponents() {
    Status status;

    if(Inertial_Sensor.reset() == INT32_MAX) {
        status.IMU_Works = false;
    }
    if(Y_Axis_Encoder.reset() == INT32_MAX) {
        status.Encoder_Works = false;
    }

    pros::delay(2000);

    if(std::isinf(Y_Axis_Encoder.get_value()) || std::isnan(Y_Axis_Encoder.get_value())) {
        status.Encoder_Works = false;
    }

    if(std::isinf(Inertial_Sensor.get_rotation()) || std::isnan(Inertial_Sensor.get_rotation())) {
        status.IMU_Works = false;
    }
    
    return status;
};

Status CheckSensors(std::optional<bool> checkChange, std::optional<double> initialEncoderValue, std::optional<double> initialIMUValue) {
    Status status;
    
    if(std::isinf(Y_Axis_Encoder.get_value()) || std::isnan(Y_Axis_Encoder.get_value())) {
        status.Encoder_Works = false;
    } else {
        status.Encoder_Works = true;
    }

    if(std::isinf(Inertial_Sensor.get_rotation()) || std::isnan(Inertial_Sensor.get_rotation())) {
        status.IMU_Works = false;
    } else {
        status.IMU_Works = true;
    }

    if(checkChange) {
        if(Y_Axis_Encoder.get_value() == initialEncoderValue) {
            status.Encoder_Works = false;
        } else {
            status.Encoder_Works = true;
        }

        if(Inertial_Sensor.get_rotation() == initialIMUValue) {
            status.IMU_Works = false;
        } else {
            status.IMU_Works = true;
        }
    }
    
    return status;
};
