
int derecha;
int izquierda;
int arriba;
int abajo;

String incomingByte = "";   // for incoming serial data
int number = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  abajo = analogRead(A0);
  arriba = analogRead(A1);
  izquierda = analogRead(A2);
  derecha = analogRead(A3);

  if(Serial.available() > 0){
    incomingByte = Serial.readString();
    number = incomingByte.toInt();

    switch(number){
      case 0:
        Serial.println("Abajo " + String(abajo));
        break;
        
      case 1:
        Serial.println("Arriba " + String(arriba));
        break;
        
      case 2:
        Serial.println("Izquierda " + String(izquierda));
        break;
        
      case 3:
        Serial.println("Derecha " + String(derecha));
        break;
    }
  }
 

  delay(1000);
}
