#include <NewPing.h>
#include <IRremote.h>

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

#define MAX_SONIC      50

NewPing sonar1(SONIC_TRIGGER1, SONIC_ECHO1, MAX_SONIC);
NewPing sonar2(SONIC_TRIGGER2, SONIC_ECHO2, MAX_SONIC);
NewPing sonar3(SONIC_TRIGGER3, SONIC_ECHO3, MAX_SONIC);
IRrecv  irrecv(IR_PIN);
decode_results ir1;

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

void loop() {
	testSonicSensors();
}

bool readLine(int pin) {
	return digitalRead(pin) == HIGH;
}

bool readShock() {
	return digitalRead(SHOCK_PIN) == HIGH;
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
	Serial.print(sonar1.ping_cm());
	Serial.print(" cm    Sonic 2: ");
	Serial.print(sonar2.ping_cm());
	Serial.print(" cm    Sonic 3: ");
	Serial.print(sonar3.ping_cm());
	Serial.print("\n");
	delay(50);
}
