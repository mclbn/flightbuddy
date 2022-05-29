#include <Keypad.h>
#include <Keyboard.h>

#define NB_COLS (6)
#define NB_ROWS (6)

byte col_pins[NB_COLS] = {0, 1, 2, 3, 4, 5};
byte row_pins[NB_ROWS] = {23, 22, 21, 20, 19, 18};

char keys[NB_ROWS][NB_COLS] = {
  {1, 2, 3, 4, 5, 6},
  {7, 8, 9, 10, 19, 23},
  {11, 12, 13, 14, 20, 24},
  {15, 16, 17, 18, 21, 25},
  {33, 35, 27, 30, 22, 26},
  {34, 36, 28, 31}
};

Keypad kpd = Keypad(makeKeymap(keys), row_pins, col_pins, NB_ROWS, NB_COLS);

void
setup() {
  for (int i = 0; i < NB_COLS; i++)
    pinMode(col_pins[i], INPUT_PULLUP);
  for (int i = 0; i < NB_ROWS; i++)
    pinMode(row_pins[i], INPUT_PULLUP);
}

void
loop() {

  if (kpd.getKeys()) {
    for (int i = 0; i < LIST_MAX; i++) {
      if (kpd.key[i].stateChanged) {

	switch (kpd.key[i].kstate) {
	case PRESSED:
	  if (kpd.key[i].kchar == 33) {
	    Joystick.hat(180);
	    Keyboard.press(KEY_DOWN);
	  } else if (kpd.key[i].kchar == 34) {
	    Joystick.hat(0);
	    Keyboard.press(KEY_UP);
	  } else if (kpd.key[i].kchar == 35) {
	    Joystick.hat(270);
	    Keyboard.press(KEY_LEFT);
	  } else if (kpd.key[i].kchar == 36) {
	    Joystick.hat(90);
	    Keyboard.press(KEY_RIGHT);
	  } else if (kpd.key[i].kchar == 27
		   || kpd.key[i].kchar == 28) {
	    Joystick.button(29, 0);
	    Joystick.button(kpd.key[i].kchar, 1);
	    delay(50);
	    Joystick.button(kpd.key[i].kchar, 0);
	  } else if (kpd.key[i].kchar == 30
		     || kpd.key[i].kchar == 31) {
	    Joystick.button(32, 0);
	    Joystick.button(kpd.key[i].kchar, 1);
	    delay(50);
	    Joystick.button(kpd.key[i].kchar, 0);
	  } else
	    Joystick.button(kpd.key[i].kchar, 1);
	  break;
	case HOLD:
	  break;
	case RELEASED:
	  if (kpd.key[i].kchar == 33) {
	    Joystick.hat(-1);
	    Keyboard.release(KEY_DOWN);
	  } else if (kpd.key[i].kchar == 34) {
	    Joystick.hat(-1);
	    Keyboard.release(KEY_UP);
	  } else if  (kpd.key[i].kchar == 35) {
	    Joystick.hat(-1);
	    Keyboard.release(KEY_LEFT);
	  } else if (kpd.key[i].kchar == 36) {
	    Joystick.hat(-1);
	    Keyboard.release(KEY_RIGHT);
	  } else if (kpd.key[i].kchar == 27
		   || kpd.key[i].kchar == 28) {
	    Joystick.button(kpd.key[i].kchar, 0);
	    Joystick.button(29, 1);
	    delay(50);
	    Joystick.button(29, 0);
	  } else if (kpd.key[i].kchar == 30
		     || kpd.key[i].kchar == 31) {
	    Joystick.button(kpd.key[i].kchar, 0);
	    Joystick.button(32, 1);
	    delay(50);
	    Joystick.button(32, 0);
	  } else
	    Joystick.button(kpd.key[i].kchar, 0);
	  break;
	case IDLE:
	  break;
	}

      }
    }
  }
}
