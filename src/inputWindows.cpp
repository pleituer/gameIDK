#include "inputWindows.h"
#include "inputConstants.h"

#if _WIN32
    #include <conio.h>

    int getChar() {
        if (kbhit()) {
            int key = _getch();
            if (key == nullKey) {
                _getch();
                return nullKey;
            }
            if (key == windowsSpecialKey) {
                //{'H':UP,'P':DOWN,'K':LEFT,'M':RIGHT}
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
            if (0 < key && key < 128) {return key;}
            return errorKey;
        }
        return nullKey;
    }

    void Init() {}

    void Finish() {}
#endif