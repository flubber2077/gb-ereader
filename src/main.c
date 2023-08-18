#include <gb/gb.h>
#include <stdint.h>
#include "screeneffects.h"
#include "splashscreen.c"
#include "content/content.c"
#include "sgb/sgb.c"
#include "constants.h"
#include "reader.c"
#include "browser.c"

// put into struct;
uint8_t state;

void init(void)
{
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;
    fadeout();
    // setSgbBorder();
    NR52_REG = 0x00u; // kill sound, save battery
}

void main(void)
{
    init();
    state = SPLASHSCREEN;

    // gameloop:
    while (1)
    {
        switch (state)
        {

        case SPLASHSCREEN:
            splashscreen();
            state = BROWSER;
            break;

        case BROWSER:
            state = browser();
            break;

        case READER:
            reader();
            break;
        }

        // case SETTINGS:
        //    only to be implemented if save data is implemented

        // case ABOUT:
        //     could be nice, would need to get browser in a good state first
    }
}
