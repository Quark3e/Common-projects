int relay = 9; //select the pin for the buzzer
int flame_sensor = 0; // variable to store the value coming from the sensor

void setup() {

//Setting the serial port speed
Serial.begin(9600);

pinMode(relay, OUTPUT);

} void loop() {

flame_sensor = analogRead(A2);

Serial.println(flame_sensor);

if (flame_sensor > 600){
//activate the buzzer
  digitalWrite(relay, HIGH);
  delay(100);
  digitalWrite(relay, LOW);
  delay(50);
  }
}
