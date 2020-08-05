// LedStrip.h

#ifndef _LEDSTRIP_h
#define _LEDSTRIP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class LedStripClass
{
 public:
	void init();
	void setup(int pin, bool fade = false);
	bool getLedStatus();
	bool getFadeStatus();
	void on();
	void off();
	void toggleFade();
 protected:
	 int m_pin;
	 bool m_status;
	 bool m_fade;
	 int m_ledBrightness;
	 void fadeOn();
	 void fadeOff();

};

extern LedStripClass LedStrip;

#endif

