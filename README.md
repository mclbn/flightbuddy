# Flight Buddy

## Why ?

I recently started to enjoy the [Falcon BMS](https://www.falcon-bms.com/) simulator. I use a HOTAS for most of the controls and an android tablet for MFDs, but I found that using the keyboard to access ICP features is at best annoying and quite immersion-breaking. 
So, here is a very simple quick-and-dirty button box that mimics this ICP. It was made with what was hanging around in my drawers and can certainly be VASTLY improved.

## What ?

![Front](pictures/front.jpg?raw=true "Front")

Not very pretty, but functionnal. That's all I asked ;-)

## How ?

First, the hardware. Sorry, no exhaustive bill of material but it's really a simplistic project. I used a Teensy 3.1 because I had one on hand, but it can most definitely be done with a cheaper Atmega32u4 board.

Buttons and switch are dull regular ones. The keypad on the left is made of blue Cherry MX leftovers from a custom keyboard build. Since I did not have at hand a bidirectionnal switch, the two bottom left switch act as up-down and left-right joystick hat, instead of the ICP 4-way Data Command Switch.

All of this is wired in a 6x6 matrix. No diodes though, so simultaneous keypresses are very likely to cause ghosting issues.

![Front](pictures/wiring.jpg?raw=true "Front")

The Teensy board is plugged on a prototyping board because I want to be able to easily repurpose it without any desoldering if I stop using the Flight Buddy.

On the software side, it's a very simple sketch using [Arduino Keypad library](https://playground.arduino.cc/Code/Keypad/) and [Teensy Keyboard library](https://www.pjrc.com/teensy/td_keyboard.html). I use [PlatformIO](https://platformio.org/) to compile and upload.

