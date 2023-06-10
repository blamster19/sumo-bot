void mainLoop() {
	
}

#define maxSpeed 255

void avoidFront() {
	goForward(-maxSpeed); // go back
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

