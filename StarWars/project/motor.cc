#include "project.h"

#define MOT1P 29
#define MOT1N 28
#define MOT2P 0
#define MOT2N 2

void Project::init_motor() {
    	pinMode(MOT1P, OUTPUT);
    	pinMode(MOT1N, OUTPUT);
    	pinMode(MOT2P, OUTPUT);
    	pinMode(MOT2N, OUTPUT);
    	digitalWrite(MOT1P, LOW);
    	digitalWrite(MOT1N, LOW);
    	digitalWrite(MOT2P, LOW);
    	digitalWrite(MOT2N, LOW);
}
void Project::do_motor(const bool is_trapdoor, const bool is_on, const bool is_opening) {
	// Trapdoor
	if (is_trapdoor) {
		if (is_on) {
			if (is_opening) {
				digitalWrite(MOT1N, LOW);
				digitalWrite(MOT1P, HIGH);
			}
			else {
				digitalWrite(MOT1P, LOW);
				digitalWrite(MOT1N, HIGH);
			}
		}
		else {
				digitalWrite(MOT1P, LOW);
				digitalWrite(MOT1N, LOW);
		}
	}
	// Stormtrooper door
	else {
		if (is_on) {
			if (is_opening) {
				digitalWrite(MOT2N, LOW);
				digitalWrite(MOT2P, HIGH);
			}
			else {
				digitalWrite(MOT2P, LOW);
				digitalWrite(MOT2N, HIGH);
			}
		}
		else {
				digitalWrite(MOT2P, LOW);
				digitalWrite(MOT2N, LOW);
		}
	}
}
