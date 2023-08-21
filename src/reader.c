#include <gb/gb.h>

#include "bookdata/metadata.h"
#include "constants.h"
#include "font.h"
#include "linePrinter.h"
#include "screeneffects.h"

// Reader program.

inline void readerInit(void) {
  // Sprite setup
  HIDE_SPRITES;

  // Background setup
  move_bkg(0, 0);
  init_bkg(0);

  // Tile setup
  fontInit();

  // Window setup
  SHOW_WIN;
  set_win_tiles(0, 0, sizeof(title), 1, title);
  move_win(7, 136);

  fadein();
}

inline uint8_t initialChunks(const unsigned char file[], uint16_t* readerPlace,
                          uint16_t* lastReaderPlace) {
  printChunk(file, TOPBORDER, readerPlace);
  *lastReaderPlace = *readerPlace;
  return printChunk(file, TOPBORDER + CHUNKSIZE, readerPlace);
}

inline uint8_t advanceChunks(const unsigned char file[], uint16_t* readerPlace,
                          uint16_t* lastReaderPlace) {
  printChunk(file, TOPBORDER, lastReaderPlace);
  return printChunk(file, TOPBORDER + CHUNKSIZE, readerPlace);
}

inline uint8_t reader(const unsigned char file[]) {
  readerInit();
  static uint8_t endOfFile = 0;
  static uint16_t readerPlace, lastReaderPlace;
  readerPlace = 0, lastReaderPlace = 0;
  initialChunks(file, &readerPlace, &lastReaderPlace);
  while (!endOfFile) {
    delayFrame(5);
    switch (joypad()) {
      case (J_A):
        const uint8_t controlChar = advanceChunks(formatted, &readerPlace, &lastReaderPlace);
        if(controlChar == ENDOFTEXT){
          endOfFile = 1;
        }
        break;
      case (J_B):
        return BROWSER;
        break;
    }
  }
  while(1){
    switch(joypad()) {
      case(J_B):
      return BROWSER;
      break;
    }

  }
}
