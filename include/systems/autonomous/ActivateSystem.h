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
void ActivateSystem(std::string system, std::optional<int>miliseconds);

#endif // __ACTIVATE_SYSTEM_H__
