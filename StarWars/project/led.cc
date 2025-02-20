#include "project.h"

#define GLED 24
#define RLED 25

void Project::init_led() {
    	pinMode(GLED, OUTPUT);
    	pinMode(RLED, OUTPUT);
    	digitalWrite(GLED, LOW);
    	digitalWrite(RLED, LOW);
}
void Project::do_led(const bool is_red, const bool is_on) {
	// Red
	if (is_red) {
    		if (is_on) digitalWrite(RLED, HIGH);
		else digitalWrite(RLED, LOW);
	}
	// Green
	else {
    		if (is_on) digitalWrite(GLED, HIGH);
		else digitalWrite(GLED, LOW);
	}
}
