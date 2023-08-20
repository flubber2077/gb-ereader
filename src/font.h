#include <gb/gb.h>
#include "content/font.tileset.h"

const void fontInit(void) {
  set_tile_data(' ', 1, space, 0x90);
  set_tile_data('A', 48, FONT_TILESET, 0x90);
  // TODO: remove once alphabet is long enough
  set_tile_data('a', 48, FONT_TILESET, 0x90);
  // numbers
  // extraneous characters
}