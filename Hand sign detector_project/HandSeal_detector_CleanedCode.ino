

int testLED = 2;
int signalingLED = 3;
int resetButton = 4;
int startButton = 5;
int clockPin = 7;
int latchPin = 8;
int dataPin = 9;
int dataPin2 = 10;
int breakVal = 0;

int signReadVal;

int FireballJutsu;
int LightningCutterJutsu;

byte handSealVar1 = 65535;
byte handSealVar2 = 65535;

char inputBits[] = {
    'Lb1', 'Lb2', 'Lb3', 'Lb4', 'Lb5', 'Lb6', 'Lb7', 'Lb8',
    'Lb9', 'Lb10', 'Lb11', 'Lb12', 'Lb13', 'Lf2', 'Lf3', 'Lf9'};
char jutsu[12] = {
    'null'};

char Fireball[4] = {
    'Serpent', 'Boar', 'Horse', 'Tiger'};
char Chidori[3] = {
    'Ox', 'Hare', 'Monkey'};
char Reppusho[5] = {
    'Serpent', 'Ram', 'Boar', 'Horse', 'Bird'};
    

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
        handSealVar2 = shiftIn(dataPin2, clockPin);
        handSealVar2 = (handSealVar2<<8) + handSealVar1;
    
        Serial.println(handSealVar1, BIN);
    
        if (resetButton == LOW) {break;}

        switch (handSealVar2) {
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

    Serial.println("Restart -------------------");

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


void FireStyle(int FireballJutsu) {
    Serial.println("Katon: Goukakyuu no Jutsu");
    breakVal = 1;
}

void LightningStyle(int LightningCutterJutsu) {
    Serial.println("Raiton: Chidori");
    breakVal = 1;
}