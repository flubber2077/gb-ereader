#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include <gb/sgb.h>

inline void setSgbBorder() {
    // Wait 4 frames
    // For PAL SNES this delay is required on startup
    for (uint8_t i = 5; i != 0; i--) vsync();
    if(sgb_check()){
        printf("sgb found");
        for (uint8_t i = 30; i != 0; i--) vsync();
    }
}