#define maxSpeed 255

void mainLoop() {
	switch(state) {
		case FIND:
			if(readSonic(sonarF) > 1) {
				state = ATTACK;
				break;
			}
			if(readSonic(sonarL) > 1) {
				while(readSonic(sonarF) == 1) {
					goTurnL(maxSpeed);
				}
				state = ATTACK;
				break;
			}
			if(readSonic(sonarR) > 1) {
				while(readSonic(sonarR) == 1) {
					goTurnR(maxSpeed);
				}
				state = ATTACK;
				break;
			}
			state = ROAM;
			break;
	}
}

void avoidFront() {
	goBackwards(-maxSpeed); // go back
	delay(1500);
	goTurnR(maxSpeed); // turn around
	delay(350);
}

void avoidFrontLeft() {
	if(readLine(LINE_PIN2)) {
		goTurnR(maxSpeed); // turn right
		delay(350);
	} else {
		avoidFront(); // both sensors see the line
	}
}

void avoidFrontRight() {
	if(readLine(LINE_PIN1)) {
		goTurnL(maxSpeed); // turn left
		delay(350);
	} else {
		avoidFront(); // both sensors see the line
	}
}

