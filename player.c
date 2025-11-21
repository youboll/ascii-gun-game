#include <stdlib.h>
#include "player.h"

#include <stdio.h>

#include "graphics.h"

Player* init_player () {
    Player *new_player = malloc(sizeof(Player));
    new_player -> position_x = 0;
    new_player -> position_y = 1;
    new_player -> health = 100;
    return new_player;
}

void print_player (Player *player) {
    printf("\x1b[%d;%dH", player->position_y+1, player->position_x+1);
    putchar(PLAYER_SYMBOL);
    puts("\x1b[0m");
}

void move_player(Player *player, char move_input) {
    int delta_x = 0;
    int delta_y = 0;

    switch (move_input) {
        case 'w':
            delta_y = -1;
            break;
        case 's':
            delta_y = 1;
            break;
        case 'a':
            delta_x = -1;
            break;
        case 'd':
            delta_x = 1;
            break;
        default:
            break;
    }
    if (has_collision(player, delta_x, delta_y)) {
        return;
    }
    player -> position_x += delta_x;
    player -> position_y += delta_y;
}

bool has_collision(Player *player, int delta_x, int delta_y) {
    int new_pos_x = player -> position_x + delta_x;
    int new_pos_y = player -> position_y + delta_y;
    if (new_pos_x < 0 || new_pos_y < 0) {
        return true;
    }
    if (graphics[new_pos_y][new_pos_x] != WALKABLE_CHAR) {
        return true;
    }
    return false;
}

void spawn_player(Player *player) {
    int player_pos_x = 0;
    int player_pos_y = 0;

    for (int x=0; x<GRAPHICS_HEIGHT; x++) {
        bool found = false;
        for (int y=0; y<GRAPHICS_WIDTH; y++) {
            if (graphics[x][y] == PLAYER_SYMBOL) {
                player_pos_x = x;
                player_pos_y = y;
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    player -> position_y = player_pos_x;
    player -> position_x = player_pos_y; // Foi mal, tá invertido hehehehehe
    graphics[player_pos_x][player_pos_y] = WALKABLE_CHAR;
}