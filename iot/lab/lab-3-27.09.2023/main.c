int delayTime = 350;
int ledRedPin = 9;
int ledOrangePin = 10;
int ledBluePin = 11;
int ledGreenPin = 2;
int ledYellowPin = 3;
int ledWhitePin = 4;

void setup()
{
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledOrangePin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
  pinMode(ledWhitePin, OUTPUT);

}

void loop()
{
  blink(ledRedPin);
  blink(ledOrangePin);
  blink(ledBluePin);
  blink(ledGreenPin);
  blink(ledYellowPin);
  blink(ledWhitePin);
}

void blink(int ledPin) 
{
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}
