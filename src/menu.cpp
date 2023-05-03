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


void PlayMenu(Screen& scr) {
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
    cout << x << endl;

    if ( x == 1) {fillbackground(Background,scr);}
    else if (x == 2){fillbackground(Background1,scr);}
    else {fillbackground(Background2,scr);}
    
    // put the button and title
    scr.renderImg(bPlay, start, endpoint_play, pos_play);
    scr.renderImg(bHelp,start,endpoint_help,pos_help);
    scr.renderImg(bSearch,start,endpoint_search,pos_search);
    scr.renderImg(Title,start,endpoint_title,pos_title);
    //scr.setBoarders(BL);
    scr.display();
    string k;
    cin >> k;
}

int SelectMenu(Screen& scr) {

    //position of menu
    Vector2f stageButton = Vector2f(3, 4);


    return 0;
}