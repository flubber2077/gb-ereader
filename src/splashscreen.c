#include <gb/gb.h>
#include <stdbool.h>

#include "constants.h"
#include "content/splashData.c"
#include "screeneffects.h"

inline void initSplashSCreen(void) {
  HIDE_WIN;
  move_bkg(0, 0);
  set_bkg_data(0u, 114u, mario_data);
  set_bkg_tiles(0, 0, SCREENWIDTH / 8, SCREENHEIGHT / 8, mario_map);
  fadein();
  bool wait = true;
}

inline void splashscreen(void) {
  HIDE_WIN;
  move_bkg(0, 0);
  set_bkg_data(0u, 114u, mario_data);
  set_bkg_tiles(0, 0, SCREENWIDTH / 8, SCREENHEIGHT / 8, mario_map);
  fadein();
  bool wait = true;
  while (wait) {
    vsync();
    switch (joypad()) {
      case J_A:
        wait = false;
        break;
    }
  };
  fadeout();
}
