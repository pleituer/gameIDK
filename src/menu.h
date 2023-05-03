#ifndef MENU_H
#define MENU_H


#include "screen.h"

void fillbackground(PPMFile backgroud,Screen& scr);
void PlayMenu(Screen& scr);
int SelectMenu(Screen& scr);
class button {
public:
    Vector2i start;
    Vector2i end;
    int value;
    Vector3i selectedColor;
    button(Vector2i s, Vector2i e, int v, Vector3i& c);
    button(Vector2f s, Vector2i e, int v, Vector3i& c);
    button(int sx, int ex, int sy, int ey, int v, Vector3i& c);
    void highlight(Screen& scr) const;
};

void PlayMenu(int& status, Screen& scr, int key, int& currentSelect);

void SelectMenu(int& status, int& seed, Screen& scr, int key);

#endif