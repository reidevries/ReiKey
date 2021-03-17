#include "WProgram.h"
#include <usb_keyboard.h>
#include "pin_assignment.h"

#define KEY_MENU                ( 101  | 0xF000 )
#define KEY_F13                 ( 104  | 0xF000 )
#define KEY_F14                 ( 105  | 0xF000 )
#define KEY_F15                 ( 106  | 0xF000 )
#define KEY_F16                 ( 107  | 0xF000 )
#define KEY_F17                 ( 108  | 0xF000 )
#define KEY_F18                 ( 109  | 0xF000 )
#define KEY_F19                 ( 110  | 0xF000 )
#define KEY_F20                 ( 111  | 0xF000 )
#define KEY_F21                 ( 112  | 0xF000 )
#define KEY_F22                 ( 113  | 0xF000 )
#define KEY_F23                 ( 114  | 0xF000 )
#define KEY_F24                 ( 115  | 0xF000 )

//checks if a button on a given pin has been pressed or released
#define PRESSED 2
#define RELEASED 1
int held[10][10] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int held_R11 = 0;

uint8_t checkPin(int pin, int* held)
{
	int val = digitalRead(pin);
	if (val == LOW && *held == 0) {
		*held = 1;
		return PRESSED;
	} else if (val == HIGH && *held == 1) {
		*held = 0;
		return RELEASED;
	}
	return 0;
}

//checks if a button at a given row and column in the key matrix has been
//pressed or released, and sends the matching keycode via usb
void checkKey(int row, int col)
{
	uint8_t status = checkPin(ROWS[row], &held[row][col]);
	if (status == PRESSED) {
		usb_keyboard_press_keycode(key_matrix[row][col]);
	} else if (status == RELEASED) {
		usb_keyboard_release_keycode(key_matrix[row][col]);
	}
}

//sets a given column index to ground, and the rest to Hi-Z
void setupCol(int col)
{
	for (int i = 0; i < col; ++i) {
		pinMode(COLS[i], INPUT);
	}
	pinMode(COLS[col], OUTPUT);
	digitalWrite(COLS[col], LOW);
	for (int i = col+1; i<10; ++i) {
		pinMode(COLS[i], INPUT);
	}
}

int main(void)
{	
	delay(1000); //make sure op sys has enough time to register input device
	// set up pins to the correct modes
	pinMode(NUM_LED, OUTPUT);
	pinMode(CAP_LED, OUTPUT);
	pinMode(PIN_R11, INPUT_PULLUP);
	for (int i = 0; i < 10; ++i) {
		pinMode(ROWS[i], INPUT_PULLUP);
	}
	// set the dead pins to be just inputs
	pinMode(10, INPUT);
	pinMode(11, INPUT);
	
	int col = 0;
	for (;;) {
		//update num/caps lock LED
		digitalWrite(NUM_LED, keyboard_leds&0x01);
		digitalWrite(CAP_LED, (keyboard_leds&0x02)>>1);
		
		//set up the current column
		setupCol(col);
		// delay to avoid retriggering and up arrow triggering page down
		delayMicroseconds(500);
	
		//check each row in the column for key presses
		for (int row = 0; row < 10; ++row) {
			checkKey(row, col);
		}

		//manually check row 11 as it is always grounded
		int status = checkPin(PIN_R11, &held_R11);
		if (status == PRESSED) {
			usb_keyboard_press_keycode(KEY_DELETE);
		} else if (status == RELEASED) {
			usb_keyboard_release_keycode(KEY_DELETE);
		}
		col = (col+1)%10;
	}
}
