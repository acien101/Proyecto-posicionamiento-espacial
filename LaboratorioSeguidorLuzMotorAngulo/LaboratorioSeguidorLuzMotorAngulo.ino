#include <Servo.h>

Servo servoContinuo;

int botonDerecha = 7;
int botonIzquierda = 6;
int optoacoplador = 2;

boolean previousAngle;
double angulo;

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
  
  while(digitalRead(botonIzquierda) == 1){

    //Serial.println("NO HAY PULSADO");
    servoContinuo.write(85);

    if(previousAngle != digitalRead(optoacoplador)){
      angulo = angulo + 5;

      Serial.println(String(angulo));
    }
    previousAngle = digitalRead(optoacoplador);
    }
  servoContinuo.write(93);
}

void loop() {

  
  
  //Serial.println("Servo Derecha" + String(digitalRead(botonIzquierda)));
  /*
  while(digitalRead(botonIzquierda) != 0 || digitalRead(botonDerecha) != 0){}
  servoContinuo.write(93);

  */
}

void initAngle(){
  while((digitalRead(botonDerecha) == 1)){

    //Serial.println("NO HAY PULSADO");
    servoContinuo.write(98);
  }
  servoContinuo.write(93);

}

