// 
// 
// 

#include "PirSensor.h"

void PirSensorClass::init()
{
}

void PirSensorClass::setup(int pin, int debounceTimeout, long motionTimeout)
{
	pinMode(pin, INPUT);
	_motionDetected = false;
	_pin = pin;
	_debounceTimeout = debounceTimeout;
	_motionStart = 0;
	_motionTimeout = motionTimeout;
}

bool PirSensorClass::motionDetected()
{
	return _motionDetected;
}

void PirSensorClass::update()
{
	int reading = digitalRead(_pin);

	if (reading == HIGH) {
		_motionDetected = true;
		_motionStart = millis();
	}
	else if (reading == LOW && (millis() - _motionStart) > _motionTimeout) {
		_motionDetected = false;
	}

}
