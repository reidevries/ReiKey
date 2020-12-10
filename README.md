# ReiKey
DIY Keyboard custom design

This is a plateless PCB-based mechanical keyboard inspired by [JayK](https://github.com/josuegaleas/JayK) and [ONO-SENDAI MATRIX 83](https://imgur.com/a/v5pzh#FiXKcm0). I've been using it as my main keyboard for a while and it works pretty well!

## Layout:
I used a highly customized 101 key layout, it is almost impossible to find full keycap sets to fit this layout. The numpad is on the left, which I find to be more ergonomic when using the arrow keys or mouse for data entry. It has big 1.5u function keys and navigation keys inspired by the Amiga 500 keyboard layout. It also has the big-ass enter key and double 2.75u shift keys. The backslash key is where the tilde key and the caps lock key is 1u to make space for the tilde key. I scrapped the printscreen, pause and scroll lock keys because I never use them. 

## Electronic Design:
It has a 10x10 keyboard matrix with the F12 key going directly to ground. The only LEDs are under the caps lock and num lock keys, and a power LED above the arrow keys. It uses a Teensy LC as the microcontroller.

## Programming:
I used C with the Teensy/Arduino keyboard libraries to register keypresses and send them to a computer. Thanks to @cruxic for the [Teensy makefile](https://github.com/cruxic/teensy-makefile). It has a delay of ~150us between checking each column to avoid duplicate keypresses. Simply build the board, plug in the Teensy LC via usb, install Teensy/arduino libraries correctly, then type `make load` and you should get a working keyboard.
