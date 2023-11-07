const int leds[] = {8, 9, 10, 11, 2, 3};
const int LIGHT = A4;
const int MIN_LIGHT = 800;
const int MAX_LIGHT = 974;

int lightData = 0;

void setup()
{
    for (int i = 0; i < 6; i++)
    {
        pinMode(leds[i], OUTPUT);
    }
}

void loop()
{
    lightData = analogRead(LIGHT);

    if (lightData <= MIN_LIGHT)
    {
        for (int i = 0; i < 6; i++)
        {
            digitalWrite(leds[i], LOW);
        }
        digitalWrite(8, HIGH);
    }
    else if (lightData >= MAX_LIGHT)
    {
        for (int i = 1; i < 6; i++)
        {
            digitalWrite(leds[i], HIGH);
        }
    }
    else
    {
        lightData = map(lightData, MIN_LIGHT, MAX_LIGHT, 0, 5);
        for (int i = 0; i < 6; i++)
        {
            if (i <= lightData)
            {
                digitalWrite(leds[i], HIGH);
            }
            else
            {
                digitalWrite(leds[i], LOW);
            }
        }
    }

    delay(1000);
}
