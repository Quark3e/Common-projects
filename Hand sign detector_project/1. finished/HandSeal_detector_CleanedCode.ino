

int testLED = 2;
int signalingLED = 3;
int resetButton = 4;
int startButton = 5;

int clockPin = 6;
int clockPin2 = 7;
int latchPin = 8;
int dataPin = 9;
int dataPin2 = 10;

int breakVal = 0;
int signReadVal;

void FireballJutsu();
void LightningCutterJutsu();
void GalePalm();

byte handSealVar1 = 255;
byte handSealVar2 = 255;

boolean fireballCompare = true;
boolean chidoriCompare = true;
boolean reppushoCompare = true;

String jutsu[12];
//note: place jutsu's in length order
String Chidori[3] = {
    "Ox", "Hare", "Monkey"};
String Fireball[4] = {
    "Serpent", "Boar", "Horse", "Tiger"};    
String Reppusho[5] = {
    "Serpent", "Ram", "Boar", "Horse", "Bird"};


void setup () {
    
    Serial.begin(9600);

    pinMode(testLED, OUTPUT);
    pinMode(signalingLED, OUTPUT);
    pinMode(resetButton, INPUT_PULLUP);
    pinMode(startButton, INPUT_PULLUP);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(clockPin2, OUTPUT);
    pinMode(dataPin, INPUT);
    pinMode(dataPin2, INPUT);
}

void loop () {

    breakVal = 0;
    digitalRead(startButton);
    while (digitalRead(startButton) == HIGH) {digitalRead(startButton); delay(100);}

    digitalWrite(testLED, LOW);
    digitalWrite(signalingLED, LOW);


    for (int i=0; i<12; i++) {
        digitalWrite(latchPin, HIGH);
        delayMicroseconds(20);
        digitalWrite(latchPin, LOW);
        handSealVar1 = shiftIn(dataPin, clockPin);
        handSealVar2 = shiftIn(dataPin2, clockPin2);
        uint16_t handSeal = handSealVar1 | (handSealVar2<<8);
    
        Serial.println("----------");
        Serial.println(handSealVar1, BIN);
        Serial.println("----------");

        digitalRead(resetButton);
        if (digitalRead(resetButton) == LOW) {break;}

        switch (handSeal) {
            case 0b0000000000010011:
                Serial.println("Bird");
                jutsu[i]= "Bird";
                break;
            case 0b0111111000000001:
                Serial.println("Boar");
                jutsu[i]= "Boar";
                break;
            case 0b0001000100100000:
                Serial.println("Dog");
                jutsu[i]= "Dog";
                TestLEDActivation();
                break;
            case 0b0000000000010001:
                Serial.println("Dragon");
                jutsu[i]= "Dragon";
                break;
            case 0b0100000000000010:
                Serial.println("Hare");
                jutsu[i]= "Hare";
                break;
            case 0b0000000000000011:
                Serial.println("Horse (special case)");
                jutsu[i]= "Horse";
                break;
            case 0b1000111000001111:
                Serial.println("Monkey");
                jutsu[i]= "Monkey";
                break;
            case 0b0000000000001100:
                Serial.println("Ox");
                jutsu[i]= "Ox";
                break;
            case 0b0001111110000111:
                Serial.println("Ram");
                jutsu[i]= "Ram";
                break;
            case 0b0100000000100100:
                Serial.println("Rat");
                jutsu[i]= "Rat";
                break;
            case 0b0001111111100001:
                Serial.println("Serpent");
                jutsu[i]= "Serpent";
                break;
            case 0b0001111111100111:
                Serial.println("Tiger");
                jutsu[i]= "Tiger";
                break;
            default:
                Serial.println("Nothing. Nada, niet");
                if (i>=1) {i=i-1;}
        }
        digitalWrite(testLED, LOW);
        breakVal = 0;

        for (int n=0; n<=i; n++) {
            if (Chidori[n] = jutsu[n]) {}
            else {chidoriCompare = false;}
        }
        for (int n=0; n<=i; n++) {
            if (Fireball[n] = jutsu[n]) {}
            else {fireballCompare = false;}
        }
        for (int n=0; n<=i; n++) {
            if (Reppusho[n] = jutsu[n]) {}
            else {reppushoCompare = false;}
        }

        if (fireballCompare) {
            if (i=3) { FireStyle(FireballJutsu);} }
        else if (chidoriCompare) {
            if (i=2) { LightningStyle(LightningCutterJutsu);} }
        else if (reppushoCompare) {
            if (i=4) { WindStyle(GalePalm);} }
        else {break;}

        digitalRead(resetButton);
        if (digitalRead(resetButton) == LOW) {break;}

        delay(500);
        if (breakVal == 1) {break;}
        delay(1000);
    }

    Serial.println("---------- Restart ----------");
    SignalingLEDActivation();

    delay(500);
}


byte shiftIn(int myDataPin, int myClockPin) {
    int k;
    int temp = 0;
    int pinState;

    byte myDataIn = 0;

    pinMode(myClockPin, OUTPUT);
    pinMode(myDataPin, INPUT);

    for (k=7; k>=0; k--) {
        digitalWrite(myClockPin, 0);
        delayMicroseconds(0.2);
        temp = digitalRead(myDataPin);

        if (temp) {
            pinState = 1;
            myDataIn = myDataIn | (1 << k);
        }
        else {
            pinState = 0;
        }
        digitalWrite(myClockPin, 1);
    }
    return myDataIn;
}

void TestLEDActivation () {
    digitalWrite(testLED, HIGH);
    delay(100);
    digitalWrite(testLED, LOW);
    delay(100);
    digitalWrite(testLED, HIGH);
    delay(100);
    digitalWrite(testLED, LOW);
    delay(100);
    digitalWrite(testLED, HIGH);
    delay(1000);
}

void SignalingLEDActivation () {
    delayMicroseconds(1000);
    digitalWrite(signalingLED, HIGH);
    delayMicroseconds(1000);
    digitalWrite(signalingLED, LOW);
    delayMicroseconds(1000);
    digitalWrite(signalingLED, HIGH);
    delayMicroseconds(1000);
    digitalWrite(signalingLED, LOW);
    delayMicroseconds(1000);
    digitalWrite(signalingLED, HIGH);
    delayMicroseconds(1000);
    digitalWrite(signalingLED, LOW);
}


void LightningStyle(int LightningCutterJutsu) {
    Serial.println("Raiton: Chidori");
    breakVal = 1;
}
void FireStyle(int FireballJutsu) {
    Serial.println("Katon: Goukakyuu no Jutsu");
    breakVal = 1;
}
void WindStyle(int GalePalm) {
    Serial.println("Futon: Reppusho");
    breakVal = 1;
}
//letters used: i, k, n, 