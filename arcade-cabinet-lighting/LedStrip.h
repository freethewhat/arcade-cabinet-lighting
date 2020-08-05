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
	void setup(int pin, bool fade = false);
	bool getLedStatus();
	bool getFadeStatus();
	void on();
	void off();
	void toggleFade();
 protected:
	 /// <summary>
	 /// Pin of the LED.
	 /// </summary>
	 int m_pin;

	 /// <summary>
	 /// Status of the LED.
	 /// </summary>
	 bool m_status;

	 /// <summary>
	 /// Status of fading.
	 /// </summary>
	 bool m_fade;

	 /// <summary>
	 /// Brightness of the LED.
	 /// </summary>
	 int m_ledBrightness;

	 void fadeOn();
	 void fadeOff();

};

extern LedStripClass LedStrip;

#endif

