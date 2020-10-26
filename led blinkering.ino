int led = 7;

void setup () {
    Serial.begin(115200);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
}

void loop () {
    digitalWrite(led, HIGH);
    delay(1000);
}