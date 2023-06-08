// SENSORS
bool readLine(byte pin) {
	return digitalRead(pin) == HIGH;
}

bool readShock() {
	return digitalRead(SHOCK_PIN) == HIGH;
}

int readSonic(NewPing sonar) {
	return sonar.ping_cm() + 1;// sensor gives distance 1 cm shorter than real value
}

// MOTORS
void goForward(byte speed) {
	motorL.setSpeed(speed);
	motorR.setSpeed(speed);
}

void goTurnR(byte speed) {
	motorL.setSpeed(speed);
	motorR.setSpeed(-speed);
}

void goArcR(byte speed, byte delta) {
	motorL.setSpeed(speed + delta);
	motorR.setSpeed(speed - delta);
}

void goTurnL(byte speed) {
	motorL.setSpeed(-speed);
	motorR.setSpeed(speed);
}

void goArcL(byte speed, byte delta) {
	motorL.setSpeed(speed - delta);
	motorR.setSpeed(speed + delta);
}
