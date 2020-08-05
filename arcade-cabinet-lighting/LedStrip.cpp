// 
// 
// 

#include "LedStrip.h"

void LedStripClass::setup(int pin, bool fadeStatus)
{
	pinMode(pin, OUTPUT);
	m_pin = pin;
	m_fade = fadeStatus;
	m_status = false;
	m_ledBrightness = 0;
}

bool LedStripClass::getLedStatus()
{
	return m_status;
}

bool LedStripClass::getFadeStatus()
{
	return m_fade;
}

void LedStripClass::on()
{
	m_status = true;

	if (m_fade)
		fadeOn();
	else 
		digitalWrite(m_pin, HIGH);
}

void LedStripClass::off()
{
	m_status = false;
	
	if (m_fade)
		fadeOff();
	else
		digitalWrite(m_pin, LOW);
}

void LedStripClass::toggleFade()
{
	m_fade = !m_fade;
}

void LedStripClass::fadeOn()
{
	if (m_ledBrightness < 255) {
		for (int i = m_ledBrightness; i <= 255; i += 5) {
			m_ledBrightness = i;
			analogWrite(m_pin, m_ledBrightness);
			delay(50);
		}
	}
}

void LedStripClass::fadeOff()
{
	if (m_ledBrightness > 0) {
		for (int i = m_ledBrightness; i >= 0; i -= 5) {
			m_ledBrightness = i;
			analogWrite(m_pin, m_ledBrightness);
			delay(50);
		}
	}
}



LedStripClass LedStrip;

