#include "project.h"
#include <pcf8591.h>
#include <math.h>

#define PCF 120
#define DOpin 6

void Project::init_flame() {
    	pcf8591Setup(PCF, 0x48);
    	pinMode(DOpin, INPUT);
}
bool Project::get_flame() {
	int analog = analogRead(PCF + 0);
	if (analog != 130) return true;
	else return false;
}
