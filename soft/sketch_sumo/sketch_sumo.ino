#include <NewPing.h>
#include <IRremote.h>
#include <CytronMotorDriver.h>
#include "pinDefinitions.h"

NewPing sonar1(SONIC_TRIGGER1, SONIC_ECHO1, MAX_SONIC);
NewPing sonar2(SONIC_TRIGGER2, SONIC_ECHO2, MAX_SONIC);
NewPing sonar3(SONIC_TRIGGER3, SONIC_ECHO3, MAX_SONIC);
IRrecv  irrecv(IR_PIN);
decode_results ir1;
CytronMD motorL(PWM_DIR, MOTOR_PWM_1, MOTOR_DIR_1);
CytronMD motorR(PWM_DIR, MOTOR_PWM_2, MOTOR_DIR_2);


void setup() {
	irrecv.enableIRIn();
	pinMode(LINE_PIN1, INPUT);
	pinMode(LINE_PIN2, INPUT);
	pinMode(LINE_PIN3, INPUT);
	pinMode(LINE_PIN4, INPUT);
	pinMode(LINE_PIN5, INPUT);
	pinMode(LINE_PIN6, INPUT);
	pinMode(SHOCK_PIN, INPUT);
}

void loop() {

}

