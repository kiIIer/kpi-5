
// Define the RGB LED pin IDs
const int RED_PIN = 11;
const int GREEN_PIN = 9;
const int BLUE_PIN = 10;

// Define the colors as numbers
const int BLUE = 1;
const int ORANGE = 2;
const int LIGHT_BLUE = 3;
const int GREEN = 4;
const int YELLOW = 5;
const int RED = 6;
const int PURPLE = 7;

int currentRed = 0;
int currentGreen = 0;
int currentBlue = 0;

void setup()
{
    // Set RGB LED pins as OUTPUT
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{
    for (int color = BLUE; color <= PURPLE; color++)
    {
        int targetRed = 0;
        int targetGreen = 0;
        int targetBlue = 0;

        switch (color)
        {
        case BLUE:
            targetBlue = 255;
            break;
        case ORANGE:
            targetRed = 255;
            targetGreen = 125;
            break;
        case LIGHT_BLUE:
            targetGreen = 255;
            targetBlue = 255;
            break;
        case GREEN:
            targetGreen = 255;
            break;
        case YELLOW:
            targetRed = 255;
            targetGreen = 255;
            break;
        case RED:
            targetRed = 255;
            break;
        case PURPLE:
            targetRed = 255;
            targetBlue = 255;
            break;
        default:
            break;
        }

        while (currentRed != targetRed || currentGreen != targetGreen || currentBlue != targetBlue)
        {
            if (currentRed < targetRed)
            {
                currentRed++;
            }
            else if (currentRed > targetRed)
            {
                currentRed--;
            }
            if (currentGreen < targetGreen)
            {
                currentGreen++;
            }
            else if (currentGreen > targetGreen)
            {
                currentGreen--;
            }
            if (currentBlue < targetBlue)
            {
                currentBlue++;
            }
            else if (currentBlue > targetBlue)
            {
                currentBlue--;
            }
            analogWrite(RED_PIN, currentRed);
            analogWrite(GREEN_PIN, currentGreen);
            analogWrite(BLUE_PIN, currentBlue);
            delay(5);
        }
    }
}
