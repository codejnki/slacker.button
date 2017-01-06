/*
  button.h - button library for using a button
  Created by Patrick Stockton
  version: 2.0.0
*/

#ifndef button_h
#define button_h

#include "Arduino.h"

namespace slacker
{
  class Button
  {
    public:
      enum ButtonType { Momentary, Toggle };
      Button(int pin, Button::ButtonType buttonType);
      Button(int pin, Button::ButtonType buttonType, long debounceDelay);
      bool ButtonPressed();
      int GetButtonCounter();
      void ResetButtonCounter();
    private:
      int _pin;
      int _lastButtonState;
      int _buttonState;
      bool _switchState;
      ButtonType _buttonType;
      bool ReadMomentary();
      bool ReadToggle();

      int _previous;
      unsigned long _time;
  };
}

#endif