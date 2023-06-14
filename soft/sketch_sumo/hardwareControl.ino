// SENSORS
bool readLine(byte pin) {
	return digitalRead(pin) == HIGH;
}

int readSonic(NewPing sonar) {
	return sonar.ping_cm() + 1;// sensor gives distance 1 cm shorter than real value
}

// MOTORS
void goForward(byte speed) {
	motor(1, FORWARD, speed);
	motor(2, BACKWARD, speed);
}

void goBackwards(byte speed) {
	motor(1, BACKWARD, speed);
	motor(2, FORWARD, speed);
}

void goTurnR(byte speed) {
	motor(1, BACKWARD, speed);
	motor(2, FORWARD, speed);
}

void goArcR(byte speed, byte delta) {
	motor(1, BACKWARD, speed + delta);
	motor(2, FORWARD, speed - delta);
}

void goTurnL(byte speed) {
	motor(1, FORWARD, speed);
	motor(2, BACKWARD, speed);
}

void goArcL(byte speed, byte delta) {
	motor(1, FORWARD, speed - delta);
	motor(2, BACKWARD, speed + delta);
}
