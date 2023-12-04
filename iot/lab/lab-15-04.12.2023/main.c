int sensorState = 0;
const int red = 13;
const int blue = 12;
const int ylw = 11;
const int grn = 10;

const int pir = 5;

void setup()
{
    pinMode(pir, INPUT);
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(ylw, OUTPUT);
    pinMode(grn, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    sensorState = digitalRead(pir);
    if (sensorState == HIGH)
    {
        digitalWrite(red, HIGH);
        digitalWrite(blue, HIGH);
        digitalWrite(ylw, LOW);
        digitalWrite(grn, LOW);
    }
    else
    {
        digitalWrite(red, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(ylw, HIGH);
        digitalWrite(grn, HIGH);
    }
    delay(10);
}
