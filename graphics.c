#include <stdio.h>
#include <string.h>
#include "graphics.h"
#include <stdlib.h>

/*
 * Gestor de gráficos em ASCII
 * Como funciona?
 *
 * Temos uma matriz base, nela temos a cena que queremos imprimir
 * Também temos a lista de matrizes chamada de components, ela representa os componentes que vamos imprimir em cima da tela
 *
 *
 */

char GRAPHICAL_GRID;
char GRAPHICAL_COMPONENTS;

void setup_graphics() {
    puts("--------------------");
    puts("                    ");
    puts("                    ");
    puts("--------------------");
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