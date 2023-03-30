/**
 * @file systems/autonomous/Translate.h
 * 
 * @brief Contains the definition of the Translate function
 * 
*/

#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__

#include "main.h"

/**
 * @brief Translates the robot to a specified x, y coordinate and angle in the robot's
 *        coordinate system (not the field's) at a specified speed percentage
 * 
 * @param x The x coordinate to translate the robot to
 * @param y The y coordinate to translate the robot to
 * @param angle The angle to rotate the robot to after translation (in degrees). If not specified, the robot will not rotate.
 * @param speed The speed percentage to translate the robot at (0-100). If not specified, the robot will translate at 100% speed.
 * @param timeout The amount of time to wait for the robot to translate before terminating the command (in milliseconds). (This is to prevent the robot from getting stuck). If not specified, the robot will wait 5 seconds.
 * @param subsystem The subsystem to activate while the robot is translating (e.g. "intake"). If not specified, no subsystem will be activated.
 * @param subsystemTimeout The amount of time to activate the parallel subsystem for (in milliseconds).
 * 
*/
void Translate(float x, float y, float angle=0, int speed=100, int timeout=5000, std::string subsystem="", int subsystemTimeout=0);

#endif // __TRANSLATE_H__
