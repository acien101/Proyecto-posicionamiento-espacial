/*

 RC_Test  - Basic R/C Servo tester - v0.2
 (C) Ariel Rocholl - 2008, Madrid Spain
 Feel free to share this source code, but include explicit mention to the author.
 Licensed under creative commons - see http://creativecommons.org/licenses/by-sa/3.0/
 
 */

int ledPin = 13;                // LED connected to digital pin 13
int PinPPM1 = 3;               // PPM signal that goes 1000us-1500us-2000us
int PinSW1 = 11;                // Switch 1 - ON (5V) indicates auto mode,
                                        //OFF (0V) indicates manual pot mode
int nValue = 0;                 // Analog value representing servo position


void setup()                    // run once, when the sketch starts
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  pinMode(PinPPM1, OUTPUT);
}

void loop()                     // run over and over again
{
  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(1000);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second

  while (1)
  { 
      //Produce the 1-1.5-2ms standard servo travel
      for (int nInd=0; nInd<30; nInd++)
      {
        digitalWrite(PinPPM1,HIGH);
        delayMicroseconds(1000);   //1ms pulse
        digitalWrite(PinPPM1,LOW);
        delay(18);                 //18ms low till next pulse
      }

      for (int nInd=0; nInd<30; nInd++)
      {
        digitalWrite(PinPPM1,HIGH);
        delayMicroseconds(1500);   //1.5ms pulse
        digitalWrite(PinPPM1,LOW);
        delay(18);                 //18ms low till next pulse
      }
      for (int nInd=0; nInd<30; nInd++)
      {
        digitalWrite(PinPPM1,HIGH);
        delayMicroseconds(2000);   //2ms pulse
        digitalWrite(PinPPM1,LOW);
        delay(18);                 //18ms low till next pulse
      }
    }
  
}
