//remeber to add library in afterwards

#include <Wire.h>
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


unsigned long punchStart = 0;
const long punchInterval = 200;
int punchAccel = 20; //faster/stronger punch means higher acceleration
int punchDecel = -40;

int flameTimeShort = 150;
int flameTimeMedium = 250;
int flameTImeLong = 500;