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

inline void initialChunks(const unsigned char file[], uint16_t* readerPlace,
                          uint16_t* lastReaderPlace) {
  printChunk(file, TOPBORDER, readerPlace);
  *lastReaderPlace = *readerPlace;
  printChunk(file, TOPBORDER + CHUNKSIZE, readerPlace);
}

inline void advanceChunks(const unsigned char file[], uint16_t* readerPlace,
                          uint16_t* lastReaderPlace) {
  printChunk(file, TOPBORDER, lastReaderPlace);
  printChunk(file, TOPBORDER + CHUNKSIZE, lastReaderPlace);
}

inline uint8_t reader(const unsigned char file[]) {
  readerInit();
  static uint16_t readerPlace, lastReaderPlace;
  readerPlace = 0, lastReaderPlace = 0;
  initialChunks(file, &readerPlace, &lastReaderPlace);
  while (1) {
    delayFrame(5);
    switch (joypad()) {
      case (J_A):
        advanceChunks(formatted, &readerPlace, &lastReaderPlace);
        break;
      case (J_B):
        return BROWSER;
        break;
    }
  }
}
