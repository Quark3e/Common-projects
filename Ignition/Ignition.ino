#include <Servo.h>

Servo myservo;

int sound_sensor = A0; 
int led1 = 13;
int solenoid = 11;
int relay = 9;
int flame = 2;
int pos = 0;
int flame_sensor = A2; // variable to store the value coming from the sensor
int buttonPin = 12;

const int max_SoundThresh = 461;
const int min_SoundThresh = 473;
const int FlameThresh = 1050;

                                 
void setup()
{
  Serial.begin(9600);
 
  
  pinMode(led1, OUTPUT);
  pinMode(solenoid, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(flame, INPUT);
  pinMode(flame_sensor, INPUT);
  pinMode(sound_sensor, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  myservo.attach(10); //need to check this one again if it's possible to write it in a different way
}



void loop()
{
  //analogRead(sound_sensor);
  //int analogSoundVal = analogRead(sound_sensor);
  //analogRead(sound_sensor);
  //Serial.println(analogRead(sound_sensor));
  //delay(10);
  
    int analogSoundVal = analogRead(sound_sensor);
    analogRead(sound_sensor);
    
    //Serial.println(analogRead(sound_sensor));
    //delay(10);

    if (analogSoundVal >= max_SoundThresh) {
    //int buttonValue = digitalRead(buttonPin);
    //if (buttonValue == LOW) {
      //if (analogSoundVal >= max_SoundThresh) {
      //int analogPerma = analogSoundVal;
      if (analogSoundVal <= min_SoundThresh) {
        //Serial.print("CLAP DETECTED! ");
        //Serial.print("Sensor Value: ");
        //Serial.println(analogRead(sound));
        //Serial.println(digitalRead(buttonPin));
  
        digitalWrite(led1, HIGH);

        for (pos = 92; pos <= 130; pos+=1) { //92 degrees is the home position of the servo
        myservo.write(pos);
        delay(10);
        }

        delay(1000);

        for (int i=0; i<=35; i++) { //time period where the relay is closed/in-contact
          digitalWrite(relay, HIGH);
          delay(10);
        }

        digitalWrite(relay, LOW);

        int analogFlameVal = analogRead(flame_sensor);
        analogRead(flame_sensor);
        
        //int x = buttonValue;
        delay(100);
        //int buttonValue = digitalRead(buttonPin);
        //delay(100);
    
        //for (0; buttonValue == 0; digitalRead(buttonPin)){
        for (0; analogFlameVal >= FlameThresh; analogRead(flame_sensor)) {
          //delay(100);
          //digitalRead(buttonPin);
          //int buttonValue = digitalRead(buttonPin);
          //Serial.println(digitalRead(buttonValue));
          //Serial.println(analogRead(analogFlameVal));
          analogRead(flame_sensor);
          int analogFlameVal = analogRead(flame_sensor);
          if (analogFlameVal < FlameThresh) {
          //if (buttonValue == 1) {
            break;
          }
          //}
        }
        //Serial.println(buttonValue);
        //Serial.println(analogFlameVal);
    
        for (pos = 130; pos >= 92; pos-=1) { //turn servo motor back //closing butane valve
        myservo.write(pos);
        delay(10);
        }
        digitalWrite(led1, LOW);
        delay(1000);
        }
    }

// separate activation method ----------------------------------------------------------------------------------------


  int buttonValue = digitalRead(buttonPin);
  if (buttonValue == LOW) {
    for (pos = 92; pos <= 130; pos+=1) { //92 degrees is the home position of the servo
        myservo.write(pos);
        delay(10);
        }
    delay(1000);
    for (int i=0; i<=49; i++) { //time period where the relay is closed/in-contact
          digitalWrite(relay, HIGH);
          delay(10);
        }
    for ( 0; buttonValue == 0; digitalRead(buttonPin)) {
          //delay(100);
          digitalRead(buttonPin);
          int buttonValue = digitalRead(buttonPin);
          Serial.println(digitalRead(buttonValue));
          //int buttonValue = digitalRead(buttonPin);
          //Serial.println(analogRead(analogFlameVal));
          //analogFlameVal = analogRead(A2);
          if (buttonValue == 1) {
            break;
          }
        }
       for (pos = 130; pos >= 92; pos-=1) {
       myservo.write(pos);
       delay(10);
       //the sequence ends
       }
  }
}
  
