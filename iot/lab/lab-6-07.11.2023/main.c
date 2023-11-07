int pins[7] = {2, 3, 4, 5, 6, 7, 8};
byte numbers[10] = {B11111010, B01100000, B11011100, B11110100, B01100110,
                    B10110110, B10111110, B10001010, B11111110, B11110110};

int mynums[10] = {3, 5, 0, 2, 6, 1, 4, 8, 7, 9};
int number = 0;

void setup()
{
    for (int i = 0; i < 7; i++)
    {
        pinMode(pins[i], OUTPUT);
    }
    for (int i = 0; i < 10; i++)
    {
        numbers[i] ^= B11111111
    }
}

void loop()
{
    showNumber(mynums[number]);
    delay(1000);
    number = (number + 1) % 10;
}

void showNumber(int num)
{
    for (int i = 0; i < 7; i++)
    {
        if (bitRead(numbers[num], 7 - i) == HIGH)
        {
            digitalWrite(pins[i], HIGH);
        }
        else
        {
            digitalWrite(pins[i], LOW);
        }
    }
}