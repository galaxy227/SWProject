#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define MOT1 0
#define MOT2 2

int main(void) {
    printf("Raspberry Pi Motor\n");

    wiringPiSetup();
    pinMode(MOT1, OUTPUT);
    pinMode(MOT2, OUTPUT);

    digitalWrite(MOT1, LOW);
    digitalWrite(MOT2, LOW);
    while (true) {
	digitalWrite(MOT1, HIGH);	// Moves motor forwards
	//digitalWrite(MOT2, HIGH);	// Moves motor backwards
        //softServoWrite(MOT, HIGH);  	// On
        delay(1000);               	// in miliseconds
	digitalWrite(MOT1, LOW);	// Turns off forward motor
	//digitalWrite(MOT2, LOW);	// Turns off backwards motor
        //softServoWrite(MOT, LOW);   	// Off
        delay(1000);
    }
    return 0;
}
