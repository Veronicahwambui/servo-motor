#include<Servo.h>
int pinPot=0;
int Red=8;
int Blue=9;
int Green=10;
int val;
Servo servo1;
int trigPin=3;
int echoPin=4;
long distance;
long duration;
void setup()
{
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  servo1.attach(12);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, OUTPUT);
}
void loop()
{
  ultra();
  servo1.write(0); 
  val=analogRead(pinPot);
  val=map(val,0,1023,0,180);
  servo1.write(val);
  delay(15);
  
   if(distance <=15){
    digitalWrite(Red, HIGH);
    delay(3000);
    digitalWrite(Red, LOW);
    delay(3000); 
    servo1.write(60);
  }
  else{servo1.write(0);}
  if(distance <=15){
    digitalWrite(Blue,HIGH);
    delay(2000);
    digitalWrite(Blue, LOW);
    delay(2000); 
    servo1.write(120);
  }
  else{servo1.write(0);}
  if(distance <=15){
    digitalWrite(Green,HIGH);
    delay(1000);
    digitalWrite(Green, LOW);
    delay(1000); 
    servo1.write(180);
  }
  else{servo1.write(0);}
}
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.343/2;
 }
// SYSTEMS IN MY ENVIRONMENT  THAT USES SERVO MOTOR;
//->Camera Auto Focus: A highly precise servo motor built into 
//the camera corrects a camera's lens to sharpen out-of-focus images.
//->Robotics: A servo motor at every "joint" of a robot is used to actuate movements, 
//giving the robot arm its precise angle.
//->Printing Presses/Printers: Servo motors stop and start the print heads precisely
//on the page as well as move paper along to print multiple rows 
//of text or graphics in exact lines, whether it's a newspaper,
//a magazine, or an annual report.
