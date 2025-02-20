#include <stdio.h>
#include <wiringPi.h>

#define SIG 3

int main(void) {
    printf("Raspberry Pi arc\n");

    wiringPiSetup();
    pinMode(SIG, OUTPUT);
    delay(3000);               // in miliseconds
    digitalWrite(SIG, HIGH);  // On
    delay(500);               // in miliseconds
    digitalWrite(SIG, LOW);   // Off
    delay(500);
    return 0;
}
