/**
 * @file systems/autonomous/ActivateSystem.h
 * 
 * @brief Contains the definition of the ActivateSystem function
 * 
*/

#ifndef __ACTIVATE_SYSTEM_H__
#define __ACTIVATE_SYSTEM_H__

#include "main.h"

/**
 * @brief Activates the robot's subsystems
 * 
 * @param system The subsystem to activate
 * @param miliseconds The amount of time to activate the subsystem
 * 
*/

struct ActivateSystemParams {
    std::string system = "";
    int miliseconds = 0;
    bool simultaneous = false;
    bool activate = false;
    bool backwards = false;
    // Flywheel parameters
    int flywheelRPMs = 190;
    int discs = 0;
    bool unjam = true;
};

void Shoot();

void ActivateSystem(const ActivateSystemParams& params);

#endif // __ACTIVATE_SYSTEM_H__
