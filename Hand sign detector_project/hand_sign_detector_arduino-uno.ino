

int clockPin = 7;
int latchPin = 8;
int dataPin = 9;
int dataPin2 = 10;

byte handsignVar1 = 65535; //65,535 = 11111111 11111111
byte handsignVar2 = 65535;

char inputBits[] = {
    'Lb1', 'Lb2', 'Lb3', 'Lb4', 'Lb5', 'Lb6', 'Lb7', 'Lb8',
    'Lb9', 'Lb10', 'Lb11', 'Lb12', 'Lb13', 'Lf2', 'Lf3', 'Lf9'};

    

void setup () {
    
    Serial.begin(9600);

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

    // for (int n=0; n<=15; n++) {
    //     if (handsignVar1 & (1 << n) ) { Serial.println(inputBits[n]); }
    // }

    //NOTE: the bits are written from right to left
    // i.e bit to the right is first char character
    // so the furthest left bit (like the 1 in 10000000)
    // is the bit from pin 7 on the shift register starting from pin 0

    switch (handsignVar1) {

        case 0b0000000000010011:
            Serial.println("Bird");
            break;
        
        case 0b0111111000000001:
            Serial.println("Boar");
            break;

        case 0b0001000100100000:
            Serial.println("Dog");
            break;

        case 0b0000000000010001:
            Serial.println("Dragon");
            break;

        case 0b0100000000000010:
            Serial.println("Hare");
            break;

        case 0b0000000000000011:
            Serial.println("Horse (special case)");
            break;

        case 0b1000111000001111:
            Serial.println("Monkey");
            break;

        case 0b0000000000001100:
            Serial.println("Ox");
            break;

        case 0b0001111110000111:
            Serial.println("Ram");
            break;

        case 0b0100000000100100:
            Serial.println("Rat");
            break;

        case 0b0001111111100001:
            Serial.println("Serpent");
            break;

        case 0b0001111111100111:
            Serial.println("Tiger");
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