

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

int FireballJutsu;
int LightningCutterJutsu;

byte handSealVar1 = 255;
byte handSealVar2 = 255;


char jutsu[12];
char Fireball[4] = {
    'p', 'b', 'f', 'o'};
char Chidori[3] = {
    'h', 'e', 'g'}; 
char Reppusho[5] = {
    'p', 'l', 'b', 'f', 'a'};


void setup () {
    
    Serial.begin(9600);

    pinMode(testLED, OUTPUT);
    pinMode(signalingLED, OUTPUT);
    pinMode(resetButton, INPUT_PULLUP);
    pinMode(startButton, INPUT_PULLUP);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);
    pinMode(dataPin2, INPUT);
}

void loop () {

    breakVal = 0;
    digitalRead(startButton);
    while (startButton == HIGH) {digitalRead(startButton); delay(100);}

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
        if (resetButton == LOW) {break;}

        switch (handSeal) {
            case 0b0000000000010011:
                Serial.println("Bird");
                jutsu[i]= 'a';
                break;
            case 0b0111111000000001:
                Serial.println("Boar");
                jutsu[i]= 'b';
                break;
            case 0b0001000100100000:
                Serial.println("Dog");
                jutsu[i]= 'c';
                TestLEDActivation();
                break;
            case 0b0000000000010001:
                Serial.println("Dragon");
                jutsu[i]= 'd';
                break;
            case 0b0100000000000010:
                Serial.println("Hare");
                jutsu[i]= 'e';
                break;
            case 0b0000000000000011:
                Serial.println("Horse");
                jutsu[i]= 'f';
                break;
            case 0b1000111000001111:
                Serial.println("Monkey");
                jutsu[i]= 'g';
                break;
            case 0b0000000000001100:
                Serial.println("Ox");
                jutsu[i]= 'h';
                break;
            case 0b0001111110000111:
                Serial.println("Ram");
                jutsu[i]= 'l';
                break;
            case 0b0100000000100100:
                Serial.println("Rat");
                jutsu[i]= 'm';
                break;
            case 0b0001111111100001:
                Serial.println("Serpent");
                jutsu[i]= 'p';
                break;
            case 0b0001111111100111:
                Serial.println("Tiger");
                jutsu[i]= 'o';
                break;
            default:
                Serial.println("Nothing. Nada, niet");
                if (i>=1) {i=i-1;}
        }
        digitalWrite(testLED, LOW);
        breakVal = 0;

        if (jutsu[0] == Fireball[0]) {
            for (int j=0; j<=i; j++) {
                if (jutsu[j] != Fireball[j]) {breakVal = 1; break;}
                if (j == 3) { FireStyle(FireballJutsu); }
            }
        } else if (jutsu[0] == Chidori[0]) {
            for (int j=0; j<=i; j++) {
                if (jutsu[j] != Fireball[j]) {breakVal = 1; break;} 
                if (j == 2) { LightningStyle(LightningCutterJutsu); }
            }
        }   else { breakVal = 1; }

        digitalRead(resetButton);
        if (resetButton == LOW) {break;}

        delay(500);
        if (breakVal == 1) {break;}
        delay(1000);
    }

    Serial.println("---------- Restart ----------");

    delay(1000);
    digitalWrite(signalingLED, HIGH);
    delay(900);
    digitalWrite(signalingLED, LOW);
    delay(700);
    digitalWrite(signalingLED, HIGH);
    delay(500);
    digitalWrite(signalingLED, LOW);
    delay(300);
    digitalWrite(signalingLED, HIGH);
    delay(100);
    digitalWrite(signalingLED, LOW);
    delay(100);
    digitalWrite(signalingLED, HIGH);
    delay(100);
    digitalWrite(signalingLED, LOW);

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

void FireStyle(int FireballJutsu) {
    Serial.println("Katon: Goukakyuu no Jutsu");
    breakVal = 1;
}

void LightningStyle(int LightningCutterJutsu) {
    Serial.println("Raiton: Chidori");
    breakVal = 1;
}

//letters used: i, j, k, 