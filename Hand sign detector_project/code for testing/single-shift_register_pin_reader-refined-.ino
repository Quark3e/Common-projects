int button = 4;
int latchPin = 8;
int dataPin = 9;
int clockPin = 7;
byte switchVar1 = 255;
char arrayVal[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
byte shiftIn(int myDataPin, int myClockPin) {
int i;
int temp = 0;
int pinState;
byte myDataIn = 0;
pinMode(myClockPin, OUTPUT);
pinMode(myDataPin, INPUT);
for (i=7; i>=0; i--)
{
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
Serial.print(pinState);
Serial.print("shit");
Serial.println (myDataIn, BIN);
digitalWrite(myClockPin, 1);
}
return myDataIn;
}
void setup() {
Serial.begin(9600);
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, INPUT);
pinMode(button, INPUT_PULLUP);
}
void loop() {
Serial.println("NEWLINE-----");
while (digitalRead(button) == HIGH) {digitalRead(button);};
digitalWrite(latchPin,1);
delayMicroseconds(20);
digitalWrite(latchPin,0);
switchVar1 = shiftIn(dataPin, clockPin);
delay(100);
Serial.println(switchVar1, BIN);
delay(1000);
}