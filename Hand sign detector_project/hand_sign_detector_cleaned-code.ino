

int resetButton = 4;
int startButton = 5;
int clockPin = 7;
int latchPin = 8;
int dataPin = 9;
int dataPin2 = 10;
int signalingLED = 3;

int breakVal = 0;

byte handsignVar1 = 65535;
byte handsignVar2 = 65535;

char inputBits[] = {
    'Lb1', 'Lb2', 'Lb3', 'Lb4', 'Lb5', 'Lb6', 'Lb7', 'Lb8',
    'Lb9', 'Lb10', 'Lb11', 'Lb12', 'Lb13', 'Lf2', 'Lf3', 'Lf9'};
char jutsu[12] = {
    'null'};

char fireballJutsu[12] = {
    'Serpent', 'Ram', 'Monkey', 'Boar', 'Horse', 'Tiger'};


void setup () {
    
    Serial.begin(9600);

    pinMode(signalingLED, OUTPUT);
    pinMode(resetButton, INPUT_PULLUP);
    pinMode(startButton, INPUT_PULLUP);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);
    pinMode(dataPin2, INPUT);
}

void loop () {

    digitalRead(startButton);
    while (startButton == HIGH) {digitalRead(startButton); delay(100);}

    digitalWrite(signalingLED, LOW);
    for (int i=0; i<12; i++) {

        digitalWrite(latchPin, HIGH);
        delayMicroseconds(20);
        digitalWrite(latchPin, LOW);
        handsignVar1 = shiftIn(dataPin, clockPin);
        handsignVar2 = shiftIn(dataPin2, clockPin);
        handsignVar2 = (handsignVar2<<8) + handsignVar1;
    
        Serial.println(handsignVar1, BIN);
    
        if (resetButton == LOW) {break;}

        switch (handsignVar2) {
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
        breakVal = 0;
        for (int j=0; j<=i; j++) { if (jutsu[j] != fireballJutsu[j]) {breakVal = 1; break;} }
        delay(100);
        if (breakVal == 1) {break;}

        

        delay(1000);
    }

    Serial.println("-------------------");

    delay(1000);
    digitalWrite(signalingLED, HIGH);
    delay(1000);
    digitalWrite(signalingLED, LOW);
    delay(1000);
    digitalWrite(signalingLED, HIGH);
    delay(1000);
    digitalWrite(signalingLED, LOW);
    delay(1000);
    digitalWrite(signalingLED, HIGH);
    delay(1000);
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

// void SignReader()