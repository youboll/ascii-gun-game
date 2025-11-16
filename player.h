#ifndef PLAYER_H
    #define PLAYER_H
    typedef struct {
        int position_x;
        int position_y;
        int health;
    } Player;
    #define PLAYER_SYMBOL '@'

    Player* init_player();
    void print_player(Player* player);
    void move_player(Player* player, char move_input);
#endif