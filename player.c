#include <stdlib.h>
#include "player.h"

#include <stdio.h>

#include "graphics.h"
#include "monsters.h"
#include "keyboard.h"


Player *player;
Bullet **bullets;
int bullets_shot = 0;

void load_player () {
    player = malloc(sizeof(Player));
    player -> position_x = 0;
    player -> position_y = 1;
    player -> health = 100;
    player -> symbol = PLAYER_SYMBOL;
}

void load_bullets() {
    bullets = malloc(sizeof(Bullet *) * MAX_BULLETS);
}

void shot_bullet() {
    Bullet *bullet = malloc(sizeof(Bullet));
    bullet -> position_x = player -> position_x;
    bullet -> position_y = player -> position_y;
    bullet -> symbol = BULLET_SYMBOL;
    bullet -> health = 100;

    if (player -> symbol == '^') {
        bullet -> direction_y = -1;
    } else if (player -> symbol == 'v') {
        bullet -> direction_y = 1;
    } else if (player -> symbol == '>') {
        bullet -> direction_x = 1;
    }else if (player -> symbol == '<') {
        bullet -> direction_x = -1;
    }
    bullets[bullets_shot] = bullet;
    bullets_shot++;
}

void print_bullets() {
    for (int x=0; x<bullets_shot; x++) {
        Bullet *bullet = bullets[x];
        if (bullet -> health == 0) continue;
        printf("\x1b[%d;%dH", bullet->position_y+1, bullet->position_x+1);
        putchar(bullet -> symbol);
        puts("\x1b[0m");
    }
}

void check_monsters_hit() {
    for (int x=0; x<bullets_shot; x++) {
        for (int y=0; y<monster_length; y++) {
            Bullet *bullet = bullets[x];
            Player *monster = monsters[y];

            if (bullet -> position_x == monster->position_x && bullet -> position_y == monster->position_y) {
                monster -> health = 0;
            }
        }
    }
}

void move_bullets() {
    for (int x=0; x<bullets_shot; x++) {
        Bullet *bullet = bullets[x];
        int delta_x = bullet ->direction_x;
        int delta_y = bullet ->direction_y;

        if (!has_collision((Player *) bullet, delta_x, delta_y)) {
            bullet -> position_x += delta_x;
            bullet -> position_y += delta_y;;
        } else {
            bullet -> health = 0;
        }
    }
    check_monsters_hit();
}

void print_player (Player *player) {
    if (player -> health == 0) return;
    printf("\x1b[%d;%dH", player->position_y+1, player->position_x+1);
    putchar(player -> symbol);
    puts("\x1b[0m");
}

void move_player(Player *player, char move_input) {
    int delta_x = 0;
    int delta_y = 0;

    switch (move_input) {
        case 'w':
            delta_y = -1;
            player -> symbol = '^';
            break;
        case 's':
            delta_y = 1;
            player -> symbol = 'v';
            break;
        case 'a':
            delta_x = -1;
            player -> symbol = '<';
            break;
        case 'd':
            delta_x = 1;
            player -> symbol = '>';
            break;
        case (char) 1006:
            shot_bullet();
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
    if (new_pos_x >= GRAPHICS_WIDTH || new_pos_y >= GRAPHICS_HEIGHT) {
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