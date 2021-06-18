

int clockPin = 7;
int latchPin = 8;
int dataPin = 9;
int dataPin2 = 10;
int dataPin3 = 11;

byte handsignVar1 = 72;
byte handsignVar2 = 72;
byte handsignVar3 = 72;


char inputBits[] = {
    'Lb1', 'Lb2', 'Lb3', 'Lb4', 'Lb5', 'Lb6', 'Lb7', 'Lb8',
    'Lb9', 'Lb10', 'Lb11', 'Lb12', 'Lb13', 'null1', 'null2', 'null3'};

void setup () {
    
    Serial.begin(9600);

    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);
    pinMode(dataPin2, INPUT);
    pinMode(dataPin3, INPUT);

}

void loop () {

    digitalWrite(latchPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(latchPin, LOW);

    handsignVar1 = shiftIn(dataPin, clockPin);
    handsignVar2 = shiftIn(dataPin2, clockPin);
    handsignVar3 = shiftIn(dataPin3, clockPin);

    // Serial.println(handsignVar1, BIN);

    // for (int n=0; n<=7; n++) {
    //     if (handsignVar1 & (1 << n) ) { Serial.println(inputBits[n]); }
    // }

    //NOTE: the bits are written from right to left
    // i.e bit to the right is first char character
    // so the furthest left bit (like the 1 in 10000000)
    // is the bit from pin 7 on the shift register starting from pin 0

    switch (handsignVar1) {

        case 0b00010011:
            Serial.println("Bird (1/2)");
            break;
        
        case 0b00000001:
            Serial.println("Boar (1/2)");
            break;

        case 0b00100000:
            Serial.println("Dog (1/2)");
            break;

        case 0b00010001:
            Serial.println("Dragon (1/2)");
            break;

        case 0b00000010:
            Serial.println("Hare (1/2)");
            break;

        case 0b00000011:
            Serial.println("Horse (full (special case))");
            break;

        case 0b00001111:
            Serial.println("Monkey (1/2)");
            break;

        case 0b00001100:
            Serial.println("Ox (full)");
            break;

        case 0b10000111:
            Serial.println("Ram (1/2)");
            break;

        case 0b00100100:
            Serial.println("Rat (1/2)");
            break;

        case 0b11100001:
            Serial.println("Serpent (1/2)");
            break;

        case 0b11100111:
            Serial.println("Tiger (1/2)");
            break;

        default:
            Serial.println("Nothing. Nada, niet");
    }

    
    Serial.println("-------------------");
    
    delay(500); //crucial delay!
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

            //set the bit to 0 no matter what
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