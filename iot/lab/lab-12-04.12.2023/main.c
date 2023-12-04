#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 10, 5, 7, 9, 11);
const int TMP36 = A0;

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop()
{
    double sensorValue = analogRead(TMP36);
    double voltage = sensorValue * 5.0 / 1024;
    double temperatureCelsius = (voltage - 0.5) * 100;
    double temperatureKelvin = temperatureCelsius + 273.15;

    displayTemperature(temperatureKelvin);
    Serial.println(temperatureKelvin);

    delay(1000);
}

void displayTemperature(double temperature)
{
    lcd.setCursor(2, 0);
    lcd.print("Temperature K");

    lcd.setCursor(4, 1);
    lcd.print(temperature);
}
