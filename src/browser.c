#include <gb/gb.h>
#include <stdio.h>
#include <gbdk/font.h>
#include "constants.c"

typedef struct {
    uint8_t place;
    uint8_t cursorX;
} BrowserVar;

void initbrowser()
{
    HIDE_WIN;
    vsync();
    font_init();
    font_t font = font_load(font_ibm);
    font_set(font);
    move_bkg(0, 0);
}

uint8_t browser()
{
    static BrowserVar browserVar = {0,0,0};
    initbrowser();
    printf("file browser go here");
    while (1)
    {
        switch (joypad())
        {
        case (J_A):
            return READER;
            break;
        case (J_B):
            return SPLASHSCREEN;
            break;
        }
        vsync();
    }
}