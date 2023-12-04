#define RED_PIN 11
#define GREEN_PIN 8
#define BLUE_PIN 9
#define TEMP_SENSOR_PIN A5

#define MIN_TEMPERATURE 48
#define MAX_TEMPERATURE 68

void setup()
{
    initSerial();
    setupPins();
}

void loop()
{
    double temperature = readTemperature();
    displayTemperature(temperature);
    controlLEDsBasedOnTemperature(temperature);
    delay(1000);
}

void initSerial()
{
    Serial.begin(9600);
}

void setupPins()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

double readTemperature()
{
    int sensorValue = analogRead(TEMP_SENSOR_PIN);
    double voltage = sensorValue * 5.0 / 1024;
    return (voltage - 0.5) * 100;
}

void displayTemperature(double temperature)
{
    Serial.print("temp = ");
    Serial.println(temperature);
}

void controlLEDsBasedOnTemperature(double temperature)
{
    if (temperature < MIN_TEMPERATURE)
    {
        setLEDColor(0, 0, 1); // Blue
    }
    else if (temperature > MAX_TEMPERATURE)
    {
        setLEDColor(1, 0, 0); // Red
    }
    else
    {
        setLEDColor(0, 1, 0); // Green
    }
}

void setLEDColor(int red, int green, int blue)
{
    digitalWrite(RED_PIN, red);
    digitalWrite(GREEN_PIN, green);
    digitalWrite(BLUE_PIN, blue);
}
