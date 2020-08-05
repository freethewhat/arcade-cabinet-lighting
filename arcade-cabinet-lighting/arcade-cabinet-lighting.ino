/*
 Name:		arcade_cabinet_lighting.ino
 Created:	8/4/2020 2:41:40 PM
 Author:	home
*/

// the setup function runs once when you press reset or power the board
#include "PirSensor.h"
#include "Button.h"

ButtonClass button;
PirSensorClass sensor;

boolean systemOn = false;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	Serial.println("Start");

	button.setup(D2);
	sensor.setup(D6);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (button.isPressed()) {
		// TODO: toggle LED strip fading
		Serial.println("Button Pressed");
	}
	
	sensor.update();

	if (sensor.motionDetected() && !systemOn) {
		Serial.println("System On");
		systemOn = !systemOn;
	}
	else if (!sensor.motionDetected() && systemOn)
	{
		Serial.println("System Off");
		systemOn = !systemOn;
	}
}

