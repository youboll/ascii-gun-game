#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keyboard.h"
#include "graphics.h"
#include "player.h"
#include "monsters.h"

void paint_screen_tick() {
    printf("\x1b[H");
    clear_screen();
    print_graphics();
    print_player(player);
    print_monsters();
    print_bullets();
}

int main () {
    hide_cursor();
    setup_graphics(); // Aloca os gráficos
    load_graphics();
    print_graphics();
    load_player();
    load_monsters();
    load_bullets();
    print_monsters();
    spawn_player(player);
    paint_screen_tick();

    int monster_count = 0;
    int bullet_count = 0;
    while (1) {
        if (kbhit()) {
            char key_value = (char) read_key();

            if (key_value == 'q') {return 0;}

            move_player(player, key_value);
            paint_screen_tick();

        }

        if (monster_count >= 7200) {
            monster_count = 0;
            move_monsters();
            paint_screen_tick();
        }
        if (bullet_count >= 1800) {
            bullet_count = 0;
            move_bullets();
            paint_screen_tick();
        }

        monster_count++;
        bullet_count++;
        sleep(1/15);  // Limite de 15 FPS
    }
}