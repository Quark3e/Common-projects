//arduono nano test code
int LED = 4;
int button = 6;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(button, INPUT_PULLUP);
}

void loop() {
    int buttonVal = digitalRead(button);
    if (buttonVal == LOW) {
        Serial.println("button =" + buttonVal);
        digitalWrite(LED, HIGH);
        for ( 0; buttonVal == LOW; digitalRead(button)) {
            digitalRead(button);
            int buttonVal = digitalRead(button);

        }
    }
    digitalWrite(LED, LOW);
    Serial.println("button =" + buttonVal);
}