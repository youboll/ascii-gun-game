#ifndef PLAYER_H
    #define PLAYER_H
    typedef struct {
        int position_x;
        int position_y;
        int health;
    } Player;
    #define PLAYER_SYMBOL '@'
    #define WALKABLE_CHAR ' '

    Player* init_player();
    void print_player(Player* player);
    void move_player(Player* player, char move_input);
    bool has_collision(Player* player, int delta_x, int delta_y);
#endif