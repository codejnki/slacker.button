/*
  button.cpp - Implements button.h
  Created by Patrick Stockton
  version: 0.0.1
*/

#include "Arduino.h"
#include "button.h"

namespace slacker
{
  unsigned long lastDebounceTime = 0;
  unsigned long debounceDelay = 200;

  Button::Button(int pin, Button::ButtonType buttonType)
  {
    _pin = pin;
    _lastButtonState = LOW;
    _buttonType = buttonType;
    _switchState = false;
    pinMode(_pin, INPUT);
  }

  bool Button::ButtonPressed()
  {
    switch (_buttonType)
    {
      case Momentary:
        return this -> ReadMomentary();
        break;
      case Toggle:
        return this -> ReadToggle();
        break;
    }
  }

  bool Button::ReadMomentary()
  {
    int buttonRead = digitalRead(_pin);

    if(buttonRead == _lastButtonState == false)
    {
      lastDebounceTime = millis();
    }

    if((millis() - lastDebounceTime) > debounceDelay) {
      if(buttonRead == _buttonState == false)
      {
        _buttonState = buttonRead;
      }
    }

    _lastButtonState = buttonRead;
    
    return buttonRead;
  }

  bool Button::ReadToggle()
  {
    // i really hate this code
    // i basically repurposed the arduino switch tutorial
    // https://www.arduino.cc/en/tutorial/switch
    // i'm pretty sure this can be made better but i'm going
    // to not worry about it at the moment, it does what i need it to

    int reading = digitalRead(_pin);
    if(reading == HIGH && _previous == LOW && millis() - _time > debounceDelay)
    {
      if(_switchState == HIGH)
      {
        _switchState = LOW;
      }
      else
      {
        _switchState = HIGH;
      }
      _time = millis();
    }

    _previous = reading;
    return _switchState;
  }
}