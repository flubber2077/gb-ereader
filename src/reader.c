#include <gb/gb.h>

#include "bookdata/metadata.h"
#include "constants.h"
#include "content/content.c"
#include "linePrinter.h"
#include "screeneffects.h"
#include "font.h"

static uint8_t yPlace = 1;

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

inline void reader(void) {
  readerInit();
  static uint16_t x = 0;

  while (1) {
    // non-display logic here
    delayFrame(5);  // wait for PPU VRAM to be fully available
    // only VRAM and Map data here.
    if (joypad() == J_A) {
      x += printLine(&formatted[x], &yPlace);
      yPlace++;
    }
  }
}
