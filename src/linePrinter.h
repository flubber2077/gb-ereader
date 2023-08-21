#pragma once
#include <gb/gb.h>

#include "constants.h"

// prints chars to background from FILE on line Y
uint8_t printLine(const unsigned char file[], uint8_t* y,
                  uint16_t* readerPlace) {
  static uint8_t tileX;
  tileX = 0;
  while (1) {
    // check for control chars
    if (file[*readerPlace] < ' ') {
      while (tileX < RIGHTBORDER) {
        set_bkg_tile_xy(tileX++, *y, ' ');
      }
      uint8_t controlChar = *readerPlace;
      (*readerPlace)++;
      return controlChar;
    } else {
      set_bkg_tile_xy(tileX++ + LEFTBORDER, *y, file[(*readerPlace)++]);
    }
  }
}

// Chunk is a group of lines the screen advances with
uint8_t printChunk(const unsigned char file[], uint8_t y,
                   uint16_t* readerPlace) {
  uint8_t lineY = y;
  uint8_t printLineReturn = 0;
  while (lineY < y + CHUNKSIZE) {
    printLineReturn = printLine(file, &lineY, readerPlace);
    switch (printLineReturn) {
      case (ENDOFTEXT):
        return ENDOFTEXT;
        break;
    }
    lineY++;
  }

  return printLineReturn;
}