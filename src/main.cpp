#include <iostream>
#include <cmath>

#include "input.hpp"
#include "screen.hpp"
#include "fileRead.hpp"
#include "helpersConsts.hpp"
#include "maze.hpp"

using namespace std;

int main() {
    Init();
    cout << OSType << '\n';
    const char* ppmName = "sus.ppm";
    PPMFile img = PPMFile(ppmName);
    Screen scr = Screen(41, 32);
    cout << "Hi"<< endl;
    //cout << mz.getWidth() << endl;
    scr.Init();
    Vector2f start = Vector2f(1.0f, 1.0f);
    Vector2f end = Vector2f(25.0f, 13.0f);
    Vector2i imgStart = Vector2i(0, 0);
    Vector2i imgEnd = Vector2i(8, 8);
    Maze mz = Maze(39, 30, scr, start, true);
    int ch = getChar();
    while (ch != K_q) {
        scr.setBoarders(BLUE);
        mz.display(scr, start);
        scr.setPixel(mz.startingPoint+start, GREEN);
        scr.setPixel(mz.endingPoint+start, RED);
        /*switch (ch) {
        case upArrow:
            start.y -= 1;
            break;
        case downArrow:
            start.y += 1;
            break;
        case leftArrow:
            start.x -= 1;
            break;
        case rightArrow:
            start.x += 1;
            break;
        case K_w:
            end.y -= 1;
            break;
        case K_a:
            end.x -= 1;
            break;
        case K_s:
            end.y += 1;
            break;
        case K_d:
            end.x += 1;
            break;
        }
        start.x = max(1.0f, min(start.x, float(scr.getWidth()-2)));
        start.y = max(1.0f, min(start.y, float(scr.getHeight()-2)));
        end.x = max(1.0f, min(end.x, float(scr.getWidth()-2)));
        end.y = max(1.0f, min(end.y, float(scr.getHeight()-2)));
        scr.renderImg(img, imgStart, imgEnd, end);
        scr.drawCircle(end, sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)), YELLOW);
        scr.drawLine(start, end, GREY);
        scr.setPixel(start.x, start.y, RED);
        scr.setPixel(end.x, end.y, GREEN);*/
        scr.display();
        scr.moveUp();
        ch = getChar();
    }
    scr.clear();
    scr.Done();
    Finish();
    return 0;
}