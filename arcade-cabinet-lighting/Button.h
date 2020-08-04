// Button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ButtonClass
{
protected:
	int _pin;
	unsigned long _debounceDelay;
	unsigned long _lastDebounceTime;
	int _state;
	int _lastState;
	bool _status;
public:
	void init();
	ButtonClass(int pin);
	bool isPressed();
	bool getStatus();
};

extern ButtonClass Button;


#endif

