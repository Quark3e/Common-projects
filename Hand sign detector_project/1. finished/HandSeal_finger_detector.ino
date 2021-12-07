/*
white to brown
blue to blue
green to green
green to brown
black to orange
red to red
yellow to brown
orange to purple
*/

int Lb_1 = 6;
int Lb_2 = 3;
int Lb_3 = 2;
int Lb_4 = 7;
int Lb_5 = 8;
int Lb_6 = 9;
int Lb_7 = 5;
int Lb_8 = 4;

void setup() {
    Serial.begin(9600);
    pinMode(Lb_1, INPUT_PULLUP);
    pinMode(Lb_2, INPUT_PULLUP);
    pinMode(Lb_3, INPUT_PULLUP);
    pinMode(Lb_4, INPUT_PULLUP);
    pinMode(Lb_5, INPUT_PULLUP);
    pinMode(Lb_6, INPUT_PULLUP);
    pinMode(Lb_7, INPUT_PULLUP);
    pinMode(Lb_8, INPUT_PULLUP);
}

void loop() {

    int val1 = digitalRead(Lb_1);
    int val2 = digitalRead(Lb_2);
    int val3 = digitalRead(Lb_3);
    int val4 = digitalRead(Lb_4);
    int val5 = digitalRead(Lb_5);
    int val6 = digitalRead(Lb_6);
    int val7 = digitalRead(Lb_7);
    int val8 = digitalRead(Lb_8);

    if (val1 != 1) {Serial.print("thumb finger\n");}
    if (val2 != 1) {Serial.print("index finger\n");}
    if (val3 != 1) {Serial.print("middle finger\n");}
    if (val4 != 1) {Serial.print("ring finger\n");}
    if (val5 != 1) {Serial.print("pinky finger\n");}
    if (val6 != 1) {Serial.print("center left\n");}
    if (val7 != 1) {Serial.print("center middle\n");}
    if (val8 != 1) {Serial.print("center right\n");}
    
    
    delay(100);

}