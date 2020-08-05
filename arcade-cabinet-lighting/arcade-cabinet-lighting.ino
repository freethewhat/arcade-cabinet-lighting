/*
 Name:		arcade_cabinet_lighting.ino
 Created:	8/4/2020 2:41:40 PM
 Author:	home
*/

// the setup function runs once when you press reset or power the board
#include "PirSensor.h"
#include "Button.h"

ButtonClass button(D2);
PirSensorClass sensor(D6);

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	Serial.println("Start");
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (button.isPressed()) {
		// TODO: toggle LED strip fading
	}
	
	sensor.update();

	if (sensor.motionDetected())
		Serial.println("Motion Detected");
	else if (!sensor.motionDetected())
		Serial.println("Motion Not Detected");
}

