#include <stdint.h>

// game states
#define SPLASHSCREEN 0
#define READER 1
#define BROWSER 2
#define ABOUT 3
#define SETTINGS 4

// screen macros
#define LEFTBORDER 0
#define RIGHTBORDER 20
#define BOTTOMBORDER 17
#define TOPBORDER 1
#define TEXTWINDOWHEIGHT (BOTTOMBORDER - TOPBORDER)

// text macros
#define NEWLINE ((uint8_t)'\x01')    // \n
#define PAGEBREAK ((uint8_t)'\f')  // \f Formfeed
#define ENDOFTEXT (uint8_t)12

// printer macros
#define CHUNKSIZE 8
#define CHUNKPERWINDOW (TEXTWINDOWHEIGHT / CHUNKSIZE)

uint8_t i;  // for any local counters