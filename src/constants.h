#include <gb/gb.h>

// possible states
#define SPLASHSCREEN 0
#define READER 1
#define BROWSER 2

// screen macros
#define TILEHEIGHT 32
#define TILEWIDTH 32
#define LEFTBORDER 0
#define RIGHTBORDER 20
#define TOPSCREEN 1

// text macros
#define NEWLINE ((uint8_t)10)    // \n
#define PAGEBREAK ((uint8_t)12)  // \f Formfeed

uint8_t i;  // for any local counters