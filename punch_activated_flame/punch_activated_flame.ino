#include <Adafruit_ADXL345_U.h>
#include <Wire.h>  // Wire library - used for I2C communication


int ADXL345 = 0x53; // The ADXL345 sensor I2C address
float X_out, Y_out, Z_out;


int accelData = 20 //in m/s^2
int decelData = -40
int solenoid = 12;
int led =
int flametime = 250 //in ms

void setup () {
    pinMode(solenoid, OUTPUT);
    pinMode(led, OUTPUT);

    Serial.begin(9600); // Initiate serial communication for printing the results on the Serial monitor
    Wire.begin(); // Initiate the Wire library
    // Set ADXL345 in measuring mode
    Wire.beginTransmission(ADXL345); // Start communicating with the device 
    Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
    // Enable measurement
    Wire.write(8); // (8dec -> 0000 1000 binary) Bit D3 High for measuring enable 
    Wire.endTransmission();
    delay(10);
}

void loop () {
    Wire.beginTransmission(ADXL345);
    Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
    X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
    X_out = X_out/32; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
    Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
    Y_out = Y_out/32;
    Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
    Z_out = Z_out/32;
    Serial.print("Xa= ");
    Serial.print(X_out);
    Serial.print("Ya= ");
    Serial.print(Y_out);
    Serial.print("Za= ");
    Serial.println(Z_out);
}
