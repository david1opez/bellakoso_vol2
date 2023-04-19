#include "main.h"

void AutonomousRoutine(Status Components_Status) {
    // Move Roller
    TranslateInches({
        .componentsStatus = Components_Status,
        .distance = 24,
        // .reverse = true,
        .timeout = 5000,
        // .subsystem = "roller-backwards",
        // .subsystemTimeout = 114,
    });

    // TranslateInches({
    //     .distance = 3,
    //     .timeout = 1000
    // });

    // Pick first disc
    // TranslateInches({
    //     .distance = 8.5,
    //     .angle = -40.2,
    //     .timeout = 3000,
    //     .subsystem = "intaker",
    //     .subsystemTimeout = 1500,
    // });



    // Move backwards to turn
    // TranslateInches({
    //     .distance = 3,
    //     .reverse = true,
    //     .angle = -40,
    //     .timeout = 150,
    //     .subsystem = "intaker",
    //     .subsystemTimeout = 1000,
    // });

    // Charge Flywheel
    // ActivateSystem("flywheel", 12000, true);

    // Move to first shooting position
    // TranslateInches(20, false, 35, 1, 7000, "intaker", 1000);
    // TranslateInches({
    //     .distance = 20,
    //     .angle = 35,
    //     .timeout = 7000,
    //     .subsystem = "intaker",
    //     .subsystemTimeout = 1000,
    // });

    // TranslateInches(12, false, -44, 1, 2000, "", 100);

    // Shoot 3 discs without charging the flywheel
    // ActivateSystem("flywheel 3", 11800, true);

    // Turn off flywheel
    // ActivateSystem("flywheel", 0, false);

    // Move to pick up stacked discs

    // Pick up stacked discs
    // TranslateInches(10, false, 35, 1, 7000, "intaker", 3000);

    // Move to second shooting position

    // Shoot 3 discs
}
