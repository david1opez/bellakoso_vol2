/**
 * @file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"

/**
 * Global Constants
*/
#include "globals.h"

/**
 * Components
 */
#include "./components/motors.h"
#include "./components/sensors.h"
#include "./components/others.h"

/**
 * Control Systems
 */
#include "./systems/control/Drive.h"
#include "./systems/control/HandleIntaker.h"
#include "./systems/control/HandleFlywheel.h"
#include "./systems/control/HandleRoller.h"
#include "./systems/control/RestartComponents.h"
#include "./systems/control/HandleExpansion.h"
#include "./systems/control/EndgameCountdown.h"

/**
 * Autonomous Systems
 */
#include "./systems/autonomous/routines/AutonomousRoutine.h"
#include "./systems/autonomous/routines/ProgrammingSkillsRoutine.h"
#include "./systems/autonomous/ActivateSystem.h"
#include "./systems/autonomous/TranslateInches.h"

/**
 * Positioning Systems
*/
#include "./systems/positioning/GetCoords.h"
#include "./systems/positioning/BackupSystems.h"

/**
 * PID Systems
 */
#include "./systems/PID/TranslatePID.h"
#include "./systems/PID/RotatePID.h"
#include "./systems/PID/FlywheelPID.h"

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * C++-only headers down here
 */

#endif

#endif  // _PROS_MAIN_H_
