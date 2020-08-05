// PirSensor.h

#ifndef _PIRSENSOR_h
#define _PIRSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PirSensorClass
{
 protected:
	 int _pin;
	 bool _motionDetected;
	 int _debounceTimeout;
	 int _motionTimeout;
	 unsigned long _motionStart;
 public:
	void init();
	PirSensorClass(int pin);
	bool motionDetected();
	void update();
};

extern PirSensorClass PirSensor;

#endif

