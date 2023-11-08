#include <Servo.h>
Servo servo1;
const int pinServo = 8;
const int POT = 5;
int valpot = 0;
int angleServo = 0;
void setup()
{
    servo1.attach(pinServo);
}
void loop()
{
    valpot = analogRead(POT);
    angleServo = map(valpot, 0, 1023, 34, 138);
    servo1.write(angleServo);
    delay(15);
}
