/*
 Name:		arcade_cabinet_lighting.ino
 Created:	8/4/2020 2:41:40 PM
 Author:	Matt Sutton
*/

// the setup function runs once when you press reset or power the board
#include "LedStrip.h"
#include "PirSensor.h"
#include "Button.h"

ButtonClass button;
PirSensorClass sensor;
LedStripClass led;

// Set the default system status.
boolean systemOn = false;

// the setup function runs once when you press reset or power the board
void setup() {
	// setup the button with the pin the button is using.
	button.setup(D2);

	// setup the PIR sensor with the pin the sensor is using.
	sensor.setup(D6);

	// setup the LED with the pin the sensor is using.
	led.setup(D5);
}

// the loop function runs over and over again until power down or reset
void loop() {
	// check to see if button is pressed and toggle the led fade status.
	if (button.isPressed()) {
		led.toggleFade();
	}
	
	sensor.update();

	if (sensor.motionDetected() && !systemOn) {
		// power on the system and turn the lights on if there system is off
		// and the sensor detects motion.
		systemOn = !systemOn;
		led.on();
	}
	else if (!sensor.motionDetected() && systemOn)
	{
		// post off the system and turn the light off is the system is on
		// and detects no motion. 
	
		// The sensor changes the motion detected 
		// state using a timer. So the turning off the system will be delayed.
		systemOn = !systemOn;
		led.off();
	}
}

