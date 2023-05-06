#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <fstream>

// Include custom header files for the game
#include "input.h"
#include "screen.h"
#include "fileRead.h"
#include "helpersConsts.h"
#include "maze.h"
#include "player.h"
#include "menu.h"
#include "statusConstants.h"
#include "sleep.h"

using namespace std;

// Define file paths for wall and user icon textures
const char* wallText = "img/WallTexture.ppm";
PPMFile walltex = PPMFile(wallText);
const char* iconsfile = "img/userIcon.ppm";
PPMFile icons = PPMFile(iconsfile);

// Define texture start and end positions
Vector2i* texStart = new Vector2i[20] {Vector2i(0, 0), Vector2i(5, 0), Vector2i(10, 0), Vector2i(15, 0), Vector2i(0, 5), Vector2i(5, 5), Vector2i(10, 5), Vector2i(15, 5),Vector2i(20, 5), Vector2i(25, 5), Vector2i(30, 5), Vector2i(35, 5), Vector2i(40, 5), Vector2i(45, 5), Vector2i(50, 5), Vector2i(55, 5), Vector2i(60, 5), Vector2i(65, 5), Vector2i(70, 5), Vector2i(75, 5)};
Vector2i* texEnd = new Vector2i[20];

// Function to ensure the user uses a compatible playing console window
void FoolProofPlan() {
    Init();
    Screen FoolproofPlan = Screen(82, 62);
    FoolproofPlan.Init();
    cout << "Please make sure you can see the whole BLUE RECTANGLE and ALL of the words\nHint: you may need to resize your font (usually Ctrl - will make the font smaller)\nPress Q to quit" << endl;
    FoolproofPlan.setBoarders(BLUE);
    FoolproofPlan.display();
    cout << "Please scroll UP" << endl;
    int width = 0;
    int height = 0;
    int ch;
    while (width < 85 || height < 65) {
        ch = getChar();
        SetScreenSize(width, height);
        if (ch == K_q || ch == K_Q) {FoolproofPlan.clear();FoolproofPlan.Done();Finish();exit(1);}
    }
    FoolproofPlan.Done();
}

// Function to initialize the maze with the given level ID
void MazeInit(int levelID, Maze& mz, Player& player, Screen& scr) {
    Vector2f start = Vector2f(1.0f, 1.0f);
    srand(levelID);
    int width = sqrt(levelID)/2 ;
    int height = 0.8*sqrt(levelID)/2;
    width = 2*width + 1;
    height = 2*height + 1;
    if (width < 21) {width = 21;}
    if (height < 15) {height = 15;}
    mz.~Maze();
    new(&mz) Maze(width, height, scr, start, false);
    player.~Player();
    new(&player) Player(mz, scr);
}

// Function to run the maze and update the game status
void MazeRun(int& status, Maze& mz, Player& player, int ch, Screen& scr, int levelID) {
    Vector2f start = Vector2f(1.0f, 1.0f);
    player.update(ch, mz);
    player.display(scr, mz, icons, walltex, texStart, texEnd, start);
    if (ch == K_b || ch == K_B) {status = 0;}
    if (player.solvedOrNot(mz)) {
        status = 4;
        string strsaveText = "echo " + to_string(levelID) + " >> completedLevels.txt\n";
        char* saveText = new char[strsaveText.length() + 1];
        strcpy(saveText, strsaveText.c_str());
        system(saveText);
        delete[] saveText;
    }
}

int main() {
    // Initialization, variable declarations, and game loop setup
    Init();
    ofstream file ("completedLevels.txt");
    file.close();

    // Ensures that the user uses a compatible playing console window
    FoolProofPlan();
    Screen scr = Screen(82, 62);
    scr.Init();
    int ch = getChar();
    clock_t current_ticks, delta_ticks;
    clock_t fps = 0;

    // To be implemented
    int status = 0;
    int currentSelect = 0;
    int seed = 0;
    int tmp = 0;
    ifstream fin("completedLevels.txt");
    while (fin >> tmp) {seed = tmp;}
    Vector2f start = Vector2f(1.0f, 1.0f);

    Maze mz = Maze(11, 11, scr, start, false);
    Player player = Player(mz, scr);

    for (int i = 0; i < 20; ++i) {texEnd[i] = Vector2i(mz.cellSize, mz.cellSize) + texStart[i];}

    cout << "Hi"<< endl;
    
    // Main game loop
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
                5: pause screen
                6: reset screen
            */
            case M_MainMenu:
                PlayMenu(status, scr, ch, currentSelect);
                if (status == M_maze) {MazeInit(seed, mz, player, scr);}
                else if (status == M_SelectMenu) {seed = 0;}
                break;
            case M_SelectMenu:
                SelectMenu(status, seed, scr, ch);
                if (status == M_maze) { MazeInit(seed, mz, player, scr); }
                break;
            case M_helpMenu:
                //render screen
                Helpermenu(scr);
                if (ch == K_B || ch == K_b || ch == K_Space) {status = M_MainMenu;}
                break;
            case M_maze:
                MazeRun(status, mz, player, ch, scr, seed);
                if (ch == K_Space) {status = M_Pause;}
                break;
            case M_congratz:
                CongratsMenu(scr);
                {
                //render screen
                string strseed = to_string(seed);
                Vector2f pos_U = Vector2f(13, 20);;
                Vector2i start = Vector2i(0, 0);
                Vector2i endpoint_U = Vector2i(7, 12);
                RenderNumber(strseed, pos_U, start, endpoint_U, scr);
                switch (ch) {
                    case K_B:
                    case K_b:
                        status = M_MainMenu;
                        break;
                    case K_N:
                    case K_n:
                        status = M_maze;
                        seed = (seed+1)%1000000;
                        MazeInit(seed, mz, player, scr);
                        break;
                }
                break;
                }
            case M_Pause:
                //render screen
                Pausescreen(scr);
                switch (ch) {
                    case K_b:
                    case K_B:
                        status = M_MainMenu;
                        break;
                    case K_c:
                    case K_C:
                        status = M_maze;
                        break;
                }
                break;
            case M_Reset:
                //render img
                Resetscreen(scr);
                switch (ch) {
                    case K_b:
                    case K_B:
                        status = M_MainMenu;
                        break;
                    case K_r:
                    case K_R:
                        char ResetText[] = "echo 0 > completedLevels.txt\n";
                        system(ResetText);
                        seed = 0;
                        //render img of reseted successfully
                        sleeps(2);
                        status = M_MainMenu;
                        break;
                }
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
    // Clean up and finish
    scr.clear();
    scr.Done();
    Finish();
    return 0;
}
