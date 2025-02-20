#include "project.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

void Project::init_all() {
	init_wiringPi();
	// Components
	init_led();
	init_flame();
	init_motor();
	init_ultrasound();
	init_arc();
}
void Project::init_wiringPi() {
	int error_code = wiringPiSetup();
	if (error_code == -1) {
		printf("Failure to initialize wiringPi");
		exit(0);
	}
}
void Project::off_all() {
	// LED
	do_led(RED, false);
	do_led(GREEN, false);
	// MOTOR
	do_motor(TRAP_DOOR, false);
	do_motor(STORMTROOPER_DOOR, false);
	// ARC
	do_arc(false);
}
