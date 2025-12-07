#include <stdbool.h>
#ifndef PLAYER_H
    #define PLAYER_H
    typedef struct {
        int position_x;
        int position_y;
        int health;
        char symbol;
    } Player;
    typedef struct {
        int position_x;
        int position_y;
        int health;
        char symbol;

        int direction_x;
        int direction_y;
    } Bullet;

    #define PLAYER_SYMBOL '@' // Começa com '@' e depois vira uma seta ascii, para onde ele olha
    #define BULLET_SYMBOL '*'
    #define MONSTER_SYMBOL 'M'
    #define WALKABLE_CHAR ' '
    #define MAX_BULLETS 512 // Caso passar disso, vamos precisar de uma pilha

    extern Player* player;
    extern Bullet** bullets;

    void load_player();
    void print_player(Player* player);
    void move_player(Player* player, char move_input);
    bool has_collision(Player* player, int delta_x, int delta_y);
    void spawn_player(Player* player);
    void load_bullets();
    void shot_bullet();
    void print_bullets();
    void move_bullets();
#endif