#include <NewPing.h>
#include <IRremote.h>
#include <CytronMotorDriver.h>

#define SONIC_TRIGGER1 8
#define SONIC_TRIGGER2 10
#define SONIC_TRIGGER3 12
#define SONIC_ECHO1    9
#define SONIC_ECHO2    11
#define SONIC_ECHO3    13
#define IR_PIN         A0
#define LINE_PIN1      0
#define LINE_PIN2      1
#define LINE_PIN3      2
#define LINE_PIN4      3
#define LINE_PIN5      A1
#define LINE_PIN6      A2
#define SHOCK_PIN      A3
#define MOTOR_PWM_1    5
#define MOTOR_DIR_1    4
#define MOTOR_PWM_2    6
#define MOTOR_DIR_2    7

#define MAX_SONIC      75

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
	Serial.begin(9600);
}

byte flag = 0;

void loop() {
	testIRMotorsSonicRotation2();
}

bool readLine(int pin) {
	return digitalRead(pin) == HIGH;
}

bool readShock() {
	return digitalRead(SHOCK_PIN) == HIGH;
}

int readSonic(NewPing sonar) {
	return sonar.ping_cm() + 1;
}

void testLineSensors() {
	for(int i = 0; i < 6; i++) {
		Serial.print("Sensor ");
		Serial.print(i);
		Serial.print(": ");
		Serial.print(readLine(LINE_PIN1 + i));// black 1
		Serial.print("   ");
	}
	Serial.print("\n");
	delay(30);
}

void testSonicSensors() {
	Serial.print("Sonic 1: ");
	Serial.print(readSonic(sonar1));
	Serial.print(" cm    Sonic 2: ");
	Serial.print(readSonic(sonar2));
	Serial.print(" cm    Sonic 3: ");
	Serial.print(readSonic(sonar3));
	Serial.print("\n");
	delay(50);
}

void testMotorL() {
	motorL.setSpeed(255);
}

void testMotorR() {
	motorR.setSpeed(255);
}

void testIR() {
	if(irrecv.decode(&ir1)) {
		Serial.println(ir1.value, HEX);
		irrecv.resume();
	}
	delay(10);
}

void testIRMotors() {
	if(irrecv.decode(&ir1)) {
		flag = flag ? 0 : 1;
		irrecv.resume();
	}
	if(flag) {
		motorR.setSpeed(255);
		motorL.setSpeed(-255);
	} else {
		motorR.setSpeed(0);
		motorL.setSpeed(0);
	}
	delay(75);
}

void testIRMotorsLine() {
	if(irrecv.decode(&ir1)) {
		flag = flag ? 0 : 1;
		irrecv.resume();
	}
	if(flag) {
		if(readLine(LINE_PIN1) && readLine(LINE_PIN2)) {// black
			motorR.setSpeed(255);
			motorL.setSpeed(-255);
		} else if(readLine(LINE_PIN1) && !readLine(LINE_PIN2)) {
			motorR.setSpeed(255);
			motorL.setSpeed(-128);
		} else if(!readLine(LINE_PIN1) && readLine(LINE_PIN2)) {
			motorR.setSpeed(128);
			motorL.setSpeed(-255);
		} else {
			motorR.setSpeed(-255);
			motorL.setSpeed(256);
		}
	} else {
		motorR.setSpeed(0);
		motorL.setSpeed(0);
	}
	delay(100);
	
}

#define motorP motorR
#define okoPrzedPrawe LINE_PIN2
#define okoPrzedLewe LINE_PIN1

void testIRMotorsLine2() {
	if(irrecv.decode(&ir1)) {
		flag = flag ? 0 : 1;
		irrecv.resume();
	}
	if(flag) {
	
	
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



	} else {
		motorR.setSpeed(0);
		motorL.setSpeed(0);
	}
	delay(100);
	Serial.print(digitalRead(LINE_PIN1));
	Serial.println(digitalRead(LINE_PIN2));
}

void testIRMotorsSonic() {
	if(irrecv.decode(&ir1)) {
		flag = flag ? 0 : 1;
		irrecv.resume();
	}
	if(flag) {
		if(readSonic(sonar1) > 1) {
			motorR.setSpeed(255);
			motorL.setSpeed(-255);
		} else {
			motorR.setSpeed(0);
			motorL.setSpeed(0);
		}
	} else {
		motorR.setSpeed(0);
		motorL.setSpeed(0);
	}
	Serial.println(readSonic(sonar1));
	delay(75);
}

void testIRMotorsSonicRotation() {
	if(irrecv.decode(&ir1)) {
		flag = flag ? 0 : 1;
		irrecv.resume();
	}
	if(flag) {
		if(readSonic(sonar1) > 1) {
			motorR.setSpeed(255);
			motorL.setSpeed(255);
			delay(175);
		} else {
			motorR.setSpeed(0);
			motorL.setSpeed(0);
		}
	} else {
		motorR.setSpeed(0);
		motorL.setSpeed(0);
	}
	Serial.println(readSonic(sonar1));
	delay(75);
}

void testIRMotorsSonicRotation2() {
	if(irrecv.decode(&ir1)) {
		flag = flag ? 0 : 1;
		irrecv.resume();
	}
	if(flag) {
		if(readSonic(sonar1) > 1) {
			motorR.setSpeed(255);
			motorL.setSpeed(-255);
		} else if(readSonic(sonar2) > 1) {
			motorR.setSpeed(255);
			motorL.setSpeed(255);
		} else if(readSonic(sonar3) > 1) {
			motorR.setSpeed(-255);
			motorL.setSpeed(-255);
		} else {
			motorR.setSpeed(0);
			motorL.setSpeed(0);
		}
	} else {
		motorR.setSpeed(0);
		motorL.setSpeed(0);
	}
	delay(75);
}
