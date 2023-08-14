#include <gb/gb.h>
#include "constants.c"
#include <stdbool.h>
#include <gbdk/font.h>

// rewrite to use modulo to divide screen, so that program understands page as linear

uint8_t xPlace = LEFTSCREEN0, yPlace = 0;
bool screen = 0;

uint8_t letter = 66;

inline void readerInit()
{
    font_init();
    font_t font = font_load(font_ibm);
    font_set(font);
    move_bkg((uint8_t)-16, 0);
    window_init();
    fadein();
}

inline void textPosition()
{
    xPlace++;
    if (xPlace == (screen ? RIGHTSCREEN1 : RIGHTSCREEN0))
    {
        yPlace++;
        xPlace = (screen ? LEFTSCREEN1 : LEFTSCREEN0);
    }
}

void reader()
{
    readerInit();

    while (1)
    {
        // non-display logic here
        vsync(); // wait for PPU VRAM to be fully available
        // only VRAM and Map data here.
        set_bkg_tiles(xPlace, yPlace, 1, 1, letter);
        textPosition();
        if (yPlace == BOTTOMSCREEN)
        {
            yPlace = TOPSCREEN;
            screen = !screen;
            if (screen)
            {
                move_bkg((uint8_t)112, 0);
            }
            else
            {
                letter = 'h';
                move_bkg((uint8_t)-16, 0);
            }
            xPlace = screen ? LEFTSCREEN1 : LEFTSCREEN0;
        }
    }
}
