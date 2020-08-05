// 
// 
// 

#include "PirSensor.h"

void PirSensorClass::init()
{
}

PirSensorClass::PirSensorClass(int pin)
{
	pinMode(pin, INPUT);
	_pin = pin;
	_debounceTimeout = 30;
	_motionStart = 0;
	_motionTimeout = 3000;
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
