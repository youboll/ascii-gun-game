#include <stdio.h>
#include "keyboard.h"

int main () {
    int key;

    printf("Pressione as setas do teclado (ESC para sair)\n");
    printf("Funciona no Windows e Linux!\n\n");

    while(1) {
        if (kbhit()) {
            key = read_key();

            switch(key) {
                case KEY_UP:
                    printf("Seta CIMA pressionada!\n");
                    break;
                case KEY_DOWN:
                    printf("Seta BAIXO pressionada!\n");
                    break;
                case KEY_LEFT:
                    printf("Seta ESQUERDA pressionada!\n");
                    break;
                case KEY_RIGHT:
                    printf("Seta DIREITA pressionada!\n");
                    break;
                case KEY_ENTER:
                    printf("ENTER pressionado!\n");
                    break;
                case KEY_ESC:
                    printf("ESC pressionado. Saindo...\n");
                    return 0;
                case KEY_SPACE:
                    printf("ESPAÇO pressionado!\n");
                    break;
                case KEY_BACKSPACE:
                    printf("BACKSPACE pressionado!\n");
                    break;
                default:
                    if (key >= 32 && key <= 126) {
                        printf("Tecla '%c' pressionada (código: %d)\n", key, key);
                    }
            }
        }
    }
    sleep(1000);
    return 0;
}