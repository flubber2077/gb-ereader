#include <gb/gb.h>
#include "constants.h"
#include <stdbool.h>
#include <gbdk/font.h>
#include "content/font.tileset.h"
#include "screeneffects.h"
#include "bookdata/metadata.h"

uint8_t xPlace = 1, yPlace = 1;

uint8_t letter = 'A';

inline void readerInit(void)
{
    // Window setup
    SHOW_WIN;
    set_win_tiles(0,0,sizeof(title),1,title);
    move_win(30,136);

    // Background setup
    move_bkg(0, 0);
    init_bkg(0);

    // Tile setup
    set_tile_data('A', 48, FONT_TILESET, 0x90);
    set_tile_data('a', 48, FONT_TILESET, 0x90); // remove once alphabet is long enough
    fadein();
}

inline void textPosition(void)
{
    xPlace++;
    if (xPlace == 19)
    {
        yPlace++;
        xPlace = 1;
    }
    if (yPlace == 16)
    {
        yPlace = 1;
    }
}

void reader(void)
{
    readerInit();

    while (1)
    {
        // non-display logic here
        vsync(); // wait for PPU VRAM to be fully available
        // only VRAM and Map data here.
        set_bkg_tile_xy(xPlace, yPlace, letter++);
        textPosition();
    }
}
