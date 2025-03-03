#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define LED 0

int main(void) {
    printf("Raspberry Pi blink\n");

    wiringPiSetup();
    pinMode(LED, OUTPUT);
   while (true){
        digitalWrite(LED, HIGH);  // On
        delay(500);               // in miliseconds
        digitalWrite(LED, LOW);   // Off
        delay(500);
    }
    return 0;
}
