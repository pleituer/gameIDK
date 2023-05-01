#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "screen.h"
#include "menu.h"



using namespace std;
const Vector3i& w = Vector3i(255, 255, 255);
const Vector3i& b = Vector3i(0, 0, 0);
const Vector3i& r = Vector3i(255, 0, 0);
const Vector3i& y = Vector3i(255, 255, 0);
const Vector3i& g = Vector3i(0, 255, 0);
const Vector3i& BL = Vector3i(0, 0, 255);
//read ppm file
const char* bplay = "img/playbotton2.ppm";
PPMFile bPlay = PPMFile(bplay);
const char* bhelp = "img/helpbotton.ppm";
PPMFile bHelp = PPMFile(bhelp);
const char* bsea ="img/searchbotton.ppm";
PPMFile bSearch = PPMFile(bsea);
const char* title = "img/titleofgame.ppm";
PPMFile Title = PPMFile(title);
const char* background = "img/backgroud.ppm";
PPMFile Background = PPMFile(background);
const char* background1 = "img/backgroud1.ppm";
PPMFile Background1 = PPMFile(background1);
const char* background2 = "img/backgroud2.ppm";
PPMFile Background2 = PPMFile(background2);



void Playmenu(Screen& scr)

{  
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
    
    // put the botton and title
    scr.renderImg(bPlay, start, endpoint_play, pos_play);
    scr.renderImg(bHelp,start,endpoint_help,pos_help);
    scr.renderImg(bSearch,start,endpoint_search,pos_search);
    scr.renderImg(Title,start,endpoint_title,pos_title);
    //scr.setBoarders(BL);
    scr.display();
    string k;
    cin >> k;
}
