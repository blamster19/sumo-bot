// SENSORS
bool readLine(int pin) {
	return digitalRead(pin) == HIGH;
}

bool readShock() {
	return digitalRead(SHOCK_PIN) == HIGH;
}

int readSonic(NewPing sonar) {
	return sonar.ping_cm() + 1;// sensor gives distance 1 cm shorter than real value
}

// MOTORS
void goForward(int speed) {
	motorL.setSpeed(speed);
	motorR.setSpeed(speed);
}

void goTurn(int speed) {
	motorL.setSpeed(speed);
	motorR.setSpeed(-speed);
}

void goArc(int speed, int delta) {
	motorL.setSpeed(speed + delta);
	motorR.setSpeed(speed - delta);
}
