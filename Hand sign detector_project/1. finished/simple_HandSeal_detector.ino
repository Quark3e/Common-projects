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
int signalingLED = 11;
int resetLED = 12;
int testLED = 13;

int breakVal = 0;

byte contactReader_function();
void arrayCreator_function(byte byteVar, int i);
bool Chidori_compareFunc();
bool Fireball_compareFunc();
bool Reppusho_compareFunc();

bool boolFunction(String ArrayVal, int j);

void FireBall_Jutsu();
void LightningCutter_Jutsu();
void GalePalm();


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
    pinMode(signalingLED, OUTPUT);
    pinMode(resetLED, OUTPUT);
    pinMode(testLED, OUTPUT);
}

void loop () {
    digitalWrite(signalingLED, LOW);
    while (startButton) {digitalRead(startButton);}
    digitalWrite(signalingLED, HIGH);
    delay(1000);
    digitalWrite(signalingLED, LOW);
    bool checker = true;
    byte checker_compare = 1;
    while (checker) {
        if (contactReader_function() >= checker_compare) {checker = false;}
    }
    
}

byte contactReader_function() {
    byte returnValue = 0;
    int val1 != digitalRead(contactPin_1);
    int val2 != digitalRead(contactPin_2);
    int val3 != digitalRead(contactPin_3);
    int val4 != digitalRead(contactPin_4);
    int val5 != digitalRead(contactPin_5);
    int val6 != digitalRead(contactPin_6);
    int val7 != digitalRead(contactPin_7);
    int val8 != digitalRead(contactPin_8);

    if (val1) {returnValue = returnValue | 1}
    if (val2) {returnValue = returnValue | (1<<2);}
    if (val3) {returnValue = returnValue | (1<<3);}
    if (val4) {returnValue = returnValue | (1<<4);}
    if (val5) {returnValue = returnValue | (1<<5);}
    if (val6) {returnValue = returnValue | (1<<6);}
    if (val7) {returnValue = returnValue | (1<<7);}
    if (val8) {returnValue = returnValue | (1<<8);}

    return returnValue;
}

void arrayCreator_function(byte byteVar, int i) {
    switch (byteVar) {
        case 0b:
            Serial.println("Bird");
            jutsu[i]= "Bird";
            break;
        case 0b:
            Serial.println("Boar");
            jutsu[i]= "Boar";
            break;
        case 0b:
            Serial.println("Dog");
            jutsu[i]= "Dog";
            break;
        case 0b:
            Serial.println("Dragon");
            jutsu[i]= "Dragon";
            break;
        case 0b:
            Serial.println("Hare");
            jutsu[i]= "Hare";
            break;
        case 0b:
            Serial.println("Horse");
            jutsu[i]= "Horse";
            break;
        case 0b:
            Serial.println("Monkey");
            jutsu[i]= "Monkey";
            break;
        case 0b:
            Serial.println("Ox");
            jutsu[i]= "Ox";
            break;
        case 0b:
            Serial.println("Ram");
            jutsu[i]= "Ram";
            break;
        case 0b:
            Serial.println("Rat");
            jutsu[i]= "Rat";
            break;
        case 0b:
            Serial.println("Serpent");
            jutsu[i]= "Serpent";
            break;
        case 0b:
            Serial.println("Tiger");
            jutsu[i]= "Tiger";
            break;
    }
}

bool Chidori_compareFunc() {
    bool returnVal = true;
    for (int n=0; n<3; n++) {
        if (Chidori[n] = jutsu[n]) {}
        else {returnVal = false;}
    }
    return returnVal;
}
bool Fireball_compareFunc() {
    bool returnVal = true;
    for (int n=0; n<4; n++) {
        if (Fireball[n] = jutsu[n]) {}
        else {returnVal = false;}
    }
    return returnVal;
}
bool Reppusho_compareFunc() {
    bool returnVal = true;
    for (int n=0; n<5; n++) {
        if (Chidori[n] = jutsu[n]) {}
        else {returnVal = false;}
    }
    return returnVal;
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