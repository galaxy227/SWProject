#include "project.h"
#include <stdio.h>
#include <sys/time.h>

#define TRIG 5
#define ECHO 4

void Project::init_ultrasound() {
    	pinMode(ECHO, INPUT);
    	pinMode(TRIG, OUTPUT);
}
bool Project::get_ultrasound(const int distance_threshold) {
	// Calculate distance
    	struct timeval tv1;
    	struct timeval tv2;
    	digitalWrite(TRIG, LOW);
    	delayMicroseconds(2);
    	digitalWrite(TRIG, HIGH);
    	delayMicroseconds(10);
    	digitalWrite(TRIG, LOW);
    	while(!(digitalRead(ECHO) == 1));
    	gettimeofday(&tv1, NULL);
    	while(!(digitalRead(ECHO) == 0));
    	gettimeofday(&tv2, NULL);
    	long time1 = tv1.tv_sec * 1000000 + tv1.tv_usec;
    	long time2  = tv2.tv_sec * 1000000 + tv2.tv_usec;
    	float distance = (float)(time2 - time1) / 1000000 * 34000 / 2;	
	// Return status
	if (distance >= distance_threshold) return true;
	else return false;
}

