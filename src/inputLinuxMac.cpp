// Include the header file for Linux and macOS input handling
#include "inputLinuxMac.h"
/ Include the header file containing input-related constants
#include "inputConstants.h"

// Check if the operating system is macOS or Linux
#if __APPLE__ || __linux__
    // Include the termios header for terminal I/O settings
    #include <termios.h>
    // Include the unistd header for POSIX OS API
    #include <unistd.h>
    // Include the sys/types header for system data types
    #include <sys/types.h>
    // Include the sys/time header for time types
    #include <sys/time.h>
    // Include the sys/ioctl header for I/O control
    #include <sys/ioctl.h>
    // Include the stdio header for standard I/O functions
    #include <stdio.h>

    // Thank you to Ben Vogit in https://stackoverflow.com/questions/6698161/getting-raw-input-from-console-using-c-or-c
    static struct termios old, new1;
    fd_set readfds, master;
    int fps = 60;
    float deltime = 1/fps;
    struct timeval tv;

    void Init() {
        // Set microseconds in timeval structure to 0
        tv.tv_usec = 0;
        // Clear the readfds file descriptor set
        FD_ZERO(&readfds);
        // Clear the master file descriptor set
        FD_ZERO(&master);
        // Add the standard input file descriptor (0) to readfds
        FD_SET(0, &readfds);
        // Add the standard input file descriptor (0) to master
        FD_SET(0, &master);
        // Get the current terminal I/O settings and store them in 'old'
        tcgetattr(0, &old); /* grab old terminal i/o settings */
        new1 = old; /* make new settings same as old settings */
        new1.c_lflag &= ~ICANON; /* disable buffered i/o */
        new1.c_lflag &= ~ECHO; /* set echo mode */
        tcsetattr(0, TCSANOW, &new1); /* use these new terminal i/o settings now */
    }

    /* Restore old terminal i/o settings */
    void Finish() {
        // Restore the old terminal I/O settings
        tcsetattr(0, TCSANOW, &old);
    }

    int _getch() {
    // Set the seconds part of the timeval structure to the delay time
        tv.tv_sec = deltime;
        // Copy the master file descriptor set to readfds
        readfds = master;
        // Declare a character variable 'c'
        char c;
        // Wait for input with a timeout
        if (select(1, &readfds, NULL, NULL, &tv)==-1) {perror("select");}
        // Check if the standard input file descriptor (0) is ready for reading
        if (FD_ISSET(0, &readfds)) {
        // Read one character from the standard input and store it in 'c'
            read(0, &c, 1);
        }
        // Return the integer value of the character 'c'
        return (int) c;
    }

    int getChar() {
    // Get a character using the _getch function
        int key = _getch();
        // If the key is 0, return the nullKey constant
        if (key == 0) {return nullKey;} 
        // Detect special keys, such as arrow keys, by their escape sequences
        if (key == unixSpecialKey1 && _getch() == unixSpecialKey2) {
            // {'\x1b[A':UP,'\x1b[B':DOWN,'\x1b[C':RIGHT,'\x1b[D':LEFT}
            // Get the next character in the escape sequence
            key = _getch();
             // Determine which special key was pressed
            switch (key) {
            case K_A:
            // If it's the up arrow key, return K_UP
                return K_UP;
            case K_B:
            // If it's the down arrow key, return K_DOWN
                return K_DOWN;
            case K_D:
            // If it's the left arrow key, return K_LEFT
                return K_LEFT;
            case K_C:
             // If it's the right arrow key, return K_RIGHT
                return K_RIGHT;
            }
        } 
        // If the key is within the valid ASCII range, return the key
        if (0 < key && key < 128) {return key;}
        // If an invalid key is detected, return the errorKey constant
        return errorKey;
    }

    void SetScreenSize(int& width, int& height) {
    // Declare a winsize structure to store the terminal window dimensions
        struct winsize w;
        // Get the terminal window size and store it in 'w'
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        // Set the height variable to the number of rows in the terminal window
        height = w.ws_row;
        // Set the width variable to half the number of columns in the terminal window
        width = w.ws_col / 2;
    }

#endif
