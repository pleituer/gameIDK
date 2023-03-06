#include "platform.hpp"
#include "inputWindows.hpp"
#include "inputConstants.hpp"

#if OSType == 0
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
                    return upArrow;
                case K_P:
                    return downArrow;
                case K_K:
                    return leftArrow;
                case K_M:
                    return rightArrow;
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