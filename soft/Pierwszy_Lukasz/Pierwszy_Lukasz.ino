#include <CytronMotorDriver.h>
#include <RC5.h>

#define Podczerwien 3 // Definiowanie pinów odbiornika podczerwieni

RC5 rc5(Podczerwien); //Informacja o podłączeniu odbiornika podczerwieni

//Zmienne dla RC5
byte address; 
byte command;
byte toggle;
 
// Definiowanie pinów czujników odbiciowych
#define okoPrzedLewe      8
#define okoPrzedPrawe     9
#define oko3              10
#define oko4              11
#define oko5              12
#define oko6              13

// Definiowanie obiektów silników 
// CytronMD motorL(PWM_DIR, MOTOR_PWM_1, MOTOR_DIR_1);
// CytronMD motorR(PWM_DIR, MOTOR_PWM_2, MOTOR_DIR_2); 
CytronMD motorL(PWM_DIR, 5, 4);  // Podłącz silnik do M1
CytronMD motorP(PWM_DIR, 6, 7);  // Podłącz silnik do M2

void setup() {
  // Inicjalizacja czujników odbiciowych
  
    pinMode(okoPrzedLewe, INPUT);
    pinMode(okoPrzedPrawe, INPUT);
  
  // Inicjalizacja odbiornika podczerwieni
  pinMode(Podczerwien, INPUT);

  // Inicjalizacja komunikacji szeregowej
  Serial.begin(9600);
}

void loop() {
  if (rc5.read(&toggle, &address, &command)){

  while (toggle == 0){
    //zatrzymaj silniki
    motorL.setSpeed(0);
    motorP.setSpeed(0);
  }

  while (toggle == 1) { // Może lepszy byłby while albo if
 
   motorL.setSpeed(100);       // po prostu rusza z miejsca i sobie jedzie
   motorP.setSpeed(100);

   if (digitalRead(okoPrzedLewe) == LOW) {   // jesli wykryje lewe oko biala linie, to skreca w prawo
     motorP.setSpeed(0);
     delay(2000);
   }
   if (digitalRead(okoPrzedPrawe) == LOW) {  // analogicznie jak powyzej
     motorL.setSpeed(0);
     delay(2000);
   }
    if ((digitalRead(okoPrzedLewe) == LOW) && (digitalRead(okoPrzedPrawe) == LOW) ) { // jesli wykrywa oboma oczami biel z przodu
     motorL.setSpeed(-100);    //cofa sie
     motorP.setSpeed(-100);
     delay(3000);
    
     motorP.setSpeed(0);      // skreca w prawo
     motorL.setSpeed(100);
     delay(2000);
    }


  

  } // do while
  } // do if od podczerwieni

} // do loop


