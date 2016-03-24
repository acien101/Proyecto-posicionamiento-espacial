int abajo;
int arriba;
int izquierda;
int derecha;

void setup() {
  Serial.begin(9600);

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

  if((abajo - arriba) > 50){
    Serial.println("arriba");
  }
  if((abajo - arriba) < -50){
    Serial.println("abajo");
  }
  if((abajo - arriba) < 50 && (abajo - arriba) > -50){
    Serial.println("igual");
  }
  

  delay(100);
}
