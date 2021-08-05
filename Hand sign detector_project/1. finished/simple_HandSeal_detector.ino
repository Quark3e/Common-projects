//This is a simpler version that uses the arduino's onboard pin's instead.
//Much more rudimental.

String jutsu[12];
//note: place jutsu's in length order
String Chidori[3] = {
    "Ox", "Hare", "Monkey"};
String Fireball[4] = {
    "Serpent", "Boar", "Horse", "Tiger"};    
String Reppusho[5] = {
    "Serpent", "Ram", "Boar", "Horse", "Bird"};


int contactPin_1 = 2;
int contactPin_2 = 3;
int contactPin_3 = 4;
int contactPin_4 = 5;
int contactPin_5 = 6;
int contactPin_6 = 7;
int contactPin_7 = 8;
int contactPin_8 = 9;

int startButton = 10;
int resetLED = 12;
int testLED = 13;

int breakVal = 0;

byte contactReader_function();
void arrayCreator_function(byte byteVar, int i);
bool boolFunction(String ArrayVal, int j);

void FireBall_Jutsu();
void LightningCutter_Jutsu();
void GalePalm();

byte handSealVar1 = 255;
byte handSealVar2 = 255;

boolean fireballCompare = true;
boolean chidoriCompare = true;
boolean reppushoCompare = true;


void setup () {
    
    Serial.begin(9600);

    pinMode(contactPin_1, INPUT_PULLUP);
    pinMode(contactPin_2, INPUT_PULLUP);
    pinMode(contactPin_3, INPUT_PULLUP);
    pinMode(contactPin_4, INPUT_PULLUP);
    pinMode(contactPin_5, INPUT_PULLUP);
    pinMode(contactPin_6, INPUT_PULLUP);
    pinMode(contactPin_7, INPUT_PULLUP);
    pinMode(contactPin_8, INPUT_PULLUP);
    pinMode(startButton, INPUT_PULLUP);
    pinMode(resetLED, OUTPUT);
    pinMode(testLED, OUTPUT);
}

void loop () {


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
        uint
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
            if (i=3) { FireStyle(FireBall_Jutsu);} }
        else if (chidoriCompare) {
            if (i=2) { LightningStyle(LightningCutter_Jutsu);} }
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
    resetLED_activation();

    delay(500);
}

byte contactReader_function() {
    byte returnValue = 72;
    int val1 != digitalRead(contactPin_1);
    int val2 != digitalRead(contactPin_2);
    int val3 != digitalRead(contactPin_3);
    int val4 != digitalRead(contactPin_4);
    int val5 != digitalRead(contactPin_5);
    int val6 != digitalRead(contactPin_6);
    int val7 != digitalRead(contactPin_7);
    int val8 != digitalRead(contactPin_8);

    if ()

    return returnValue;
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

void resetLED_activation () {
    delayMicroseconds(1000);
    digitalWrite(resetLED, HIGH);
    delayMicroseconds(1000);
    digitalWrite(resetLED, LOW);
    delayMicroseconds(1000);
    digitalWrite(resetLED, HIGH);
    delayMicroseconds(1000);
    digitalWrite(resetLED, LOW);
    delayMicroseconds(1000);
    digitalWrite(resetLED, HIGH);
    delayMicroseconds(1000);
    digitalWrite(resetLED, LOW);
}

bool boolFunction(string ArrayVal, int j) {
    bool boolAnswer = true;
	if (ArrayVal == testArray[j]) {}
    else {boolAnswer = false;}
	return boolAnswer;
}
void LightningStyle(int LightningCutter_Jutsu) {
    Serial.println("Raiton: Chidori");
    breakVal = 1;
}
void FireStyle(int FireBall_Jutsu) {
    Serial.println("Katon: Goukakyuu no Jutsu");
    breakVal = 1;
}
void WindStyle(int GalePalm) {
    Serial.println("Futon: Reppusho");
    breakVal = 1;
}
//letters used: i, j, k, n, 