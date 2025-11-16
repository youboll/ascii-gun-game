#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keyboard.h"
#include "graphics.h"
#include "player.h"

Player *player;

void draw_map() {
    strcpy(graphics[0], "-------------------------\n\0");
    strcpy(graphics[1], "                         \n\0");
    strcpy(graphics[2], "-----------   -----------\n\0");
    strcpy(graphics[3], "                         \n\0");
    strcpy(graphics[4], "                         \n\0");
    strcpy(graphics[5], "--- ---------------- ----\n\0");
    strcpy(graphics[6], "                         \n\0");
    strcpy(graphics[7], "                         \n\0");
    strcpy(graphics[8], "-------------------------\n\0");
}

void paint_screen_tick() {
    printf("\x1b[H");
    clear_screen();
    print_graphics();
    print_player(player);
}

int main () {
    hide_cursor();
    setup_graphics(); // Aloca os gráficos
    draw_map();
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