#include "Weather.h"

Weather weather;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  float dp = weather.dew_point(25, 57);
  char message[10]; //taille max de 20 caractère pour le message, pour l'exemple
  sprintf(message, "%f", dp); //comme un printf mais dans une chaine !
  Serial.write(message);
}

void loop() {
  // put your main code here, to run repeatedly:

}
