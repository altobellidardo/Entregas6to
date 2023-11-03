#include "HX711.h"

#define DT 13
#define SCK 12

HX711 balanza;

void setup() {
  Serial.begin(9600);
  balanza.begin(DT, SCK);
  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(balanza.read());
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  balanza.set_scale(135.26012); // Establecemos la escala.
  // escala = valor de lectura / peso real
  balanza.tare(20);  //El peso actual es considerado Tara.
 
  Serial.println("Listo para pesar");  
}

void loop() {
  Serial.print("Peso: ");
  Serial.print(balanza.get_units(20), 3);
  Serial.println(" gr");
  delay(500);
}
