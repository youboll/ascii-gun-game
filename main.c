#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keyboard.h"
#include "graphics.h"
#include "player.h"

Player *player;


void paint_screen_tick() {
    printf("\x1b[H");
    clear_screen();
    print_graphics();
    print_player(player);
}

int main () {
    hide_cursor();
    setup_graphics(); // Aloca os gráficos
    load_graphics();
    print_graphics();
    player = init_player();
    spawn_player(player);
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