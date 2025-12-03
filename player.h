#ifndef PLAYER_H
    #define PLAYER_H
    typedef struct {
        int position_x;
        int position_y;
        int health;
        char symbol;
    } Player;
    #define PLAYER_SYMBOL '@' // Começa com '@' e depois vira uma seta ascii, para onde ele olha
    #define WALKABLE_CHAR ' '

    extern Player* player;

    void load_player();
    void print_player(Player* player);
    void move_player(Player* player, char move_input);
    bool has_collision(Player* player, int delta_x, int delta_y);
    void spawn_player(Player* player);
#endif