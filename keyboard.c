#include <stdio.h>
#include "keyboard.h"

// Detecta se uma tecla foi pressionada
int kbhit(void) {
#if IS_WINDOWS
    return _kbhit();
#else
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
#endif
}

// Lê uma tecla sem echo
int getch_custom(void) {
#if IS_WINDOWS
    return _getch();
#else
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

// Lê tecla (incluindo setas e teclas especiais)
int read_key(void) {
    int ch = getch_custom();

#if IS_WINDOWS
    // Windows usa códigos especiais para setas
    if (ch == 0 || ch == 224) {
        ch = getch_custom();
        switch(ch) {
            case 72: return KEY_UP;
            case 80: return KEY_DOWN;
            case 75: return KEY_LEFT;
            case 77: return KEY_RIGHT;
        }
    }

    // Teclas comuns
    switch(ch) {
        case 13: return KEY_ENTER;
        case 27: return KEY_ESC;
        case 32: return KEY_SPACE;
        case 8: return KEY_BACKSPACE;
    }
#else
    // Linux usa sequências de escape ANSI
    if (ch == 27) {
        ch = getch_custom();
        if (ch == '[') {
            ch = getch_custom();
            switch(ch) {
                case 'A': return KEY_UP;
                case 'B': return KEY_DOWN;
                case 'C': return KEY_RIGHT;
                case 'D': return KEY_LEFT;
            }
        } else {
            return KEY_ESC;
        }
    }

    // Teclas comuns
    switch(ch) {
        case 10: return KEY_ENTER;
        case 32: return KEY_SPACE;
        case 127: return KEY_BACKSPACE;
    }
#endif

    return ch;
}
