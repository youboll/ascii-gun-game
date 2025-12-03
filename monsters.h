#ifndef MONSTERS_H
    #define MONSTERS_H

    #include "player.h"
    #define MONSTER_SYMBOL 'M'
    #define MAX_MONSTERS 50

    extern Player** monsters;
    extern int monster_length;

    void load_monsters();
    void print_monsters();
    void move_monsters();
#endif