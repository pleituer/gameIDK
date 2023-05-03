#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "input.h"
#include "screen.h"
#include "menu.h"

using namespace std;
const Vector3i& w = Vector3i(255, 255, 255);
const Vector3i& b = Vector3i(0, 0, 0);
const Vector3i& r = Vector3i(255, 0, 0);
const Vector3i& y = Vector3i(255, 255, 0);
const Vector3i& g = Vector3i(0, 255, 0);
const Vector3i& BL = Vector3i(0, 0, 255);

Vector3i border = Vector3i(255, 0, 0);

//read ppm file
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

void PlayMenu(int& status, Screen& scr, int key , int& currentSelect) {

    //position of image 
    Vector2f pos_play;
    Vector2f pos_search;
    Vector2f pos_help;
    Vector2f pos_title;
    Vector2f pos_backgroud;

    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_play = Vector2i(30,7);
    Vector2i endpoint_search = Vector2i(30,7);
    Vector2i endpoint_help = Vector2i(30,7);
    Vector2i endpoint_title = Vector2i(46,15);
    Vector2i endpoint_background = Vector2i(80,60);
    Vector2i endpoint_background1 = Vector2i(80,60);
    Vector2i endpoint_background2 = Vector2i(80,60);

    
    pos_play = Vector2f(25,27);
    pos_search = Vector2f(25,37);
    pos_help = Vector2f(25,47);
    pos_title = Vector2f(17,2);
    pos_backgroud = Vector2f(0,0);

    // randomly form background
    srand((unsigned)time(NULL));
    int max = 3;
    int min = 1;
    int x = rand() % (max - min + 1) + min ;
    cout << x << endl;

    if ( x == 1) {scr.renderImg(Background,start,endpoint_background,pos_backgroud);}
    else if (x == 2){scr.renderImg(Background1,start,endpoint_background1,pos_backgroud);}
    else {scr.renderImg(Background2,start,endpoint_background2,pos_backgroud);}
    
    // put the button and title
    scr.renderImg(bPlay, start, endpoint_play, pos_play);
    button playButton(pos_play, endpoint_play, 1, border);

    scr.renderImg(bHelp,start,endpoint_help,pos_help);
    button helpButton(pos_help, endpoint_help, 2, border);

    scr.renderImg(bSearch,start,endpoint_search,pos_search);
    button searchButton(pos_search, endpoint_search, 1, border);

    scr.renderImg(Title,start,endpoint_title,pos_title);
    //scr.setBoarders(BL);
    scr.display();

    button select[3] = {playButton, helpButton, searchButton};
    select[currentSelect].highlight(scr);
    switch (key) {
        case K_d:
        case K_D:
        case K_RIGHT:
        case K_w:
        case K_W:
        case K_UP:
            currentSelect += 1;
            break;
        case K_s:
        case K_S:
        case K_DOWN:
        case K_a:
        case K_A:
        case K_LEFT:
            currentSelect -= 1;
            break;
        case K_Space:
            status = select[currentSelect].value;
            break;
    }
    currentSelect %= 3;
}