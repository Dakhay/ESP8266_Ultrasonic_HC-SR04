#include <Arduino.h>

#define TRIG_PIN D1 // Broche TRIG connectée à la broche D1
#define ECHO_PIN D2 // Broche ECHO connectée à la broche D2

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Affichage des détails du capteur ultrasonique.
  Serial.println("------------------------------------");
  Serial.println("Capteur Ultrasonique HC-SR04");
  Serial.print("Broche TRIG: "); Serial.println(TRIG_PIN);
  Serial.print("Broche ECHO: "); Serial.println(ECHO_PIN);
  Serial.print("Distance maximale:   "); Serial.print(400);  Serial.println(" cm");
  Serial.print("Distance minimale:   "); Serial.print(2); Serial.println(" cm");
  Serial.println("------------------------------------");
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calcul de la distance en centimètres
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
