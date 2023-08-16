#include <gb/gb.h>

const unsigned char window[] = "hello";

inline void window_init(void){
    SHOW_WIN;

    set_win_tiles(0,0,8,1,window);
    move_win(7,136);
}