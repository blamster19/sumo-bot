#include <NewPing.h>
#include <IRremote.h>
#include <Servo.h>
#include "pinDefinitions.h"

NewPing sonar1(SONIC_TRIGGER1, SONIC_ECHO1, MAX_SONIC);
NewPing sonar2(SONIC_TRIGGER2, SONIC_ECHO2, MAX_SONIC);
NewPing sonar3(SONIC_TRIGGER3, SONIC_ECHO3, MAX_SONIC);
IRrecv  irrecv(IR_PIN);
decode_results ir1;

void setup() {
	irrecv.enableIRIn();
	pinMode(LINE_PIN1, INPUT_PULLUP);
	pinMode(LINE_PIN2, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(LINE_PIN1), avoidFrontLeft, LOW);
	attachInterrupt(digitalPinToInterrupt(LINE_PIN2), avoidFrontRight, LOW);
}

enum mode {
	ROAM,
	BACKOFF,
	ATTACK,
	FIND
};

mode state = ROAM;
byte onOff = 0;

#define sonarL sonar1
#define sonarR sonar2
#define sonarF sonar3

void loop() {
	if(irrecv.decode(&ir1)) {
		onOff = onOff ? 0 : 1;
		irrecv.resume();
	}
	if(onOff) {
		mainLoop();
	} else {
		goForward(0);
	}
	delay(75);
}

