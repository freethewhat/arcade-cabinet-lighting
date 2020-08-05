// 
// 
// 

#include "Button.h"

void ButtonClass::init()
{

}

void ButtonClass::setup(int pin, unsigned long debounceDelay) {
    pinMode(pin, INPUT);
    _pin = pin;
    _state;
    _lastState = LOW;
    _lastDebounceTime = 0;
    _debounceDelay = 30;
    _status = false;
}

bool ButtonClass::isPressed()
{
    boolean retval = false;

    int reading = digitalRead(_pin);

    // Set the last debounce time if the last known state is not equal 
    // to the current reading. This prevents any noise from being misread
    // and is safe to assume this is on purpose.
    if (reading != _lastState)
        _lastDebounceTime = millis();

    // Continue to check button if the button has been pressed longer than
    // the allotted debounce delay.
    if ((millis() - _lastDebounceTime) > _debounceDelay)
    {
        // store the reading state in case the button is released during processing.
        if (reading != _state) {
            _state = reading;

            if (_state == HIGH)
            {
                // set the return value and change the button state on/off
                retval = true;
                _status = !_status;
            }
        }
    }

    _lastState = reading;
    return retval; // return that the button has been pressed.
}

bool ButtonClass::getStatus()
{
    return _status;
}
