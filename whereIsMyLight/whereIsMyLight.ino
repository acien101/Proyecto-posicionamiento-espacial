
#include <Servo.h>

int abajo;
int arriba;
int izquierda;
int derecha;

int pos;

Servo servo;

void setup() {
  Serial.begin(9600);

  servo.attach(3);
  
  pos = 180;
  servo.write(pos);
}

void loop() {
  abajo = analogRead(A0);
  arriba = analogRead(A1);
  izquierda = analogRead(A2);
  derecha = analogRead(A3);

/*
  if((izquierda - derecha) > 100){    // Hay más luz en derecha que en la izquierda
    Serial.println("derecha");   
  }
  if((izquierda - derecha) < -20){    //Hay más luz en la izquierda que en la derecha
    Serial.println("izquierda");
  }
  if((izquierda - derecha) < 100 && (izquierda - derecha) > -20){     //Más o menos hay la misma luz
    Serial.println("nada");
  }

  */

  if((abajo - arriba) > 50){      //Hay más luz abajo que arriba
    Serial.println("abajo");

    if(pos != 180){
      pos++;
    }
  }
  if((abajo - arriba) < -50){     //Hay más luz arriba que abajo
    Serial.println("arriba");

    if(pos != 60){
      pos--;
    }
  }
  if((abajo - arriba) < 50 && (abajo - arriba) > -50){        //Más o menos la misma luz
    Serial.println("igual");
  }
  
  servo.write(pos);
}
