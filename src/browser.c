#include <gb/gb.h>
#include <stdio.h>
#include <gbdk/font.h>
#include "constants.c"
#include "content/pointer.c"
#include "content/metadata.c"

typedef struct
{
    uint8_t place;
    uint8_t cursorY;
    uint8_t cursorBlink;
} BrowserVar;

void initbrowser()
{
    SHOW_WIN;
    move_win(7, 130);
    vsync();
    set_sprite_data(1, 2, pointer);
    set_sprite_tile(0, 1);
    move_sprite(0, 16, 24);
    SHOW_SPRITES;
    font_init();
    font_t font = font_load(font_ibm);
    font_set(font);
    move_bkg(0, 0);
    fadein();
}

uint8_t browser(void)
{
    static BrowserVar browserVar = {0, 0, 0};
    initbrowser();
    printf("file browser go here more text momre text more text more text");
    printf("why isn't this working");
    while (1)
    {
        browserVar.cursorBlink++;
        set_sprite_tile(0, (browserVar.cursorBlink & (uint8_t)0x8) ? 2 : 1);
        switch (joypad())
        {
        case (J_DOWN):
            browserVar.cursorBlink = 0;
            if (browserVar.cursorY == maxChapter)
            {
                break;
            }
            if (browserVar.cursorY % 16 == 15) // && not at end of files
            {
                // load & display new set of chapters or books.
                move_sprite(0, 16, 24);
            }
            else
            {
                scroll_sprite(0, 0, 8);
            }
            browserVar.cursorY++;
            break;
        case (J_UP):
            browserVar.cursorBlink = 0;
            if (browserVar.cursorY == 0)
            {
                break;
            }
            else if (browserVar.cursorY % 16 == 0)
            {
                // load & display new set of chapters or books.
                move_sprite(0, 16, 144);
            }
            else
            {
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
        for (i = 0; i < 5; i++)
        {
            vsync();
        }
    }
}