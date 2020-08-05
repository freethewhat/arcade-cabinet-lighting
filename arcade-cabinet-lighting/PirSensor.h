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
	 long _motionTimeout;
	 unsigned long _motionStart;
 public:
	void init();
	void setup(int pin, int debounceTimeout = 30, long motionTimeout = 10000);
	bool motionDetected();
	void update();
};

extern PirSensorClass PirSensor;

#endif

