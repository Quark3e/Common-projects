
int button = 4;
int latchPin = 8;
int dataPin = 9;
int clockPin = 7;

byte switchVar1 = 72;

char arrayVal[] = {
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};


void setup() {

  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, INPUT);
  pinMode(button, INPUT_PULLUP);

}

void loop() {

  Serial.println("NEWLINE-------------------");
  while (digitalRead(button) == HIGH) {digitalRead(button);};

  digitalWrite(latchPin,1);
  delayMicroseconds(20);
  digitalWrite(latchPin,0);


  switchVar1 = shiftIn(dataPin, clockPin, MSBFIRST);
  delay(100);
  Serial.println(switchVar1, BIN);

  for (int n=0; n<=7; n++)
  {
    if (switchVar1 & (1 << n) ){
      Serial.println(arrayVal[n]);
    }
  Serial.println("-------------------");
  }

  switch (switchVar1) {

  case 0b00101010:
    Serial.println("D minor");
    break;

  case 0b00010101:
    Serial.println("C major");
    break;

  case 0b01010100:
    Serial.println("E minor");
    break;

  case 0b00101001:
    Serial.println("F major");
    break;

  case 0b01010010:
    Serial.println("G major");
    break;

  case 0b00100101:
    Serial.println("A minor");
    break;

  case 0b01001010:
    Serial.println("B diminished");
    break;

  default:
    Serial.println("Play It, Joe");

  }
Serial.println("-------------------");

delay(1000);

}

// byte shiftIn(int myDataPin, int myClockPin) {
//   int i;
//   int temp = 0;
//   int pinState;
//   byte myDataIn = 0;
//   pinMode(myClockPin, OUTPUT);
//   pinMode(myDataPin, INPUT);
//   for (i=7; i>=0; i--)
//   {
//     digitalWrite(myClockPin, 0);
//     delayMicroseconds(0.2);
//     temp = digitalRead(myDataPin);
//     if (temp) {
//       pinState = 1;
//       myDataIn = myDataIn | (1 << i);
//     }
//     else {
//       pinState = 0;
//     }
//     digitalWrite(myClockPin, 1);
//   }
//   return myDataIn;
// }
