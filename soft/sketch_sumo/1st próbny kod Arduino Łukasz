#include <CytronMotorDriver.h>

CytronMD motor(3, 2, 6, 5);  // Konfiguracja sterownika silników Cytron Shield

int irReceiverPin = 4;  // Pin odbiornika podczerwieni
int dohyoWidth = 800;   // Szerokość dohyo w milimetrach

int irData = 0;
bool robotOnDohyo = true;

void setup() {
  Serial.begin(9600);  // Inicjalizacja komunikacji szeregowej
  
  pinMode(irReceiverPin, INPUT);  // Ustawienie pinu odbiornika podczerwieni jako wejście
  
  for (int i = 0; i < 6; i++) {
    pinMode(i, INPUT);  // Ustawienie pinów czujników odbiciowych jako wejścia
  }
  
  motor.begin();  // Inicjalizacja sterownika silników
}

void loop() {
  if (digitalRead(irReceiverPin) == HIGH) {
    // Jeśli odbiornik podczerwieni odbierze sygnał, włącz robot
    robotOnDohyo = true;
    Serial.println("Robot włączony");
  }
  
  while (robotOnDohyo) {
    int sensorValues[6];
    
    for (int i = 0; i < 6; i++) {
      sensorValues[i] = digitalRead(i);  // Odczyt wartości czujników odbiciowych
    }
    
    // Sprawdzenie, czy robot wypadł za dohyo
    if (sensorValues[0] == HIGH || sensorValues[1] == HIGH || sensorValues[2] == HIGH ||
        sensorValues[3] == HIGH || sensorValues[4] == HIGH || sensorValues[5] == HIGH) {
      robotOnDohyo = false;
      Serial.println("Robot wypadł za dohyo");
      break;
    }
    
    // Instrukcje sterowania ruchem robota w zależności od odczytów czujników
    // Tutaj należy umieścić logikę sterowania minisumo
    // Przykładowo:
    
    // Jeśli wykryto czarny kolor na czujniku odbiciowym 0 (lewy przód)
    if (sensorValues[0] == LOW) {
      // Wykonaj odpowiednie operacje sterujące silnikami, aby skręcić w lewo
      motor.motorSpeed(MD_MOTOR_1, MD_CW, 100);  // Przykładowa prędkość silnika 1
      motor.motorSpeed(MD_MOTOR_2, MD_CCW, 100); // Przykładowa prędko
