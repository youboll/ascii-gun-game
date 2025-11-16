#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keyboard.h"
#include "graphics.h"
#include "player.h"

Player *player;

void paint_screen_tick() {
    clear_screen();
    setup_graphics();
    print_player(player);
}

int main () {
    hide_cursor();
    player = init_player();
    paint_screen_tick();
    while (1) {
        if (kbhit()) {
            char key_value = (char) read_key();

            if (key_value == 'q') {return 0;}

            move_player(player, key_value);
            paint_screen_tick();
        }
    }
}