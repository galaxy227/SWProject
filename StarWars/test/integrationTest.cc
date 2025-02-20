#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <sys/time.h>
#include <pcf8591.h>
#include <math.h>

// Flame
#define PCF 120
#define DOpin 6
// Motor
#define MOT1P 29
#define MOT1N 28
#define MOT2P 0
#define MOT2N 2
// LED
#define GLED 24
#define RLED 25
// Ultrasound
#define TRIG 5
#define ECHO 4
// Arc
#define SIG 3

void init() {
	// WiringPi
    	if (wiringPiSetup() == -1) {
		printf("Failure to initialize wiringPi");
		exit(0);
    	}
	// TODO: Turn on the star wars theme song
	
	// LED
    	pinMode(GLED, OUTPUT);
    	pinMode(RLED, OUTPUT);
	// TODO Test
    	digitalWrite(RLED, LOW);
	delay(3000);

    	digitalWrite(GLED, LOW);
    	digitalWrite(RLED, HIGH);
    	printf("LED init\n");
	
	// Flame
    	pcf8591Setup(PCF, 0x48);
    	pinMode(DOpin, INPUT);
    	printf("FLAME init\n");
    	
	// Motor
    	pinMode(MOT1P, OUTPUT);
    	pinMode(MOT1N, OUTPUT);
    	pinMode(MOT2P, OUTPUT);
    	pinMode(MOT2N, OUTPUT);
    	digitalWrite(MOT1P, LOW);
    	digitalWrite(MOT1N, LOW);
    	digitalWrite(MOT2P, LOW);
    	digitalWrite(MOT2N, LOW);
    	printf("MOTOR init\n");
    	
	// Ultrasound
    	pinMode(ECHO, INPUT);
    	pinMode(TRIG, OUTPUT);
    	printf("ULTRASOUND init\n");
}

bool flame() {
	int analget = analogRead(PCF + 0);
    	printf("%d \n", analog);
	if (analog != 130) return true;
	else return false;
}

void motor(const bool status, const bool state, const bool is_forward) {
	if (status) {
		// Trap door opening
		if (state and is_forward) {
			digitalWrite(MOT1P, HIGH);
			delay(185);
			digitalWrite(MOT1P, LOW);
		}
		// Trap door closing
		else if (state and !is_forward) {
			digitalWrite(MOT1N, HIGH);
			delay(140);
			digitalWrite(MOT1N, LOW);
		}
		// Strom trooper opening
		else if (!state and is_forward) {
			digitalWrite(MOT2P, HIGH);
			delay(328);
			digitalWrite(MOT2P, LOW);
		}
		// Storm trooper closing
		else if (!state and !is_forward) {
			digitalWrite(MOT2N, HIGH);
			delay(253);
			digitalWrite(MOT2N, LOW);
		}
	}
	else {
		digitalWrite(MOT1P, LOW); // Off
		digitalWrite(MOT1N, LOW);
		digitalWrite(MOT2P, LOW);
		digitalWrite(MOT2N, LOW);
	}
}
void led(const bool status) {
	if (status) {
		digitalWrite(GLED, HIGH); // On
		digitalWrite(RLED, LOW);
	}
	else { 
		digitalWrite(GLED, LOW); // Off
		digitalWrite(RLED, HIGH);
	}
}
bool ultrasound(const int threshold) {
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
	if (distance <= threshold) return true;
	else return false;
}

int main(void) {
	init(); // Turns red led on

	// Trap door opens
	motor(true, true, true);
    	printf("Trap door opens\n");
	
	// Loop
	bool status = true;

	// Ultrasound 
    	while (status) {
		printf("%d\n", status);
		// Detect status
		status = ultrasound(30);
		delay(250); // TODO Delay required to read ultrasound
		if (!status) {
    			printf("R2D2 moved away\n");
			// Play the r2d2 screaming sounds
		}
	}
	status = false;

	// Wait for r2d2 to fall in
	delay(1500);

	// Flame sensor
	while (!status) {
		//Send a shock until we detect a flame
		digitalWrite(SIG, HIGH);
		delay(100);
		digitalWrite(SIG, LOW);
		delay(50);

		// If we detect a flame
		status = flame();
		
		// Perform action
		if (status) {
    			printf("Detected flame\n");
			// TODO: If we have 1 speaker, turn off r2d2 screaming here
			// Open the stormtrooper door
			delay(2000);
			motor(status, false, true);
    			printf("Stormtrooper door opens\n");
			// Turn red led off and green led on
			led(status);
    			printf("Red off, green on\n");
			// Turn on stormtrooper footsteps/sounds
		}
    	}
	status = false;

	delay(3000);
	
	// TODO: If we have 2 speakers, turn off r2d2 screaming here
	
	// Close doors
	motor(true, true, false); // Close trapdoor
	motor(true, false, false); // Close stormtrooper door
    	printf("Close doors\n");
	// Switch lights
	led(status);
    	printf("Red on, green off\n");

	delay(5000);
	// Turn everything off
    	digitalWrite(RLED, LOW);
    	digitalWrite(GLED, LOW);

    	return 0;
}
