const int MOTOR = 9;
const int POT = 3;
int valpot = 0;
int speedMotor = 0;

void setup()
{
    pinMode(MOTOR, OUTPUT);
}
void loop()
{
    valpot = analogRead(POT);
    speedMotor = map(valpot, 0, 1023, 0, 255);
    analogWrite(MOTOR, speedMotor);
    delay(1000);
}