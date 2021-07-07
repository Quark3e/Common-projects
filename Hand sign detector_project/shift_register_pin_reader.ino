

int resetButton = 4;
int startButton = 5;

int clockPin = 6;
int clockPin2 = 7;
int latchPin = 8;
int dataPin = 9;
int dataPin2 = 10;

int breakVal = 0;
int signReadVal;

byte handSealVar1 = 255;
byte handSealVar2 = 255;

char inputBits[16][5] = {
    "Lb1", "Lb2", "Lb3", "Lb4", "Lb5", "Lb6", "Lb7", "Lb8",
    "Lb9", "Lb10", "Lb11", "Lb12", "Lb13", "Lf2", "Lf3", "Lf9" };


void setup () {
    
    Serial.begin(9600);

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

    digitalWrite(latchPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(latchPin, LOW);

    handSealVar1 = shiftIn(dataPin, clockPin);
    handSealVar2 = shiftIn(dataPin2, clockPin2);
    uint16_t handSeal = handSealVar1 | (handSealVar2<<8);

    for (int n=0; n<=15; n++) {
        if (handSeal & (1 << n) ){
            Serial.println(inputBits[n]);
            Serial.println("------------");
        }
    }
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
