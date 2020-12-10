#include "WProgram.h"
#include <usb_keyboard.h>
#define MANUFACTURER_NAME	{'R','e','i',' ','d','e',' ','V','r','i','e','s'}
#define MANUFACTURER_NAME_LEN	12
#define PRODUCT_NAME		{'R','e','i','K','e','y'}
#define PRODUCT_NAME_LEN		6

/*
#define MODIFIERKEY_CTRL        ( 0x01 | 0xE000 )
#define MODIFIERKEY_SHIFT       ( 0x02 | 0xE000 )
#define MODIFIERKEY_ALT         ( 0x04 | 0xE000 )
#define MODIFIERKEY_GUI         ( 0x08 | 0xE000 )
#define MODIFIERKEY_LEFT_CTRL   ( 0x01 | 0xE000 )
#define MODIFIERKEY_LEFT_SHIFT  ( 0x02 | 0xE000 )
#define MODIFIERKEY_LEFT_ALT    ( 0x04 | 0xE000 )
#define MODIFIERKEY_LEFT_GUI    ( 0x08 | 0xE000 )
#define MODIFIERKEY_RIGHT_CTRL  ( 0x10 | 0xE000 )
#define MODIFIERKEY_RIGHT_SHIFT ( 0x20 | 0xE000 )
#define MODIFIERKEY_RIGHT_ALT   ( 0x40 | 0xE000 )
#define MODIFIERKEY_RIGHT_GUI   ( 0x80 | 0xE000 )

#define KEY_SYSTEM_POWER_DOWN   ( 0x81 | 0xE200 )
#define KEY_SYSTEM_SLEEP        ( 0x82 | 0xE200 )
#define KEY_SYSTEM_WAKE_UP      ( 0x83 | 0xE200 )

#define KEY_MEDIA_PLAY          ( 0xB0 | 0xE400 )
#define KEY_MEDIA_PAUSE         ( 0xB1 | 0xE400 )
#define KEY_MEDIA_RECORD        ( 0xB2 | 0xE400 )
#define KEY_MEDIA_FAST_FORWARD  ( 0xB3 | 0xE400 )
#define KEY_MEDIA_REWIND        ( 0xB4 | 0xE400 )
#define KEY_MEDIA_NEXT_TRACK    ( 0xB5 | 0xE400 )
#define KEY_MEDIA_PREV_TRACK    ( 0xB6 | 0xE400 )
#define KEY_MEDIA_STOP          ( 0xB7 | 0xE400 )
#define KEY_MEDIA_EJECT         ( 0xB8 | 0xE400 )
#define KEY_MEDIA_RANDOM_PLAY   ( 0xB9 | 0xE400 )
#define KEY_MEDIA_PLAY_PAUSE    ( 0xCD | 0xE400 )
#define KEY_MEDIA_PLAY_SKIP     ( 0xCE | 0xE400 )
#define KEY_MEDIA_MUTE          ( 0xE2 | 0xE400 )
#define KEY_MEDIA_VOLUME_INC    ( 0xE9 | 0xE400 )
#define KEY_MEDIA_VOLUME_DEC    ( 0xEA | 0xE400 )

#define KEY_A                   (   4  | 0xF000 )
#define KEY_B                   (   5  | 0xF000 )
#define KEY_C                   (   6  | 0xF000 )
#define KEY_D                   (   7  | 0xF000 )
#define KEY_E                   (   8  | 0xF000 )
#define KEY_F                   (   9  | 0xF000 )
#define KEY_G                   (  10  | 0xF000 )
#define KEY_H                   (  11  | 0xF000 )
#define KEY_I                   (  12  | 0xF000 )
#define KEY_J                   (  13  | 0xF000 )
#define KEY_K                   (  14  | 0xF000 )
#define KEY_L                   (  15  | 0xF000 )
#define KEY_M                   (  16  | 0xF000 )
#define KEY_N                   (  17  | 0xF000 )
#define KEY_O                   (  18  | 0xF000 )
#define KEY_P                   (  19  | 0xF000 )
#define KEY_Q                   (  20  | 0xF000 )
#define KEY_R                   (  21  | 0xF000 )
#define KEY_S                   (  22  | 0xF000 )
#define KEY_T                   (  23  | 0xF000 )
#define KEY_U                   (  24  | 0xF000 )
#define KEY_V                   (  25  | 0xF000 )
#define KEY_W                   (  26  | 0xF000 )
#define KEY_X                   (  27  | 0xF000 )
#define KEY_Y                   (  28  | 0xF000 )
#define KEY_Z                   (  29  | 0xF000 )
#define KEY_1                   (  30  | 0xF000 )
#define KEY_2                   (  31  | 0xF000 )
#define KEY_3                   (  32  | 0xF000 )
#define KEY_4                   (  33  | 0xF000 )
#define KEY_5                   (  34  | 0xF000 )
#define KEY_6                   (  35  | 0xF000 )
#define KEY_7                   (  36  | 0xF000 )
#define KEY_8                   (  37  | 0xF000 )
#define KEY_9                   (  38  | 0xF000 )
#define KEY_0                   (  39  | 0xF000 )
#define KEY_ENTER               (  40  | 0xF000 )
#define KEY_ESC                 (  41  | 0xF000 )
#define KEY_BACKSPACE           (  42  | 0xF000 )
#define KEY_TAB                 (  43  | 0xF000 )
#define KEY_SPACE               (  44  | 0xF000 )
#define KEY_MINUS               (  45  | 0xF000 )
#define KEY_EQUAL               (  46  | 0xF000 )
#define KEY_LEFT_BRACE          (  47  | 0xF000 )
#define KEY_RIGHT_BRACE         (  48  | 0xF000 )
#define KEY_BACKSLASH           (  49  | 0xF000 )
#define KEY_NON_US_NUM          (  50  | 0xF000 )
#define KEY_SEMICOLON           (  51  | 0xF000 )
#define KEY_QUOTE               (  52  | 0xF000 )
#define KEY_TILDE               (  53  | 0xF000 )
#define KEY_COMMA               (  54  | 0xF000 )
#define KEY_PERIOD              (  55  | 0xF000 )
#define KEY_SLASH               (  56  | 0xF000 )
#define KEY_CAPS_LOCK           (  57  | 0xF000 )
#define KEY_F1                  (  58  | 0xF000 )
#define KEY_F2                  (  59  | 0xF000 )
#define KEY_F3                  (  60  | 0xF000 )
#define KEY_F4                  (  61  | 0xF000 )
#define KEY_F5                  (  62  | 0xF000 )
#define KEY_F6                  (  63  | 0xF000 )
#define KEY_F7                  (  64  | 0xF000 )
#define KEY_F8                  (  65  | 0xF000 )
#define KEY_F9                  (  66  | 0xF000 )
#define KEY_F10                 (  67  | 0xF000 )
#define KEY_F11                 (  68  | 0xF000 )
#define KEY_F12                 (  69  | 0xF000 )
#define KEY_PRINTSCREEN         (  70  | 0xF000 )
#define KEY_SCROLL_LOCK         (  71  | 0xF000 )
#define KEY_PAUSE               (  72  | 0xF000 )
#define KEY_INSERT              (  73  | 0xF000 )
#define KEY_HOME                (  74  | 0xF000 )
#define KEY_PAGE_UP             (  75  | 0xF000 )
#define KEY_DELETE              (  76  | 0xF000 )
#define KEY_END                 (  77  | 0xF000 )
#define KEY_PAGE_DOWN           (  78  | 0xF000 )
#define KEY_RIGHT               (  79  | 0xF000 )
#define KEY_LEFT                (  80  | 0xF000 )
#define KEY_DOWN                (  81  | 0xF000 )
#define KEY_UP                  (  82  | 0xF000 )
#define KEY_NUM_LOCK            (  83  | 0xF000 )
#define KEYPAD_SLASH            (  84  | 0xF000 )
#define KEYPAD_ASTERIX          (  85  | 0xF000 )
#define KEYPAD_MINUS            (  86  | 0xF000 )
#define KEYPAD_PLUS             (  87  | 0xF000 )
#define KEYPAD_ENTER            (  88  | 0xF000 )
#define KEYPAD_1                (  89  | 0xF000 )
#define KEYPAD_2                (  90  | 0xF000 )
#define KEYPAD_3                (  91  | 0xF000 )
#define KEYPAD_4                (  92  | 0xF000 )
#define KEYPAD_5                (  93  | 0xF000 )
#define KEYPAD_6                (  94  | 0xF000 )
#define KEYPAD_7                (  95  | 0xF000 )
#define KEYPAD_8                (  96  | 0xF000 )
#define KEYPAD_9                (  97  | 0xF000 )
#define KEYPAD_0                (  98  | 0xF000 )
#define KEYPAD_PERIOD           (  99  | 0xF000 )
#define KEY_NON_US_BS           ( 100  | 0xF000 )
#define KEY_MENU        	( 101  | 0xF000 )
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
*/


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

#define NUM_LED  0
#define CAP_LED 12

// keyboard drives thru cols and reads thru rows
#define PIN_F12  1
int ROWS[] = { 25, 24,  9,  8,  7,  6,  5,  4,  3,  2 };
int COLS[] = { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };

uint16_t key_matrix[10][10] = {
	{ KEY_PAGE_DOWN, KEY_PAGE_UP, KEY_INSERT, KEY_DELETE, KEY_HOME, 
		KEY_END, KEY_RIGHT, KEY_DOWN, KEY_LEFT, KEY_UP },
	{ KEY_CAPS_LOCK, KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_LEFT_ALT,
		KEY_LEFT_GUI, KEY_RIGHT_GUI, KEY_RIGHT_ALT, KEY_RIGHT_CTRL,
		KEY_NON_US_BS, KEY_RIGHT_SHIFT},
	{ KEY_TAB, KEY_TILDE, KEY_A, KEY_Z, KEY_X, KEY_SPACE, KEY_COMMA,
		KEY_PERIOD, KEY_SLASH, KEY_ENTER },
	{ KEY_BACKSLASH, KEY_Q, KEY_S, KEY_D, KEY_C, 
		KEY_V, KEY_M, KEY_L, KEY_SEMICOLON, KEY_QUOTE },
	{ KEY_F3, KEY_1, KEY_W, KEY_E, KEY_F,
		KEY_B, KEY_N, KEY_K, KEY_LEFT_BRACE, KEY_RIGHT_BRACE },
	{ KEY_F4, KEY_2, KEY_3, KEY_R, KEY_G,
		KEY_H, KEY_J, KEY_P, KEY_EQUAL, KEY_BACKSPACE },
	{ KEY_F5, KEY_4, KEY_5, KEY_T, KEY_Y,
		KEY_U, KEY_I, KEY_O, KEY_MINUS, KEY_F11 },
	{ KEY_F6, KEY_F7, KEY_6, KEY_7, KEY_F8,
		KEY_8, KEY_9, KEY_F9, KEY_0, KEY_F10 },
	{ KEY_F1, KEY_F2, KEYPAD_MINUS, KEYPAD_PLUS, KEYPAD_ENTER,
		KEYPAD_SLASH, KEYPAD_8, KEYPAD_5, KEYPAD_2, KEYPAD_0 },
	{ KEYPAD_ASTERIX, KEYPAD_9, KEYPAD_6, KEYPAD_3, KEYPAD_PERIOD,
		KEY_ESC, KEY_NUM_LOCK, KEYPAD_7, KEYPAD_4, KEYPAD_1}
};

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
int held_F12 = 0;

//checks if a button on a given pin has been pressed or released
#define PRESSED 2
#define RELEASED 1
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
	pinMode(PIN_F12, INPUT_PULLUP);
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
		delayMicroseconds(200);
	
		//check each row in the column for key presses
		for (int row = 0; row < 10; ++row) {
			checkKey(row, col);
		}

		//manually check F12 as it is always grounded
		int status = checkPin(PIN_F12, &held_F12);
		if (status == PRESSED) {
			usb_keyboard_press_keycode(KEY_F12);
		} else if (status == RELEASED) {
			usb_keyboard_release_keycode(KEY_F12);
		}
		col = (col+1)%10;
	}
}
