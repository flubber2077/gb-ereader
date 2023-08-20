#pragma once
#include <gb/gb.h>

#include "screeneffects.h"

void delayFrame(uint8_t frames) {
  for (uint8_t i = 0; i < frames; i++) {
    vsync();
  }
}

void fadeout(void) {
  BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_WHITE, DMG_DARK_GRAY, DMG_BLACK);
  delayFrame(4);
  BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_WHITE, DMG_WHITE, DMG_BLACK);
  delayFrame(4);
  BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_WHITE, DMG_WHITE, DMG_WHITE);
}

void fadein(void) {
  BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_WHITE, DMG_WHITE, DMG_BLACK);
  delayFrame(4);
  BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_WHITE, DMG_DARK_GRAY, DMG_BLACK);
  delayFrame(4);
  BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
}
