


int botonDerecha = 7;
int botonIzquierda = 6;
int optoacoplador = 2;

void setup() {
  Serial.begin(9600);
  pinMode(botonIzquierda, INPUT);
  pinMode(botonDerecha, INPUT);
  pinMode(optoacoplador, INPUT);

}

void loop() {
  if(digitalRead(botonIzquierda) == 0){
    Serial.println("Se ha pulsado el boton izquierdo");
  }

  if(digitalRead(botonDerecha) == 0){
    Serial.println("Se ha pulsado el boton derecho");
  }

  //Serial.println("Optotransistor " + String(digitalRead(optoacoplador)));

  delay(500);
}
