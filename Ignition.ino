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

const int max_threshold = 461;
const int min_threshold = 473;

                                 
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
  //int analogValue = analogRead(sound_sensor);
  //analogRead(sound_sensor);
  //Serial.println(analogRead(sound_sensor));
  //delay(10);
    int analogValue = analogRead(sound_sensor);
    analogRead(sound_sensor);
    //Serial.println(analogRead(sound_sensor));
    //delay(10);

    if (analogValue >= max_threshold) {

    int buttonValue = digitalRead(buttonPin);

    //if (buttonValue == LOW) {

    //if (analogValue >= max_threshold) {
      //int analogPerma = analogValue;
     // if (analogPerma <= min_threshold) {
        //Serial.print("CLAP DETECTED! ");
        //Serial.print("Sensor Value: ");
        //Serial.println(analogRead(sound));

        Serial.println(digitalRead(buttonPin));
  
        digitalWrite(led1, HIGH);
        for (pos = 92; pos <= 130; pos+=1) { //92 degrees is the home position of the servo
        myservo.write(pos);
        delay(10);
        }
        delay(1000);
    
        for (int i=0; i<=35; i++) {
          digitalWrite(relay, HIGH);
          delay(10);
        }
        digitalWrite(relay, LOW);

        //delay(2000);
    
        //flame_sensor = analogRead(A2);
        
        //int x = buttonValue;
        delay(100);
        //int buttonValue = digitalRead(buttonPin);
        delay(100);
    
        for ( 0; buttonValue == 0; digitalRead(buttonPin)){
          //delay(100);
          digitalRead(buttonPin);
          int buttonValue = digitalRead(buttonPin);
          Serial.println(digitalRead(buttonValue));
          //int buttonValue = digitalRead(buttonPin);
          //Serial.println(analogRead(flame_sensor));
          //flame_sensor = analogRead(A2);
          if (buttonValue == 1) {
            break;
          }
        }
        Serial.println(buttonValue);
    
        //Serial.println(flame_sensor);
    
        for (pos = 130; pos >= 92; pos-=1) {
        myservo.write(pos);
        delay(10);
        }
        digitalWrite(led1, LOW);
        delay(1000);
    //}
  }

  int buttonValue = digitalRead(buttonPin);
  if (buttonValue == LOW) {
    for (pos = 92; pos <= 130; pos+=1) { //92 degrees is the home position of the servo
        myservo.write(pos);
        delay(10);
        }
    delay(1000);
    digitalWrite(relay, HIGH);
    for ( 0; buttonValue == 0; digitalRead(buttonPin)) {
          //delay(100);
          digitalRead(buttonPin);
          int buttonValue = digitalRead(buttonPin);
          Serial.println(digitalRead(buttonValue));
          //int buttonValue = digitalRead(buttonPin);
          //Serial.println(analogRead(flame_sensor));
          //flame_sensor = analogRead(A2);
          if (buttonValue == 1) {
            break;
          }
        }
       digitalWrite(relay, LOW);
       for (pos = 130; pos >= 92; pos-=1) {
       myservo.write(pos);
       delay(10);
       }
  }
  
}
  
