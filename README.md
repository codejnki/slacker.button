# slacker.button

An exceedingly simple button class to help with things.  Utilizes a 200 ms debounce.

## Installation and usage

To install this library just place the entire sub folder in your library folder.

```cpp
#include <button.h>

// The button class supports two different modes, momentary or switch
// Momentary will return a value while a button is actively being pressed
// Toggle will switch state on each button press much like a lightswitch

slacker::Button::ButtonType _buttonType = slacker::Button::ButtonType::Momentary;
slacker::Button _button(2, _buttonType);

// your code goes here
```

## Methods

```cpp
ButtonPressed();
```

Will return `true` if the button has been pressed.  Can be used in either __toggle__ or __momentary__ mode.

## ToDo

So I'm not terribly happy with this code at the moment.

* Code refactor to clean up the two main button Methods
* Implement a counter property
