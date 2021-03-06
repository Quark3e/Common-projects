#include <Wire.h> //adafruit neopixel
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

//for software SPI
#define LIS3DH__CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11

//for hardware & software SPI
#define LIS3DH_CS 10

//software SPI
Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH__CLK);

const int shortVal = 120;
const int mediumVal = 150;
const int longVal = 200;

unsigned long punchStart = 0;
const long punchInterval = 200; //basically the duration from punch start to punch ending
//const long punchIntervalShort = 90; //this should later be changed //ms
//const long punchIntervalMedium = 130;
//const long punchIntervalLong = 210;
int punchAccel = 20; //faster-stronger punch means higher acceleration
int punchDecel = -40;

int flameTimeShort = 150;
int flameTimeMedium = 250;
int flameTimeLong = 500;
//int flameTimeAuto = 300;

int flameTimeAuto = 0;

int solenoid = 8;
int igniter = 9; //igniter = relay

void setup(void) {
    Serial.begin(9600);
    Serial.println("LIS3DH test");
    if (! lis.begin(0x18)) { //i2c address //can be changed to 0x19(?) for alternative address
        Serial.println("Couldn't start");
        while (1);
    }
    Serial.println("LIS3DH found");

    lis.setRange(LIS3DH_RANGE_16_G); //16 for +-16g //gives a good wider range
    Serial.print("Range = "); Serial.print(2 << lis.getRange());
    Serial.println("G");

    pinMode(solenoid, OUTPUT);
    pinMode(igniter, OUTPUT);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
}

void loop() {
    lis.read();
    sensors_event_t event;
    lis.getEvent(&event);

    //look for punch
    if (event.acceleration.x > punchAccel) {
        Serial.println(event.acceleration.x);
        punchStart = millis();
    }

    unsigned long currentMillis = millis();

    if (event.acceleration.x < punchDecel && currentMillis - punchStart < punchInterval){
        Serial.println(event.acceleration.x);
        Serial.println("Punch registered");
        Serial.println(currentMillis);
        Serial.println(punchStart);
        int flameTimeAuto = currentMillis;
        //Fire(flameTimeAuto);
        if (currentMillis < shortVal) {
            FireShort(flameTimeShort);
            Serial.println("Small flame");
        }
        if (currentMillis >= shortVal && currentMillis < mediumVal) {
            FireMedium(flameTimeMedium);
            Serial.println("Medium flame");
        }
        if (currentMillis >= mediumVal && currentMillis <= longVal) {
            FireLong(flameTimeLong);
            Serial.println("Big flame");
        }
        
        
    }
}

//void Fire(int flameTimeAuto) {
    //digitalWrite(solenoid, HIGH);
    //digitalWrite(igniter, HIGH);
    //delay(flameTimeAuto);
    //digitalWrite(solenoid, LOW);
    //digitalWrite(igniter, LOW);
//}

void FireShort(int flameTimeShort) {
    digitalWrite(solenoid, HIGH);
    digitalWrite(igniter, HIGH);
    delay(flameTimeShort);
    digitalWrite(solenoid, LOW);
    digitalWrite(igniter, LOW);
}

void FireMedium(int flameTimeMedium) {
    digitalWrite(solenoid, HIGH);
    digitalWrite(igniter, HIGH);
    delay(flameTimeMedium);
    digitalWrite(solenoid, LOW);
    digitalWrite(igniter, LOW);
}

void FireLong(int flameTimeLong) {
    digitalWrite(solenoid, HIGH);
    digitalWrite(igniter, HIGH);
    delay(flameTimeLong);
    digitalWrite(solenoid, LOW);
    digitalWrite(igniter, LOW);
}