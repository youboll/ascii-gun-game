#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keyboard.h"
#include "graphics.h"
#include "player.h"
#include "monsters.h"

Player *player;


void paint_screen_tick() {
    printf("\x1b[H");
    clear_screen();
    print_graphics();
    print_player(player);
    print_monsters();
}

int main () {
    hide_cursor();
    setup_graphics(); // Aloca os gráficos
    load_graphics();
    print_graphics();
    load_player();
    load_monsters();
    print_monsters();
    spawn_player(player);
    paint_screen_tick();

    int frame_count = 0;
    while (1) {
        if (kbhit()) {
            char key_value = (char) read_key();

            if (key_value == 'q') {return 0;}

            move_player(player, key_value);
            paint_screen_tick();

        }

        if (frame_count >= 7200) {
            frame_count = 0;
            move_monsters();
            paint_screen_tick();
        }

        frame_count++;
        sleep(1/15);  // Limite de 15 FPS
    }
}