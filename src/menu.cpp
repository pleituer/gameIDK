#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "screen.h"
#include "menu.h"
#include "input.h"
#include "statusConstants.h"


using namespace std;
const Vector3i& w = Vector3i(255, 255, 255);
const Vector3i& b = Vector3i(0, 0, 0);
const Vector3i& r = Vector3i(255, 0, 0);
const Vector3i& y = Vector3i(255, 255, 0);
const Vector3i& g = Vector3i(0, 255, 0);
const Vector3i& BL = Vector3i(0, 0, 255);

Vector3i border = Vector3i(255, 0, 0);

// read ppm file
// for main menu
const char* bplay = "img/playbutton2.ppm";
PPMFile bPlay = PPMFile(bplay);
const char* bhelp = "img/helpbutton.ppm";
PPMFile bHelp = PPMFile(bhelp);
const char* bsea ="img/searchbutton.ppm";
PPMFile bSearch = PPMFile(bsea);
const char* title = "img/titleofgame.ppm";
PPMFile Title = PPMFile(title);
const char* background = "img/background.ppm";
PPMFile Background = PPMFile(background);
const char* background1 = "img/background1.ppm";
PPMFile Background1 = PPMFile(background1);
const char* background2 = "img/background2.ppm";
PPMFile Background2 = PPMFile(background2);

// for select menu
const char* u_0 = "img/unit_0.ppm";
PPMFile U_0 = PPMFile(u_0);
const char* u_1 = "img/unit_1.ppm";
PPMFile U_1 = PPMFile(u_1);
const char* u_2 = "img/unit_2.ppm";
PPMFile U_2 = PPMFile(u_2);
const char* u_3 = "img/unit_3.ppm";
PPMFile U_3 = PPMFile(u_3);
const char* u_4 = "img/unit_4.ppm";
PPMFile U_4 = PPMFile(u_4);
const char* u_5 = "img/unit_5.ppm";
PPMFile U_5 = PPMFile(u_5);
const char* u_6 = "img/unit_6.ppm";
PPMFile U_6 = PPMFile(u_6);
const char* u_7 = "img/unit_7.ppm";
PPMFile U_7 = PPMFile(u_7);
const char* u_8 = "img/unit_8.ppm";
PPMFile U_8 = PPMFile(u_8);
const char* u_9 = "img/unit_9.ppm";
PPMFile U_9 = PPMFile(u_9);
const char* enterleveltoplay = "img/EnterLeveltoPlay.ppm";
PPMFile EnterLeveltoPlay = PPMFile(enterleveltoplay);

// For Congrats screen
const char* goodgame = "img/GoodGame.ppm";
PPMFile Goodgame = PPMFile(goodgame);
const char* back = "img/backbutton.ppm";
PPMFile Back = PPMFile(back);
const char* nextt = "img/nextbutton.ppm";
PPMFile Next = PPMFile(nextt);
const char* keyforback = "img/keyforback.ppm";
PPMFile Keyforback = PPMFile(keyforback);
const char* keyfornext = "img/keyfornext.ppm";
PPMFile Keyfornext = PPMFile(keyfornext);


void fillbackground(PPMFile backgroud,Screen& scr)
{
    Vector2i start = Vector2i(0,0);
    Vector2i endpoint = Vector2i(10,10);
    Vector2f pos;
    for (int i = 0; i < 8; i++ )
    {
        for (int j = 0; j < 6; j ++)
        {
            pos = Vector2f(i*10,j*10);
            scr.renderImg(backgroud, start, endpoint, pos);
        }
    }

}

button::button(Vector2i s, Vector2i e, int v, Vector3i& c) {
    start = s;
    end = e;
    value = v;
    selectedColor = c;
}

button::button(Vector2f s, Vector2i e, int v, Vector3i& c) {
    start = Vector2i(s.x, s.y);
    end = Vector2i(s.x + e.x, s.y + e.y);
    value = v;
    selectedColor = c;
}

button::button(int sx, int ex, int sy, int ey, int v, Vector3i& c) {
    start = Vector2i(sx, sy);
    end = Vector2i(ex, ey);
    value = v;
    selectedColor = c;
}

void button::highlight(Screen& scr) const {
    scr.drawExclusiveRectangle(start, end, selectedColor);
}

// Displays the main menu and prompt the user to select
void PlayMenu(int& status, Screen& scr, int key , int& currentSelect) {

    //position of image
    Vector2f pos_play;
    Vector2f pos_search;
    Vector2f pos_help;
    Vector2f pos_title;


    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_play = Vector2i(30,7);
    Vector2i endpoint_search = Vector2i(30,7);
    Vector2i endpoint_help = Vector2i(30,7);
    Vector2i endpoint_title = Vector2i(46,15);



    pos_play = Vector2f(25,27);
    pos_search = Vector2f(25,37);
    pos_help = Vector2f(25,47);
    pos_title = Vector2f(17,2);


    // randomly form background
    srand((unsigned)time(NULL));
    int max = 3;
    int min = 1;
    int x = rand() % (max - min + 1) + min ;

    if ( x == 1) {fillbackground(Background,scr);}
    else if (x == 2){fillbackground(Background1,scr);}
    else {fillbackground(Background2,scr);}

    // put the button and title
    scr.renderImg(bPlay, start, endpoint_play, pos_play);
    button playButton(pos_play, endpoint_play, M_maze, border);

    scr.renderImg(bHelp,start,endpoint_help,pos_help);
    button helpButton(pos_help, endpoint_help, M_helpMenu, border);

    scr.renderImg(bSearch,start,endpoint_search,pos_search);
    button searchButton(pos_search, endpoint_search,M_SelectMenu, border);

    scr.renderImg(Title,start,endpoint_title,pos_title);
    //scr.setBoarders(BL);

    button select[3] = {playButton, searchButton, helpButton};
    select[currentSelect].highlight(scr);
    switch (key) {
        case K_d:
        case K_D:
        case K_RIGHT:
        case K_s:
        case K_S:
        case K_DOWN:
            currentSelect += 1;
            break;
        case K_w:
        case K_W:
        case K_UP:
        case K_a:
        case K_A:
        case K_LEFT:
            currentSelect -= 1;
            break;
        case K_Space:
            status = select[currentSelect].value;
            currentSelect = 0;
            return;
    }
    currentSelect %= 3;
}

void RenderNumber(string current, Vector2f& pos_U, Vector2i& start, Vector2i& endpoint_U, Screen& scr) {
    PPMFile tempChar;
    for (int i = 0; i < current.size(); i++) {
        int temp = current[i] - 48;
        switch (temp) {
            case 0:
                tempChar = U_0;
                break;
            case 1:
                tempChar = U_1;
                break;
            case 2:
                tempChar = U_2;
                break;
            case 3:
                tempChar = U_3;
                break;
            case 4:
                tempChar = U_4;
                break;
            case 5:
                tempChar = U_5;
                break;
            case 6:
                tempChar = U_6;
                break;
            case 7:
                tempChar = U_7;
                break;
            case 8:
                tempChar = U_8;
                break;
            case 9:
                tempChar = U_9;
                break;
        }

    scr.renderImg(tempChar, start, endpoint_U, pos_U);
    pos_U.x += 9;
    }
}

void SelectMenu(int& status, int& seed, Screen& scr, int key) {

    string current = to_string(seed);
    while (current.size() < 6) {current = "0" + current;}

    Vector2f pos_U;
    Vector2f pos_EnterLeveltoPlay;

    Vector2i start = Vector2i(0, 0);
    Vector2i endpoint_U = Vector2i(7, 12);
    Vector2i endpoint_EnterLeveltoPlay = Vector2i(58, 17);

    pos_EnterLeveltoPlay = Vector2f(11, 10);

    // put the button and title
    scr.renderImg(EnterLeveltoPlay, start, endpoint_EnterLeveltoPlay, pos_EnterLeveltoPlay);

    pos_U = Vector2f(13, 34);
    RenderNumber(current, pos_U, start, endpoint_U, scr);
    if (key > K_0 - 1 && key < K_9 + 1) {if (current[0] == K_0) {seed = seed*10 + key-K_0;}}
    switch (key) {
        case K_Bkspc:
        case K_Del:
            seed /= 10;
            break;
        case K_Space:
            seed = stoi(current);
            status = M_maze;
            break;
        case K_b:
        case K_B:
            status = M_MainMenu;
            break;
    }

}
void CongratsMenu(Screen& scr)
{
    Vector2f pos_Goodgame;
    Vector2f pos_Back;
    Vector2f pos_Next;
    Vector2f pos_Keyforback;
    Vector2f pos_Keyfornext;
    
    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_Goodgame = Vector2i(65,17);
    Vector2i endpoint_Back = Vector2i(30,10);
    Vector2i endpoint_Next = Vector2i(30,10);
    Vector2i endpoint_Keyforback = Vector2i(20,10);
    Vector2i endpoint_Keyfornext = Vector2i(20,10);


    pos_Goodgame = Vector2f(11,5);
    pos_Back = Vector2f(25,27);
    pos_Next = Vector2f(25,47);
    pos_Keyforback = Vector2f(60,27);
    pos_Keyfornext = Vector2f(60,47);

    scr.renderImg(Goodgame,start,endpoint_Goodgame,pos_Goodgame);
    scr.renderImg(Back,start,endpoint_Back,pos_Back);
    scr.renderImg(Next,start,endpoint_Next,pos_Next);
    scr.renderImg(Keyforback,start,endpoint_Keyforback,pos_Keyforback);
    scr.renderImg(Keyfornext,start,endpoint_Keyfornext,pos_Keyfornext);
}