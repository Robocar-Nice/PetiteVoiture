#include <SoftwareSerial.h>

SoftwareSerial BT(11, 12);

// Moteur A
const int ENA = 9;   // PWM - vitesse moteur A
const int IN1 = 3;
const int IN2 = 4;

// Moteur B
const int ENB = 10;  // PWM - vitesse moteur B
const int IN3 = 5;
const int IN4 = 6;

int vitesse = 200;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  if (BT.available()) {
    char c = BT.read();

    switch (c) {
      case 'F': avancer(vitesse); break;        // Forward
      case 'B': reculer(vitesse); break;        // Backward
      case 'L': tournerGauche(vitesse); break;  // Left
      case 'R': tournerDroite(vitesse); break;  // Right
      case 'G': avantGauche(vitesse); break;    // Forward-Left (diagonale)
      case 'I': avantDroite(vitesse); break;    // Forward-Right
      case 'H': arriereGauche(vitesse); break;  // Backward-Left
      case 'J': arriereDroite(vitesse); break;  // Backward-Right
      case 'S': arreter(); break;               // Stop
    }
  }
}

void avancer(int v) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, v);
  analogWrite(ENB, v);
}

void reculer(int v) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, v);
  analogWrite(ENB, v);
}

void tournerDroite(int v) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, v);
  analogWrite(ENB, v);
}

void tournerGauche(int v) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, v);
  analogWrite(ENB, v);
}

void avantGauche(int v) {
  // moteur A ralenti, moteur B plein régime -> léger virage en avançant
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, v / 2);
  analogWrite(ENB, v);
}

void avantDroite(int v) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, v);
  analogWrite(ENB, v / 2);
}

void arriereGauche(int v) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, v / 2);
  analogWrite(ENB, v);
}

void arriereDroite(int v) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, v);
  analogWrite(ENB, v / 2);
}

void arreter() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
