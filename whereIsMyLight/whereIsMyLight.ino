
#include <Servo.h>

Servo servo;
Servo servoContinuo;

int botonDerecha = 7;
int botonIzquierda = 6;
int optoacoplador = 2;

boolean previousAngle;
int angulo;


int abajo;
int arriba;
int izquierda;
int derecha;

int posVertical;

void setup() {
  Serial.begin(9600);

  pinMode(botonIzquierda, INPUT);
  pinMode(botonDerecha, INPUT);
  pinMode(optoacoplador, INPUT);


  /*
  servoContinuo.attach(5);
  initAngle();
  
  previousAngle = digitalRead(optoacoplador);
  angulo = 0; 

   delay(1000);

   */

   
   servo.attach(3);
   posVertical = 170;
   servo.write(posVertical);

   
}

void loop() {
  
  abajo = analogRead(A0);
  arriba = analogRead(A1);
  izquierda = analogRead(A2);
  derecha = analogRead(A3);
  /*

  if((izquierda - derecha) > 100){    // Hay más luz en derecha que en la izquierda
    Serial.println("derecha");

    if(angulo != 0){
      goToAngle((angulo - 5));
    }
  }
  if((izquierda - derecha) < -20){    //Hay más luz en la izquierda que en la derecha
    Serial.println("izquierda");

    if(angulo != 180){
      goToAngle((angulo + 5));
    }
  }
  if((izquierda - derecha) < 100 && (izquierda - derecha) > -20){     //Más o menos hay la misma luz
    Serial.println("nada");
  }
*/
  


  if((abajo - arriba) > 50){      //Hay más luz abajo que arriba
    Serial.println("abajo");

    if(posVertical != 170){
      posVertical++;
    }
  }
  if((abajo - arriba) < -50){     //Hay más luz arriba que abajo
    Serial.println("arriba");

    if(posVertical != 60){
      posVertical--;
    }
  }
  if((abajo - arriba) < 50 && (abajo - arriba) > -50){        //Más o menos la misma luz
    Serial.println("igual");
  }
  
  
  servo.write(posVertical);

  delay(10);

  
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

    if(digitalRead(botonIzquierda) == 0 || digitalRead(botonDerecha) == 0){
      angulo = 0;
    }
  }
  servoContinuo.write(93);
}

