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
 * @brief Turns the robot left at a specified speed percentage
 * 
 * @param speed The speed percentage to turn the robot at (0-100)
 * 
*/
void TurnLeft(int speed);

/**
 * @brief Turns the robot right at a specified speed percentage
 * 
 * @param speed The speed percentage to turn the robot at (0-100)
 * 
*/
void TurnRight(int speed);

/**
 * @brief Moves the robot forwards at a specified speed percentage
 * 
 * @param speed The speed percentage to move the robot at (0-100)
 * 
*/
void MoveForwards(int speed);

/**
 * @brief Moves the robot backwards at a specified speed percentage
 * 
 * @param speed The speed percentage to move the robot at (0-100)
 * 
*/
void MoveBackwards(int speed);

/**
 * @brief Stops the robot
 * 
*/
void Stop(int speed);

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
void Translate(
    double x,
    double y,
    std::optional<double> angle = std::nullopt,
    std::optional<std::string> subsystem = std::nullopt,
    std::optional<int> speed = std::nullopt,
    std::optional<int> timeout = std::nullopt,
    std::optional<int> subsystemTimeout = std::nullopt
);

#endif // __TRANSLATE_H__
