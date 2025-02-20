#include <stdio.h>
#include <wiringPi.h>

#define		    arcPin  1

int main() {
    wiringPiSetup();

    pinMode(arcPin, OUTPUT);
    digitalWrite(arcPin, LOW);

    delay(1000);
    digitalWrite(arcPin, HIGH);
    delay(1000);
    digitalWrite(arcPin, LOW);

    return 0;
}

