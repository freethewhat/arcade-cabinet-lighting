// 
// 
// 

#include "LedStrip.h"

/// <summary>
/// Setup the led configuration.
/// </summary>
/// <param name="pin">Pin of the LED</param>
/// <param name="fadeStatus">Status of the fade.</param>
void LedStripClass::setup(int pin, bool fadeStatus)
{
	pinMode(pin, OUTPUT);
	m_pin = pin;
	m_fade = fadeStatus;
	m_status = false;
	m_ledBrightness = 0;
}

/// <summary>
/// Get the status of the LED.
/// </summary>
/// <returns>Boolean</returns>
bool LedStripClass::getLedStatus()
{
	return m_status;
}

/// <summary>
/// Get the status of fading.
/// </summary>
/// <returns>Boolean</returns>
bool LedStripClass::getFadeStatus()
{
	return m_fade;
}

/// <summary>
/// Turn the LED on.
/// </summary>
void LedStripClass::on()
{
	m_status = true;

	if (m_fade)
		fadeOn();
	else 
		digitalWrite(m_pin, HIGH);
}

/// <summary>
/// Turn the LED off.
/// </summary>
void LedStripClass::off()
{
	m_status = false;
	
	if (m_fade)
		fadeOff();
	else
		digitalWrite(m_pin, LOW);
}

/// <summary>
/// Toggle the fade status.
/// </summary>
void LedStripClass::toggleFade()
{
	m_fade = !m_fade;
}

/// <summary>
/// Fade the LED on.
/// </summary>
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

/// <summary>
/// Fade the LED off.
/// </summary>
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

