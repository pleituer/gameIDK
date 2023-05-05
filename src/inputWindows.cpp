#include "inputWindows.h"
#include "inputConstants.h"

// Compile the following code only if _WIN32 is defined (Windows environment)
#if _WIN32
    // Include the conio.h header for console I/O functions
    #include <conio.h>
    // Include the windows.h header for Windows-specific functions
    #include <windows.h>

    // This function gets a character input from the keyboard
    int getChar() {
        // Check if a key has been pressed using kbhit()
        if (kbhit()) {
            // Get the pressed key using _getch()
            int key = _getch();
            // Check if the key is a null key
            if (key == nullKey) {
                // Consume the next key
                _getch();
                // Return the null key constant
                return nullKey;
            }
            // Check if the key is a special key (e.g., arrow keys)
            if (key == windowsSpecialKey) {
               // Map special keys to their corresponding constants
                //{'H':UP,'P':DOWN,'K':LEFT,'M':RIGHT}
                // Get the next key
                key = _getch();
                switch (key) {
                case K_H:
                    return K_UP;
                case K_P:
                    return K_DOWN;
                case K_K:
                    return K_LEFT;
                case K_M:
                    return K_RIGHT;
                }
            }
            // If the key is a valid ASCII character, return its value
            if (0 < key && key < 128) {return key;}
            // If the key is invalid, return the error key constant
            return errorKey;
        }
        // If no key has been pressed, return the null key constant
        return nullKey;
    }
    // This function initializes the Windows input system (currently empty)
    void Init() {}

    // This function cleans up the Windows input system (currently empty)
    void Finish() {}

    // This function sets the console screen size for the Windows environment
    void SetScreenSize(int& width, int& height) {
        // Declare a structure to store console buffer info
        CONSOLE_SCREEN_BUFFER_INFO csbi;    
        // Declare a structure to store console buffer info
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        // Calculate the width and height of the console window
        width = (csbi.srWindow.Right - csbi.srWindow.Left + 1)/2;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
#endif
