int inputValue;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    inputValue = Serial.read();
    switch (inputValue)
    {
    case 'C':
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1050);
        digitalWrite(LED_BUILTIN, LOW);
        delay(1050);
        Serial.println("Hello C Milan");
        break;

    case 'M':
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1050);
        digitalWrite(LED_BUILTIN, LOW);
        delay(1050);
        Serial.println("This was made by Mike");
        break;
    }
}
