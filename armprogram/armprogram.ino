//Program to control the arm of the DORA Rover
//Antares Rahman & Moustafa Ndiaye

#include <Servo.h>
#include <NewPing.h>

#define SONAR_NUM 1 // Number or sensors.
#define MAX_DISTANCE 300 // Max distance in cm.
#define PING_INTERVAL 33 // Milliseconds between pings.

Servo baseServo;      //servo on the bottom
Servo turnServo1;     //Big servo on top of the base
Servo turnServo2;     //
Servo turnServo3;     //Servo at grip hinge
Servo turnServo4;     // Small gripping servo


boolean done = false;

int posB = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  pinMode(4, OUTPUT);
  baseServo.attach(9);
  turnServo1.attach(10);
  turnServo2.attach(6);
  turnServo3.attach(3);
  turnServo4.attach(11);
  
}
void rePositionServo(Servo servo, int posF, int spd) {   //send intitial position and desired position
  int posI = servo.read();
  Serial.println(posI);
  
  if(posI < posF){
    Serial.println("Entering if statement");
    for(int i = posI; i <= posF; i += 1){
      servo.write(i);
      delay(spd);
    }
  }else if(posI > posF){
    Serial.println("Entering else if statement");
    for(int i = posI; i >= posF; i -= 1){
      servo.write(i);
      delay(spd);
    }
  }else{
    Serial.println("Entering else");
    servo.write(posF);
    delay(spd);
  }
  delay(1000);
  Serial.println(servo.read());  
}

void loop() {
  
  rePositionServo(baseServo, 90, 50);
  rePositionServo(turnServo1, 90, 50);
  rePositionServo(turnServo2, 50, 50);
  rePositionServo(turnServo3, 80, 50);
  rePositionServo(turnServo4, 0, 30);
  
  int val = digitalRead(7);
  
  digitalWrite(4, HIGH);
  delay(4000);
  digitalWrite(4, LOW);
  
    rePositionServo(turnServo3, 170, 45);    //Servo at grip hinge 3
    
    rePositionServo(turnServo1, 20, 45);      //Big serson on top of platform
    
    rePositionServo(turnServo2, 74, 45);     //Servo in the middle
    
    rePositionServo(baseServo, 65, 45);
    
    rePositionServo(baseServo, 110, 45);
    
    rePositionServo(baseServo, 90, 45);
    delay(500);
    
    rePositionServo(turnServo4, 160, 30);
    
    rePositionServo(turnServo1, 130, 45);
    
    rePositionServo(turnServo2, 74, 45);
    
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(4, LOW);
}
