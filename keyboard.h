#ifndef KEYBOARD_H
#define KEYBOARD_H
int kbhit(void); // Mostra se alguma tecla foi ativada
int getch_custom(void); // Igual o read_key - Só que mais merda
int read_key(void); // Lê a tecla

#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__) || defined(__MINGW32__) || defined(__MINGW64__)
    #define IS_WINDOWS 1
    #include <conio.h>
    #include <windows.h>
#else
    #define IS_WINDOWS 0
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

typedef enum {
    KEY_UP = 1000,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_ENTER,
    KEY_ESC,
    KEY_SPACE,
    KEY_BACKSPACE
} SpecialKey;

// Entre 32 e 126 São teclas normais


#endif