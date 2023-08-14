#include <gb/gb.h>
#include <stdbool.h>
#include "content/splashData.c"

void delayFrame(uint8_t frames){
    for(uint8_t i = 0; i < frames; i++){
        vsync();
    }
}

void fadeout()
{
    BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_BLACK, DMG_BLACK);
    delayFrame(4);
    BGP_REG = DMG_PALETTE(DMG_DARK_GRAY, DMG_BLACK, DMG_BLACK, DMG_BLACK);
    delayFrame(4);
    BGP_REG = DMG_PALETTE(DMG_BLACK, DMG_BLACK, DMG_BLACK, DMG_BLACK);
}

void fadein()
{
    BGP_REG = DMG_PALETTE(DMG_DARK_GRAY, DMG_BLACK, DMG_BLACK, DMG_BLACK);
    delayFrame(4);
    BGP_REG = DMG_PALETTE(DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK, DMG_BLACK);
    delayFrame(4);
    BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
}


inline void splashscreen()
{
    HIDE_WIN;
    move_bkg(0, 0);
    set_bkg_data(0u, 114u, mario_data);
    set_bkg_tiles(0, 0, SCREENWIDTH / 8, SCREENHEIGHT / 8, mario_map);
    fadein();
    bool wait = true;
    while (wait)
    {
        vsync();
        switch (joypad())
        {
        case J_A:
            wait = false;
            break;
        }
    };
    fadeout();
}

