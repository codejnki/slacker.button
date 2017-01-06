# slacker.button

An exceedingly simple button class to help with things.  Utilizes a 200 ms debounce.

## Version 2.0.0 Update

For version 2 I changed the include to be a `.hpp` file since I'm doing this as a cpp class.

## Installation and usage

To install this library just place the entire sub folder in your library folder.

```cpp
#include <button.hpp>

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


```cpp
GetButtonCounter()
```

When the button is in toggle mode this will return a counter that increments each time the button is flipped to the __on__ state.

```cpp
ResetButtonCounter()
```

Will reset the counter back to zero.

## ToDo

So I'm not terribly happy with this code at the moment.

* Code refactor to clean up the two main button Methods
* ~~Implement a counter property~~
* Implement a counter in momentary mode that tells you how long the button has been held down.
