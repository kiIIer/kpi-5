#include <IRremote.h>

int resetButton = 16;
int yellowButton = 12;
int greenButton = 6;
int redButton = 4;
int redPin = 10;
int greenPin = 9;
int yellowPin = 7;
int IR_RECEIVE_PIN = 8;
IRrecv irrecv(IR_RECEIVE_PIN);

void setup()
{
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    irrecv.begin(IR_RECEIVE_PIN);
}

void loop()
{
    if (irrecv.decode())
    {
        int command = irrecv.decodedIRData.command;
        Serial.println(command);
        if (command == redButton)
        {
            digitalWrite(redPin, HIGH);
        }
        if (command == greenButton)
        {
            digitalWrite(greenPin, HIGH);
        }
        if (command == yellowButton)
        {
            digitalWrite(yellowPin, HIGH);
        }
        if (command == resetButton)
        {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(yellowPin, LOW);
        }
        irrecv.resume();
    }
}
