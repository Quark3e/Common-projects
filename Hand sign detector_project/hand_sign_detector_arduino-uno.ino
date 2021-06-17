
int latchPin = 8;
int dataPin = 9;
int clockPin = 7;

byte handsignVar1 = 72;

char inputBits[] = {
    'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7', 'p8'};

void setup () {
    
    Serial.begin(9600);

    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);

}

void loop () {

    digitalWrite(latchPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(latchPin, LOW);

    handsignVar1 = shiftIn(dataPin, clockPin);

    Serial.println(handsignVar1, BIN);

    for (int n=0; n<=7; n++) {
        if (handsignVar1 & (1 << n) ) { Serial.println(inputBits[n]); }
    }

    //note: the bits are written from right to left
    // i.e bit to the right is first char character
    // so the furthest left bit (like the 1 in 10000000)
    // is the bit from pin 7 on the shift register

    switch (handsignVar1) {

        case :
            Serial.println("");
            break;
        
        case :
            Serial.println("");
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