#include <stdlib.h>
#include "player.h"

#include <stdio.h>

Player* init_player () {
    Player *new_player = malloc(sizeof(Player));
    new_player -> position_x = 5;
    new_player -> position_y = 5;
    new_player -> health = 100;
    return new_player;
}

void print_player (Player *player) {
    printf("\x1b[%d;%dH", player->position_y, player->position_x);
    putchar(PLAYER_SYMBOL);
    puts("\x1b[0m\n");
}

void move_player(Player *player, char move_input) {
    switch (move_input) {
        case 'w':
            player -> position_y -= 1;
            break;
        case 's':
            player -> position_y += 1;
            break;
        case 'a':
            player -> position_x -= 1;
            break;
        case 'd':
            player -> position_x += 1;
            break;
        default:
            break;
    }
}
