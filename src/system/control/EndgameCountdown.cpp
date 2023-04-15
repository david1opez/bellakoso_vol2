#include "main.h"

int EndgameCountdown(int countdown) {
    if(countdown <= 19500 && countdown > 0) {
		Controller.rumble("-  -");
	}

    countdown -= 1;
    pros::delay(1);

    return countdown;
}
