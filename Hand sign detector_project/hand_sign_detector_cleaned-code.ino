
int resetButton = 4;

int clockPin = 7;
int latchPin = 8;
int dataPin = 9;
int dataPin2 = 10;

byte handsignVar1 = 65535;
byte handsignVar2 = 65535;

char inputBits[] = {
    'Lb1', 'Lb2', 'Lb3', 'Lb4', 'Lb5', 'Lb6', 'Lb7', 'Lb8',
    'Lb9', 'Lb10', 'Lb11', 'Lb12', 'Lb13', 'Lf2', 'Lf3', 'Lf9'};

char jutsu[12];

char fireballJutsu[12] = {
    'Serpent', 'Ram', 'Monkey', 'Boar', 'Horse', 'Tiger'};


void setup () {
    
    Serial.begin(9600);

    pinMode(resetButton, INPUT_PULLUP);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);
    pinMode(dataPin2, INPUT);
}

void loop () {

    digitalWrite(latchPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(latchPin, LOW);
    handsignVar1 = shiftIn(dataPin, clockPin);
    handsignVar2 = shiftIn(dataPin2, clockPin);
    handsignVar2 = (handsignVar2<<8) + handsignVar1;
    
    Serial.println(handsignVar1, BIN);

    int a;
    for ( a=0; a<12; a++) {
        if (resetButton == LOW) {break;}
        switch (handsignVar2) {
            case 0b0000000000010011:
                Serial.println("Bird");
                jutsu[a]= "Bird";
                break;
            case 0b0111111000000001:
                Serial.println("Boar");
                jutsu[a]= "Boar";
                break;
            case 0b0001000100100000:
                Serial.println("Dog");
                jutsu[a]= "Dog";
                break;
            case 0b0000000000010001:
                Serial.println("Dragon");
                jutsu[a]= "Dragon";
                break;
            case 0b0100000000000010:
                Serial.println("Hare");
                jutsu[a]= "Hare";
                break;
            case 0b0000000000000011:
                Serial.println("Horse (special case)");
                jutsu[a]= "Horse";
                break;
            case 0b1000111000001111:
                Serial.println("Monkey");
                jutsu[a]= "Monkey";
                break;
            case 0b0000000000001100:
                Serial.println("Ox");
                jutsu[a]= "Ox";
                break;
            case 0b0001111110000111:
                Serial.println("Ram");
                jutsu[a]= "Ram";
                break;
            case 0b0100000000100100:
                Serial.println("Rat");
                jutsu[a]= "Rat";
                break;
            case 0b0001111111100001:
                Serial.println("Serpent");
                jutsu[a]= "Serpent";
                break;
            case 0b0001111111100111:
                Serial.println("Tiger");
                jutsu[a]= "Tiger";
                break;
            default:
                Serial.println("Nothing. Nada, niet");
                if (a>=1) {a=a-1;}
        }
        delay(100);
    }

    // for (int n=0; n<=15; n++) {
    //     if (handsignVar2 & (1 << n) ) { Serial.println(inputBits[n]); }
    // }

    Serial.println("-------------------");

    delay(500);

    int b = 0;
    if (jutsu[b] == fireballJutsu[b]) {
        b=b+1;
        if (jutsu[b] == fireballJutsu[b]) {
            b=b+1;
            if (jutsu[b] == fireballJutsu[b]) {
                b=b+1;
                if (jutsu[b] == fireballJutsu[b]) {
                    b=b+1;
                    if (jutsu[b] == fireballJutsu[b]) {
                        b=b+1;
                        if (jutsu[b] == fireballJutsu[b]) {
                            b=b+1;
                            if (jutsu[b] == fireballJutsu[b]) {
                                b=b+1;
                                if (jutsu[b] == fireballJutsu[b]) {
                                    b=b+1;
                                    if (jutsu[b] == fireballJutsu[b]) {
                                        b=b+1;
                                        if (jutsu[b] == fireballJutsu[b]) {
                                            b=b+1;
                                            if (jutsu[b] == fireballJutsu[b]) {
                                                b=b+1;
                                                if (jutsu[b] == fireballJutsu[b]) {
                                                    
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

byte shiftIn(int myDataPin, int myClockPin) {
    int i;
    int temp = 0;
    int pinState;

    byte myDataIn = 0;

    pinMode(myClockPin, OUTPUT);
    pinMode(myDataPin, INPUT);

    for (i=7; i>=0; i--) {
        digitalWrite(myClockPin, 0);
        delayMicroseconds(0.2);
        temp = digitalRead(myDataPin);

        if (temp) {
            pinState = 1;

            myDataIn = myDataIn | (1 << i);
        }
        else {
            pinState = 0;
        }
        digitalWrite(myClockPin, 1);
    }

    return myDataIn;
}

// void SignReader()