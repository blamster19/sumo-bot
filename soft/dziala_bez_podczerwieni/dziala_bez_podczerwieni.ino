#include <CytronMotorDriver.h>
#include <RC5.h>



 
// Definiowanie pinów czujników odbiciowych
#define okoPrzedLewe      0
#define okoPrzedPrawe     1
#define oko3              2
#define oko4              3
#define oko5              15
#define oko6              16

// Definiowanie obiektów silników 
// CytronMD motorL(PWM_DIR, MOTOR_PWM_1, MOTOR_DIR_1);
// CytronMD motorR(PWM_DIR, MOTOR_PWM_2, MOTOR_DIR_2); 
CytronMD motorL(PWM_DIR, 5, 4);  // Podłącz silnik do M1
CytronMD motorP(PWM_DIR, 6, 7);  // Podłącz silnik do M2

void setup() {
  // Inicjalizacja czujników odbiciowych
  
    pinMode(okoPrzedLewe, INPUT);
    pinMode(okoPrzedPrawe, INPUT);
  
  

  // Inicjalizacja komunikacji szeregowej
  Serial.begin(9600);
}

void loop() {
 

  
   

 
   motorL.setSpeed(-255);       // po prostu rusza z miejsca i sobie jedzie
   motorP.setSpeed(255);

   if (digitalRead(okoPrzedLewe) == LOW) {   // jesli wykryje lewe oko biala linie, to skreca w prawo
     motorP.setSpeed(-255);
     delay(350);
   }
   if (digitalRead(okoPrzedPrawe) == LOW) {  // analogicznie jak powyzej
     motorL.setSpeed(255);
     delay(350);
   }
    if ((digitalRead(okoPrzedLewe) == LOW) && (digitalRead(okoPrzedPrawe) == LOW) ) { // jesli wykrywa oboma oczami biel z przodu
     motorL.setSpeed(-255);    //cofa sie
     motorP.setSpeed(-255);
     delay(1500);
    
     motorP.setSpeed(-255);      // skreca w prawo
     motorL.setSpeed(255);
     delay(350);
    }


  

 

} // do loop
