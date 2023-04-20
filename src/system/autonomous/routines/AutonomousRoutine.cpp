#include "main.h"

void AutonomousRoutine(Status Components_Status) {
    // Move Roller
    TranslateInches({
        .componentsStatus = Components_Status,
        .PID = false,
        .distance = 3,
        .reverse = true,
        .timeout = 45,
        .subsystem = "roller",
        .subsystemTimeout = 190,
        .backwards = true,
    });

    TranslateInches({
        .PID = false,
        .distance = 4,
        .timeout = 200
    });

    // Pick first disc
    TranslateInches({
        .distance = 11,
        .angle = -41,
        .timeout = 3000,
        .subsystem = "intaker",
        .subsystemTimeout = 1200,
    });

    TranslateInches({
        .PID = false,
        .distance = 4,
        .reverse = true,
        .angle = -41,
        .timeout = 120
    });

    // Charge Flywheel
    ActivateSystem({
        .system = "flywheel",
        .activate = true,
    });

    // Move to first shooting position
    TranslateInches({
        .distance = 17,
        .angle = 41,
        .timeout = 5000,
        .subsystem = "intaker",
        .subsystemTimeout = 1200,
    });

    TranslateInches({
        .distance = 7,
        .angle = -22,
        .timeout = 5000,
    });


    // Shoot 3 discs without charging the flywheel
    // ActivateSystem("flywheel 3", 11800, true);
    //ActivateSystem({
    //    .system = "flywheel",
    //    .discs = true
    //});
    

    // Turn off flywheel
    // ActivateSystem("flywheel", 0, false);

    // Move to pick up stacked discs

    // Pick up stacked discs
    // TranslateInches(10, false, 35, 1, 7000, "intaker", 3000);

    // Move to second shooting position

    // Shoot 3 discs
}
