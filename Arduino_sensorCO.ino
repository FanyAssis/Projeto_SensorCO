#include <Arduino.h>

#define MQ7_PIN A0 
#define BUZZER_PIN 8 

//configurações iniciais
const int CO_THRESHOLD = 200; //Concentração limite da particula por ppm
const unsinged long CHECK_INTERVAL = 2000; 


void setup() {
  pin_MODE(MQ-7_PIN ,INPUT );
  pin_MODE(BUZZER-PIN, OUTPUT);

 
  serial.begin(9600);
  
}

void loop() {
  

  int coValue = analogRead(MQ-7_PIN);

  
  int coPPM = map(Value, 0 ,1023 ,0 , 1000);

  
  serial.print("CO PPM: ");
  serial.println(coPPM);

  // DEFININDO O NÍVEL DE CO ADEQUADO
  if(coPPM > CO_THRESHOLD);
  { 
    tone(BUZZER_PIN, 1000); //FREQUENCIA EM HZ
    delay(1000);
    noTone(BUZZER_PIN);  
  }

  

  delay(CHECK_INTERVAL);
}
