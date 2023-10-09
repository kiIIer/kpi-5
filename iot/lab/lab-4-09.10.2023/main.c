const int buttonPin1 = 12;
const int buttonPin2 = 13;
const int buttonPin3 = 7;
const int buttonPin4 = 6;
const int buttonPin5 = 5;
const int buttonPin6 = 4;

const int RedLedPin = 8;
const int OrangeLedPin = 9;
const int BlueLedPin = 10;
const int GreenLedPin = 11;
const int YellowLedPin = 2;
const int WhiteLedPin = 3;

struct ButtonLedPair {
    int buttonPin;
    int ledPin;
};

void initButtonLedPair(struct ButtonLedPair *pair) {
    pinMode(pair->ledPin, OUTPUT);
    pinMode(pair->buttonPin, INPUT);
}

void updateButtonLedPair(struct ButtonLedPair *pair) {
    if (digitalRead(pair->buttonPin) == HIGH) {
        digitalWrite(pair->ledPin, HIGH);
    } else {
        digitalWrite(pair->ledPin, LOW);
    }
}

void loop() {
    struct ButtonLedPair pairs[] = {
        {buttonPin1, RedLedPin},
        {buttonPin2, OrangeLedPin},
        {buttonPin3, BlueLedPin},
        {buttonPin4, GreenLedPin},
        {buttonPin5, YellowLedPin},
        {buttonPin6, WhiteLedPin}
    };

    for (int i = 0; i < sizeof(pairs) / sizeof(pairs[0]); i++) {
        updateButtonLedPair(&pairs[i]);
    }
}


void setup() {
    struct ButtonLedPair pairs[] = {
        {buttonPin1, RedLedPin},
        {buttonPin2, OrangeLedPin},
        {buttonPin3, BlueLedPin},
        {buttonPin4, GreenLedPin},
        {buttonPin5, YellowLedPin},
        {buttonPin6, WhiteLedPin}
    };

    for (int i = 0; i < sizeof(pairs) / sizeof(pairs[0]); i++) {
        initButtonLedPair(&pairs[i]);
    }
}

