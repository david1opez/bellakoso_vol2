/**
 * @file components/RestartComponents.h
 * 
*/

#ifndef __RESTART_COMPONENTS_H__
#define __RESTART_COMPONENTS_H__

#include "main.h"

/**
 * @brief Runs initialization code. This occurs as soon as the program is started.
*/

struct Status {
    bool Encoder_Works;
    bool IMU_Works;
};

Status RestartComponents();

Status CheckSensors(
    std::optional<bool> checkChange = std::nullopt,
    std::optional<double> initialEncoderValue = std::nullopt,
    std::optional<double> initialIMUValue = std::nullopt
);

#endif // __RESTART_COMPONENTS_H__
