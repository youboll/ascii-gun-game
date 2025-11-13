#ifndef KEYBOARD_H
#define KEYBOARD_H
int kbhit(void);
int getch_custom(void);
int read_key(void);

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


#endif