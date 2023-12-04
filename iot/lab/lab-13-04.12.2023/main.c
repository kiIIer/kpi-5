int trigPin = 12;
int echoPin = 13;
int speakerPin = 8;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    int distance = measureDistance();
    Serial.print(distance);
    Serial.println(" cm");
    controlSpeaker(distance);
    delay(100);
}

int measureDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    int duration = pulseIn(echoPin, HIGH);
    return duration / 58;
}

void controlSpeaker(int distance) {
    if (distance >= 105 && distance <= 205) {
        tone(speakerPin, 300);
    } else {
        noTone(speakerPin);
    }
}
