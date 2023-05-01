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

const char* wallText = "img/WallTexture.ppm";
PPMFile walltex = PPMFile(wallText);
const char* iconsfile = "img/userIcon.ppm";
PPMFile icons = PPMFile(iconsfile);

Vector2i* texStart = new Vector2i[20] {Vector2i(0, 0), Vector2i(5, 0), Vector2i(10, 0), Vector2i(15, 0), Vector2i(0, 5), Vector2i(5, 5), Vector2i(10, 5), Vector2i(15, 5),Vector2i(20, 5), Vector2i(25, 5), Vector2i(30, 5), Vector2i(35, 5), Vector2i(40, 5), Vector2i(45, 5), Vector2i(50, 5), Vector2i(55, 5), Vector2i(60, 5), Vector2i(65, 5), Vector2i(70, 5), Vector2i(75, 5)};
Vector2i* texEnd = new Vector2i[20];

void FoolProofPlan() {
    Screen FoolproofPlan = Screen(82, 62);
    FoolproofPlan.Init();
    cout << "Please make sure you can see the whole BLUE RECTANGLE and ALL of the words" << endl;
    FoolproofPlan.setBoarders(BLUE);
    FoolproofPlan.display();
    cout << "Please scroll UP" << endl;
    int width=0, height=0;
    while (width < 85 || height < 65) {SetScreenSize(width, height);}
    FoolproofPlan.Done();
}

void MazeInit(int levelID, Maze& mz, Player& player, Screen& scr) {
    Vector2f start = Vector2f(1.0f, 1.0f);
    srand(levelID);
    int width = sqrt(levelID)/2 ;
    int height = 0.8*sqrt(levelID)/2;
    width = 2*width + 1;
    height = 2*height + 1;
    if (width < 21) {width = 21;}
    if (height < 15) {height = 15;}
    cout << width << ' ' << height << endl;
    mz.~Maze();
    new(&mz) Maze(width, height, scr, start, false);
    player.~Player();
    new(&player) Player(mz, scr);
}
void MazeRun(int& status, Maze& mz, Player& player, int ch, Screen& scr) {
    Vector2f start = Vector2f(1.0f, 1.0f);
    player.update(ch, mz);
    player.display(scr, mz, icons, walltex, texStart, texEnd, start);
    if (ch == K_b || ch == K_B) {status = 0;}
    if (player.solvedOrNot(mz)) {status = 4;}
}

int main() {

    Init();

    // Ensures that the user uses a compatible playing console window
    FoolProofPlan();
    Screen scr = Screen(82, 62);
    scr.Init();
    int ch = getChar();
    clock_t current_ticks, delta_ticks;
    clock_t fps = 0;
    int status = 3;
    Vector2f start = Vector2f(1.0f, 1.0f);

    Maze mz = Maze(11, 11, scr, start, false);
    Player player = Player(mz, scr);
    MazeInit(0, mz, player, scr);

    for (int i = 0; i < 20; ++i) {texEnd[i] = Vector2i(mz.cellSize, mz.cellSize) + texStart[i];}

    cout << "Hi"<< endl;

    while (ch != K_q && ch != K_Q) {
        current_ticks = clock();
        cout << "fps: " << fps << endl;

        // Dynamicly display the correct screen during the game
        switch (status) {
            /*
                0: main menu
                1: select screen
                2: help screen
                3: maze
                4: congrats screen after solving maze
            */
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                MazeRun(status, mz, player, ch, scr);
                break;
            case 4:
                break;
        }

        scr.setBoarders(BLUE);
        scr.display();
        scr.moveUp();
        cout << "\x1b[1A\x1b[K";
        ch = getChar();
        delta_ticks = clock() - current_ticks;
        if(delta_ticks > 0) {fps = CLOCKS_PER_SEC / delta_ticks;}
    }
    scr.clear();
    scr.Done();
    Finish();
    return 0;
}