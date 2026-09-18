// Moteur A
const int ENA = 9;   // PWM - vitesse moteur A
const int IN1 = 3;
const int IN2 = 4;

// Moteur B
const int ENB = 10;  // PWM - vitesse moteur B
const int IN3 = 5;
const int IN4 = 6;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char val = Serial.read();

    Serial.print(val);

    // if (val == *code*) {
      //do something
    //}
  }
}

void avancer(int vitesse) {
  // Moteur A avant
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Moteur B avant
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, vitesse);
  analogWrite(ENB, vitesse);
}

void reculer(int vitesse) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, vitesse);
  analogWrite(ENB, vitesse);
}

void tournerDroite(int vitesse) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, vitesse);
  analogWrite(ENB, vitesse);
}

void tournerGauche(int vitesse) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, vitesse);
  analogWrite(ENB, vitesse);
}

void arreter() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
