#include <Servo.h>

Servo servoContinuo;

int botonDerecha = 7;
int botonIzquierda = 6;
int optoacoplador = 2;

boolean previousAngle;
int angulo;

String estado = "";

void setup() {
  Serial.begin(9600);
  pinMode(botonIzquierda, INPUT);
  pinMode(botonDerecha, INPUT);
  pinMode(optoacoplador, INPUT);

  servoContinuo.attach(5);


  initAngle();
  
  previousAngle = digitalRead(optoacoplador);
  angulo = 0;

  /*
  while(digitalRead(botonDerecha) == 1){

    //Serial.println("NO HAY PULSADO");
    servoContinuo.write(100);

    if(previousAngle != digitalRead(optoacoplador)){
      angulo = angulo + 5;

      Serial.println(String(angulo));
    }
    previousAngle = digitalRead(optoacoplador);
    }
  servoContinuo.write(93);

  */
  goToAngle(180);
  goToAngle(50);
}

void loop() {

  
  
  //Serial.println("Servo Derecha" + String(digitalRead(botonIzquierda)));
  /*
  while(digitalRead(botonIzquierda) != 0 || digitalRead(botonDerecha) != 0){}
  servoContinuo.write(93);

  */
}

void initAngle(){
  while((digitalRead(botonIzquierda) == 1)){

    //Serial.println("NO HAY PULSADO");
    servoContinuo.write(88);
  }
  servoContinuo.write(93);

}

void goToAngle(int finishAngle){
  while(angulo != finishAngle){
    if(angulo > finishAngle){
      servoContinuo.write(88);

      if(previousAngle != digitalRead(optoacoplador)){
        angulo -= 5;
      }
      previousAngle = digitalRead(optoacoplador);
    
    }
    if(angulo < finishAngle){
      servoContinuo.write(98);

      if(previousAngle != digitalRead(optoacoplador)){
        angulo += 5;
      }
      previousAngle = digitalRead(optoacoplador);
    
    }
  }
  servoContinuo.write(93);
}



