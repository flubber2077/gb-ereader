#include <gb/gb.h>

#include "bookdata/metadata.h"
#include "constants.h"
#include "content/font.tileset.c"
#include "content/pointer.c"
#include "screeneffects.h"

typedef struct {
  uint8_t place;
  uint8_t cursorY;
  uint8_t cursorBlink;
} BrowserVar;

inline void initbrowser(void) {
  SHOW_WIN;
  move_win(7, 136);
  vsync();
  set_sprite_data(1, 2, pointer);
  set_sprite_tile(0, 1);
  move_sprite(0, 16, 24);
  init_bkg(0);
  set_tile_data(66, 48, FONT_TILESET, 0x90);
  SHOW_SPRITES;
  move_bkg(0, 0);
  fadein();
}

inline uint8_t browser(void) {
  static BrowserVar browserVar = {0, 0, 0};
  initbrowser();

  while (1) {
    browserVar.cursorBlink++;
    set_sprite_tile(0, (browserVar.cursorBlink & (uint8_t)0x8) ? 2 : 1);
    switch (joypad()) {
      case (J_DOWN):
        browserVar.cursorBlink = 0;
        if (browserVar.cursorY == maxChapter) {
          break;
        }
        if (browserVar.cursorY % 16 == 15)  // && not at end of files
        {
          // load & display new set of chapters or books.
          move_sprite(0, 16, 24);
        } else {
          scroll_sprite(0, 0, 8);
        }
        browserVar.cursorY++;
        break;
      case (J_UP):
        browserVar.cursorBlink = 0;
        if (browserVar.cursorY == 0) {
          break;
        } else if (browserVar.cursorY % 16 == 0) {
          // load & display new set of chapters or books.
          move_sprite(0, 16, 144);
        } else {
          scroll_sprite(0, 0, -8);
        }
        browserVar.cursorY--;
        break;
      case (J_A):
        return READER;
        break;
      case (J_B):
        return SPLASHSCREEN;
        break;
    }
    for (i = 0; i < 5; i++) {
      vsync();
    }
  }
}