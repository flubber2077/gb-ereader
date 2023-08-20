#pragma once
#include <gb/gb.h>

#include "constants.h"

uint8_t printBlankLine(uint8_t* y) {
  for (int x = 0; x <= 20; x++) {
    set_bkg_tile_xy(x, *y, ' ');
  }
}

// prints chars to background from FILE on line Y
uint8_t printLine(const unsigned char file[], uint8_t* y) {
  static uint8_t x;
  x = 0;
  while (1) {
    switch (file[x]) {
      // check for control chars
      case NEWLINE:
        uint8_t charX = x + 1;
        while (x < RIGHTBORDER) {
          set_bkg_tile_xy(x++, *y, ' ');
        }
				return charX;
        break;
      case PAGEBREAK:
        return -PAGEBREAK;
        break;

      // include any other control characters here
      default:
        set_bkg_tile_xy((x++) + LEFTBORDER, *y, file[x]);
    }
  }
}

// Chunk is a group of lines the screen advances with
uint16_t printChunk(const unsigned char file[], uint8_t* y) {
  static uint16_t x;
  x = 0;
}