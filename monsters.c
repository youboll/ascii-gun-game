#include <stdlib.h>
#include <stdio.h>
#include "monsters.h"

#include <time.h>
#include <unistd.h>

#include "player.h"
#include "graphics.h"

Player **monsters;
int monster_length = 0;
int last_tick = -1;


// Que ironia, o player também é um monstro...
int get_player_x(Player* player, Player* monster) {
    return player -> position_x - monster -> position_x;
}

int get_player_y(Player* player, Player* monster) {
    return player -> position_y - monster -> position_y;
}

void load_monsters() {
    monsters = malloc(sizeof(Player*) * MAX_MONSTERS);
    int last_index = 0;

    for (int y=0; y<GRAPHICS_HEIGHT; y++) {
        for (int x=0; x<GRAPHICS_WIDTH; x++) {
            if (graphics[y][x] == MONSTER_SYMBOL) {
                Player *monster = malloc(sizeof(Player));
                monster -> symbol = MONSTER_SYMBOL;
                monster -> position_x = x;
                monster -> position_y = y;
                monster -> health = 100;
                monsters[last_index] = monster;
                last_index++;

                graphics[y][x] = WALKABLE_CHAR;
            }
        }
    }
    monster_length = last_index;
}

void move_monsters() {
    for (int x=0; x<monster_length; x++) {
        Player *monster = monsters[x];
        int move_x = 0;
        int move_y = 0;
        if (player -> position_x > monster -> position_x) {
            move_x = 1;
        } else if (player -> position_x > monster -> position_x) {
            move_x = 0;
        } else {
            move_x = -1;
        }

        if (!has_collision(monster, move_x, 0)) {
            monster -> position_x += move_x;
        }

        if (player -> position_y > monster -> position_y) {
            move_y = 1;
        } else if (player -> position_y == monster -> position_y) {
            move_y = 0;
        } else {
            move_y = -1;
        }

        if (!has_collision(monster, 0, move_y)) {
            monster -> position_y += move_y;
        }
    }
}

void print_monsters() {
    for (int x=0; x<monster_length; x++) {
        print_player(monsters[x]);
    }
}