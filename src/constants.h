#include <gb/gb.h>

// possible states
#define SPLASHSCREEN 0
#define READER 1
#define BROWSER 2

// screen macros
#define TILEHEIGHT 32
#define TILEWIDTH 32
#define BORDER 2
#define LEFTSCREEN0 BORDER
#define LEFTSCREEN1 (TILEWIDTH / 2) + BORDER
#define RIGHTSCREEN0 (TILEWIDTH / 2) - BORDER
#define RIGHTSCREEN1 TILEWIDTH - BORDER
#define TOPSCREEN 0
#define BOTTOMSCREEN TILEHEIGHT - 1

uint8_t i; // for any local counters