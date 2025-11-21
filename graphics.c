#include <stdio.h>
#include <string.h>
#include "graphics.h"
#include <stdlib.h>

/*
 * Gestor de gráficos em ASCII
 * Como funciona?
 *
 * Temos uma matriz base, nela temos a cena que queremos imprimir
 * O algoritmo colisão é implementado em player.h e usa a matriz graphics como base
 *
 *
 */

char GRAPHICAL_GRID;
char GRAPHICAL_COMPONENTS;
char **graphics;
int current_level = 1;

void setup_graphics() {
    graphics = malloc(GRAPHICS_HEIGHT * sizeof(char*));

    for (int i = 0; i < GRAPHICS_HEIGHT; i++) {
        graphics[i] = malloc(GRAPHICS_WIDTH * sizeof(char));
        graphics[i][0] = '\0'; // deixa vazio
    }
}


void print_graphics() {
    for (int x = 0; x < GRAPHICS_HEIGHT; x++) {
        fputs(graphics[x], stdout);
    }
}


void clear_screen() {
    #if IS_WINDOWS
        system("cls");
    #else
        system("clear");
    #endif
}

void hide_cursor() {
    puts("\x1b[?25l");
}

FILE* load_graphics_file(int file_index) {
    FILE *graphics_file;
    char *filename[256];
    sprintf((char *)filename, "levels/level%d.txt", file_index);
    graphics_file = fopen((char *)filename, "r");

    return graphics_file;
}

void load_graphics() {
    FILE *current_graphics_file = load_graphics_file(current_level);
    for (int x=0;x<GRAPHICS_HEIGHT;x++) {
        fgets(graphics[x], GRAPHICS_WIDTH, current_graphics_file);
    }
    fclose(current_graphics_file);
}

