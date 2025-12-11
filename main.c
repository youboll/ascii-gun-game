#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "keyboard.h"
#include "graphics.h"
#include "player.h"
#include "monsters.h"
#include "colors.h"

void paint_screen_tick() {
    printf("\x1b[H");
    clear_screen();
    health_bar(player);
    printf("\x1b[2;1H");
    print_graphics();
    print_player(player);
    for (int x = 0; x < monster_length; x++) {
        print_player(monsters[x]);
    }
    print_bullets();
    fflush(stdout);
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
    int frame_count = 0;
    int monster_move_interval = 5;
    int bullet_move_interval = 2;
    while (1) {

        if (player -> health <= 0) {
            printf("\x1b[H");
            clear_screen();
            printf(COLOR_RED "\n\n    GAME OVER!\n" COLOR_RESET);
            printf("    Voce foi derrotado!\n\n");
            return 0;
        }
        if (kbhit()) {
            char key_value = (char) read_key();

            if (key_value == 'q') {return 0;}

            move_player(player, key_value);
            paint_screen_tick();

        }

        if (frame_count % monster_move_interval == 0) {
            move_monsters();
            paint_screen_tick();
        }
        if (frame_count % bullet_move_interval == 0) {
            move_bullets();
            paint_screen_tick();
        }

        monster_count++;
        bullet_count++;
        frame_count++;
        if (frame_count > 1000) frame_count = 0;

        #ifdef _WIN32
            Sleep(33);// Windows - 66 ms
        #else
            usleep(33333); // Linux - 66.666 ms
        #endif

    }
}