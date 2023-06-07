#include <NewPing.h>
#include <IRremote.h>
#include <CytronMotorDriver.h>

#define SONIC_TRIGGER1 1
#define SONIC_TRIGGER2 2
#define SONIC_TRIGGER3 3
#define SONIC_ECHO1    4
#define SONIC_ECHO2    5
#define SONIC_ECHO3    6
#define IR_PIN         7
#define LINE_PIN1      8
#define LINE_PIN2      9
#define LINE_PIN3      10
#define LINE_PIN4      11
#define LINE_PIN5      12
#define LINE_PIN6      13
#define SHOCK_PIN      14
#define MOTOR_PWM_1    3
#define MOTOR_DIR_1    4
#define MOTOR_PWM_2    9
#define MOTOR_DIR_2    10

#define MAX_SONIC      50

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

bool readLine(int pin) {
	return digitalRead(pin) == HIGH;
}

bool readShock() {
	return digitalRead(SHOCK_PIN) == HIGH;
}

int readSonic(NewPing sonar) {
	return sonar.ping_cm() + 1;// sensor gives distance 1 cm shorter then real value
}
