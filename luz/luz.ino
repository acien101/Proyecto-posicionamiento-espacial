
#include <Servo.h>

int luz0;
int luz1;
int mypos;

int velocity = 93;

Servo myservo;

void setup() {
  Serial.begin(9600);

  myservo.attach(6);
  mypos= 0;

  myservo.write(mypos);

}

void loop() {
  luz0 = analogRead(0);
  luz1 = analogRead(1);

  
  /*
  if(luz0 > luz1 && mypos < 180){
    myservo.write(mypos++);
  }
  if(luz1 > luz0 && mypos >0){
    myservo.write(mypos--);
  }
  if(luz1 == luz0){

  }

  

  if(luz0 > luz1){
    myservo.write(100);
  }
  if(luz1 > luz0){
    myservo.write(80);
  }
  if(luz1 == luz0){
    myservo.write(93);
  }

  */



  if(Serial.available()){

    velocity = Serial.readString().toInt();
    myservo.write(velocity);   
    
  }


  delay(10);

}
