#define maxSpeed 255

void mainLoop() {
	switch(state) {
		case FIND:
			if(readSonic(sonarF) > 1) { // if enemy in front of
				state = ATTACK;
				break;
			}
			if(readSonic(sonarL) > 1) { // if enemy on the left
				while(readSonic(sonarF) == 1) {
					goTurnL(maxSpeed);
				}
				state = ATTACK;
				break;
			}
			if(readSonic(sonarR) > 1) { // if enemy on the right
				while(readSonic(sonarR) == 1) {
					goTurnR(maxSpeed);
				}
				state = ATTACK;
				break;
			}
			state = ROAM; // else wander
			break;
		case ATTACK:
			goForward(maxSpeed);
			break;
		case ROAM:
			goArcL(maxSpeed - 10, 10);
			state = FIND;
			break;
	}
}

void avoidFront() {
	if(onOff) {
		goBackwards(maxSpeed); // go back
		delay(1500);
		goTurnR(maxSpeed); // turn around
		delay(350);
	}
}

void avoidFrontLeft() {
	if(onOff) {
		if(readLine(LINE_PIN2)) {
			goTurnR(maxSpeed); // turn right
			delay(350);
		} else {
			avoidFront(); // both sensors see the line
		}
	}
}

void avoidFrontRight() {
	if(onOff) {
		if(readLine(LINE_PIN1)) {
			goTurnL(maxSpeed); // turn left
			delay(350);
		} else {
			avoidFront(); // both sensors see the line
		}
	}
}

