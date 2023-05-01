#include "inputLinuxMac.h"
#include "inputConstants.h"

#if __APPLE__ || __linux__
    #include <termios.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <sys/ioctl.h>
    #include <stdio.h>

    // Thank you to Ben Vogit in https://stackoverflow.com/questions/6698161/getting-raw-input-from-console-using-c-or-c
    static struct termios old, new1;
    fd_set readfds, master;
    int fps = 60;
    float deltime = 1/fps;
    struct timeval tv;

    void Init() {
        tv.tv_usec = 0;
        FD_ZERO(&readfds);
        FD_ZERO(&master);
        FD_SET(0, &readfds);
        FD_SET(0, &master);
        tcgetattr(0, &old); /* grab old terminal i/o settings */
        new1 = old; /* make new settings same as old settings */
        new1.c_lflag &= ~ICANON; /* disable buffered i/o */
        new1.c_lflag &= ~ECHO; /* set echo mode */
        tcsetattr(0, TCSANOW, &new1); /* use these new terminal i/o settings now */
    }

    /* Restore old terminal i/o settings */
    void Finish() {
        tcsetattr(0, TCSANOW, &old);
    }

    int _getch() {
        tv.tv_sec = deltime;
        readfds = master;
        char c;
        if (select(1, &readfds, NULL, NULL, &tv)==-1) {perror("select");}
        if (FD_ISSET(0, &readfds)) {
            read(0, &c, 1);
        }
        return (int) c;
    }

    int getChar() {
        int key = _getch();
        if (key == 0) {return nullKey;} 
        if (key == unixSpecialKey1 && _getch() == unixSpecialKey2) {
            // {'\x1b[A':UP,'\x1b[B':DOWN,'\x1b[C':RIGHT,'\x1b[D':LEFT}
            key = _getch();
            switch (key) {
            case K_A:
                return K_UP;
            case K_B:
                return K_DOWN;
            case K_D:
                return K_LEFT;
            case K_C:
                return K_RIGHT;
            }
        } 
        if (0 < key && key < 128) {return key;}
        return errorKey;
    }

    void SetScreenSize(int& width, int& height); {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        width = w.ws_row/2;
        height = w.ws_col;
    }

#endif
