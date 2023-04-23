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
        .subsystemTimeout = 1400,
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
        .distance = 18,
        .angle = 41,
        .timeout = 5000,
        .subsystem = "intaker",
        .subsystemTimeout = 1300,
    });

    TranslateInches({
        .distance = 6,
        .angle = -21,
        .timeout = 5000,
    });

    // Shoot 3 discs without charging the flywheel
    ActivateSystem({
       .system = "flywheel",
       .flywheelRPMs = 3320,
       .discs = 1,
    });

    ActivateSystem({
       .system = "flywheel",
       .flywheelRPMs = 3280,
       .discs = 2,
    });
    
    // Move to second pickup position
    TranslateInches({
        .PID = false,
        .distance = 7,
        .reverse = true,
        .angle = -21,
        .timeout = 2000
    });

    TranslateInches({
        .distance = 6,
        .angle = 52,
    });

    // Pick up stacked discs
    TranslateInches({
        .distance = 5,
        .angle = 52,
        .subsystem = "intaker",
        .subsystemTimeout = 900,
    });

    TranslateInches({
        .distance = 5,
        .angle = 52,
        .subsystem = "intaker",
        .subsystemTimeout = 800,
    });

    // Charge Flywheel
    ActivateSystem({
        .system = "flywheel",
        .activate = true,
    });

    // Move to second shooting position
    TranslateInches({
        .distance = 7.5,
        .angle = -19,
        .subsystem = "intaker",
        .subsystemTimeout = 2500,
    });

    // Shoot 3 discs without charging the flywheel
    ActivateSystem({
       .system = "flywheel",
       .flywheelRPMs = 3200,
       .discs = 3,
    });

    // Move to third pickup position
    TranslateInches({
        .PID = false,
        .distance = 8,
        .reverse = true,
        .angle = -20,
        .timeout = 2000
    });

    TranslateInches({
        .distance = 14,
        .angle = 56,
        .timeout = 3000,
        .subsystem = "intaker",
        .subsystemTimeout = 2000,
    });

    // Charge Flywheel
    ActivateSystem({
        .system = "flywheel",
        .activate = true,
    });

    // Move to third shooting position
    TranslateInches({
        .distance = 7.5,
        .angle = -19,
        .timeout = 3000,
        .subsystem = "intaker",
        .subsystemTimeout = 2500,
    });

    // Shoot 2 discs without charging the flywheel
    ActivateSystem({
       .system = "flywheel",
       .flywheelRPMs = 3260,
       .discs = 2,
    });
    
    // Move to fourth pickup position
    TranslateInches({
        .distance = 50,
        .reverse = true,
        .angle = -6,
        .timeout = 2000
    });

    TranslateInches({
        .distance = 24,
        .angle = 25,
        .timeout = 2000,
        .subsystem = "intaker",
        .subsystemTimeout = 3000,
    });

    TranslateInches({
        .distance = 7,
        .angle = 20.5,
        .timeout = 2000,
        .subsystem = "intaker",
        .subsystemTimeout = 1000,
    });

    // // Move to fourth pickup position
    // TranslateInches({
    //     .distance = 9,
    //     .angle = 45,
    //     .subsystem = "intaker",
    //     .subsystemTimeout = 800,
    // });

//     TranslateInches({
//         .PID = false,
//         .distance = 3,
//         .reverse = true,
//         .angle = 45,
//         .subsystem = "intaker",
//         .subsystemTimeout = 800,
//     });

//     TranslateInches({
//         .distance = 14,
//         .angle = 45,
//         .subsystem = "intaker",
//         .subsystemTimeout = 800,
//     });

//     TranslateInches({
//         .PID = false,
//         .distance = 3,
//         .reverse = true,
//         .angle = 45,
//         .subsystem = "intaker",
//         .subsystemTimeout = 800,
//     });

//     TranslateInches({
//         .distance = 23,
//         .angle = 45,
//         .subsystem = "intaker",
//         .subsystemTimeout = 800,
//     });
}
