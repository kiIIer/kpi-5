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
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        Serial.println("Hello C world");
        break;

    case 'M':
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        Serial.println("This was made by Mike");
        break;
    }
}
