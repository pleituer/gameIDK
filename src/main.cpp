#include <iostream>
#include <cmath>
#include <time.h>

#include "input.h"
#include "screen.h"
#include "fileRead.h"
#include "helpersConsts.h"
#include "maze.h"
#include "player.h"

using namespace std;

int main() {
    Init();
    const char* wallText = "WallTexture.ppm";
    PPMFile walltex = PPMFile(wallText);
    const char* iconsfile = "userIcon.ppm";
    PPMFile icons = PPMFile(iconsfile);
    Screen scr = Screen(42, 32);
    scr.Init();
    Vector2f start = Vector2f(1.0f, 1.0f);
    Maze mz = Maze(31, 31, scr, start, false);
    Player player = Player(mz, scr);
    Vector2i* texStart = new Vector2i[20] {Vector2i(0, 0), Vector2i(5, 0), Vector2i(10, 0), Vector2i(15, 0), Vector2i(0, 5), Vector2i(5, 5), Vector2i(10, 5), Vector2i(15, 5),Vector2i(20, 5), Vector2i(25, 5), Vector2i(30, 5), Vector2i(35, 5), Vector2i(40, 5), Vector2i(45, 5), Vector2i(50, 5), Vector2i(55, 5), Vector2i(60, 5), Vector2i(65, 5), Vector2i(70, 5), Vector2i(75, 5)};
    Vector2i* texEnd = new Vector2i[20];
    for (int i = 0; i < 20; ++i) {texEnd[i] = Vector2i(mz.cellSize, mz.cellSize) + texStart[i];}
    int ch = getChar();
    clock_t current_ticks, delta_ticks;
    clock_t fps = 0;
    cout << "Hi"<< endl;
    while (ch != K_q) {
        current_ticks = clock();
        cout << "fps: " << fps << endl;
        player.display(scr, mz, icons, walltex, texStart, texEnd, start);
        scr.setBoarders(BLUE);
        //scr.setPixel(start, RED);
        //scr.setPixel(start + Vector2i(5, 5), GREEN);
        scr.display();
        scr.moveUp();
        cout << "\x1b[1A\x1b[K";
        ch = getChar();
        player.update(ch, mz);
        delta_ticks = clock() - current_ticks;
        if(delta_ticks > 0) {fps = CLOCKS_PER_SEC / delta_ticks;}
    }
    scr.clear();
    scr.Done();
    Finish();
    return 0;
}