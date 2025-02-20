#include "project.h"

#define ARCPIN  1

void Project::init_arc() {
    pinMode(ARCPIN, OUTPUT);
    digitalWrite(ARCPIN, LOW);
}
void Project::do_arc(const bool is_on) {
	if (is_on) digitalWrite(ARCPIN, HIGH);
	else digitalWrite(ARCPIN, LOW);
}
