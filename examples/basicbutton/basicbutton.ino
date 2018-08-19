/*
  Basic button example.  
  A re-implementation of https://www.arduino.cc/en/tutorial/switch
  Created by Patrick Stockton
  version: 0.0.1
*/

#include <led.hpp>
#include <button.hpp>

// To see the two various modes a button can act uncomment this line and comment the other one out
// slacker::Button::ButtonType _buttonType = slacker::Button::ButtonType::Toggle;
slacker::Button::ButtonType _buttonType = slacker::Button::ButtonType::Momentary;
slacker::Button _button(2, _buttonType);
slacker::Led _led(13);

void setup() {
}

void loop() {

  if (_button.ButtonPressed()) {
    _led.On();
  } else {
    _led.Off();
  }
}