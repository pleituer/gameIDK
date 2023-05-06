// Include necessary libraries and header files
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "screen.h"
#include "menu.h"
#include "input.h"
#include "statusConstants.h"


using namespace std;
// Define color constants
// White color
const Vector3i& w = Vector3i(255, 255, 255);
// Black color
const Vector3i& b = Vector3i(0, 0, 0);
// Red color
const Vector3i& r = Vector3i(255, 0, 0);
// Yellow color
const Vector3i& y = Vector3i(255, 255, 0);
// Green color
const Vector3i& g = Vector3i(0, 255, 0);
 // Blue color
const Vector3i& BL = Vector3i(0, 0, 255);

// Red color for border
Vector3i border = Vector3i(255, 0, 0);

// Declare file paths for images used in the program
// Images for the main menu
const char* bplay = "img/playbutton2.ppm";
// Play button image
PPMFile bPlay = PPMFile(bplay);
const char* bhelp = "img/helpbutton.ppm";
// Help button image
PPMFile bHelp = PPMFile(bhelp);
// Search button image
const char* bsea ="img/searchbutton.ppm";
// Title image
PPMFile bSearch = PPMFile(bsea);

const char* mreset = "img/mreset.ppm";
PPMFile Mreset = PPMFile(mreset);

const char* title = "img/titleofgame.ppm";
PPMFile Title = PPMFile(title);
const char* background = "img/background.ppm";
// Background image 
PPMFile Background = PPMFile(background);
const char* background1 = "img/background1.ppm";
// Background image 1
PPMFile Background1 = PPMFile(background1);
const char* background2 = "img/background2.ppm";
// Background image 2
PPMFile Background2 = PPMFile(background2);

//Images for the help menu
const char* movebutton = "img/movebutton.ppm";
PPMFile Movebutton = PPMFile(movebutton);
const char* wasdbutton = "img/wasdbutton.ppm";
PPMFile Wasdbutton= PPMFile(wasdbutton);
const char* keymovebutton = "img/keymovebutton.ppm";
PPMFile Keymovebutton = PPMFile(keymovebutton);
const char* placemarker = "img/placemarker.ppm";
PPMFile Placemarker = PPMFile(placemarker);
const char* xbutton = "img/xbutton.ppm";
PPMFile Xbutton = PPMFile(xbutton);
const char* removemarker = "img/removemarker.ppm";
PPMFile Removemarker = PPMFile(removemarker);
const char* qbutton = "img/qbutton.ppm";
PPMFile Qbutton = PPMFile(qbutton);
const char* ybutton = "img/ybutton.ppm";
PPMFile Ybutton = PPMFile(ybutton);
const char* smallback = "img/smallback.ppm";
PPMFile Smallback = PPMFile(smallback);
const char* bbutton = "img/bbutton.ppm";
PPMFile Bbutton = PPMFile(bbutton);
const char* quitbotton = "img/quit.ppm";
PPMFile Quitbotton = PPMFile(quitbotton);

// Image for the pause 
const char* cbutton = "img/cbutton.ppm";
PPMFile Cbutton = PPMFile(cbutton);
const char* ccontinue = "img/continue.ppm";
PPMFile Ccontinue = PPMFile(ccontinue);
const char* paused = "img/pause.ppm";
PPMFile Paused = PPMFile(paused);

// Image for the reset
const char* rbutton= "img/rbutton.ppm";
PPMFile Rbutton = PPMFile(rbutton);
const char* rreset = "img/reset.ppm";
PPMFile Rreset = PPMFile(rreset);
const char* successfully = "img/successfully.ppm";
PPMFile Successfully = PPMFile(successfully);

// Images for the select menu
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

// Images for the congrats screen
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
const char* level1 = "img/level1.ppm";
PPMFile Level1 = PPMFile(level1);




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
    Vector2f pos_Mreset;


    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_play = Vector2i(30,7);
    Vector2i endpoint_search = Vector2i(30,7);
    Vector2i endpoint_help = Vector2i(30,7);
    Vector2i endpoint_title = Vector2i(46,15);
    Vector2i endpoint_Mreset = Vector2i(30,7);



    pos_play = Vector2f(25,21);
    pos_search = Vector2f(25,31);
    pos_help = Vector2f(25,41);
    pos_title = Vector2f(17,2);
    pos_Mreset = Vector2f(25,51);


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

    scr.renderImg(Mreset,start, endpoint_Mreset,pos_Mreset);
    button mresetButton(pos_Mreset, endpoint_Mreset, M_Reset, border);

    scr.renderImg(Title,start,endpoint_title,pos_title);
    //scr.setBoarders(BL);

    button select[4] = {playButton, searchButton, helpButton, mresetButton};
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
    if (currentSelect < 0) {currentSelect += 4;}
    currentSelect %= 4;
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
    Vector2f pos_Level1;
    
    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_Goodgame = Vector2i(65,17);
    Vector2i endpoint_Back = Vector2i(30,10);
    Vector2i endpoint_Next = Vector2i(30,10);
    Vector2i endpoint_Keyforback = Vector2i(20,10);
    Vector2i endpoint_Keyfornext = Vector2i(20,10);
    Vector2i endpoint_Level1 = Vector2i(20,10);


    pos_Goodgame = Vector2f(11,5);
    pos_Back = Vector2f(25,33);
    pos_Next = Vector2f(25,47);
    pos_Keyforback = Vector2f(60,34);
    pos_Keyfornext = Vector2f(60,47);
    pos_Level1 = Vector2f(3,20);

    scr.renderImg(Goodgame,start,endpoint_Goodgame,pos_Goodgame);
    scr.renderImg(Back,start,endpoint_Back,pos_Back);
    scr.renderImg(Next,start,endpoint_Next,pos_Next);
    scr.renderImg(Keyforback,start,endpoint_Keyforback,pos_Keyforback);
    scr.renderImg(Keyfornext,start,endpoint_Keyfornext,pos_Keyfornext);
    scr.renderImg(Level1,start,endpoint_Level1,pos_Level1);
}
void Pausescreen(Screen& scr)
{   
    Vector2f pos_Ccontinue;
    Vector2f pos_Cbutton;
    Vector2f pos_Back;
    Vector2f pos_Keyforback;
    Vector2f pos_Paused;
    
    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_Ccontinue= Vector2i(60,10);
    Vector2i endpoint_Cbutton = Vector2i(20,10);
    Vector2i endpoint_Keyforback = Vector2i(20,10);
    Vector2i endpoint_Back = Vector2i(30,10);
    Vector2i endpoint_Paused = Vector2i(30,7);

    pos_Ccontinue = Vector2f(10,15);
    pos_Cbutton = Vector2f(54,31);
    pos_Back = Vector2f(10, 37);
    pos_Keyforback = Vector2f(40,50);
    pos_Paused = Vector2f(30,3);

    scr.renderImg(Ccontinue,start,endpoint_Ccontinue,pos_Ccontinue);
    scr.renderImg(Cbutton,start,endpoint_Cbutton,pos_Cbutton);
    scr.renderImg(Back,start,endpoint_Back,pos_Back);
    scr.renderImg(Keyforback,start,endpoint_Keyforback,pos_Keyforback);
    scr.renderImg(Paused,start,endpoint_Paused,pos_Paused);
    
}

void Helpermenu(Screen& scr)
{
    Vector2f pos_Movebutton;
    Vector2f pos_Bbutton;
    Vector2f pos_Xbutton;
    Vector2f pos_Removemarker;
    Vector2f pos_Qbutton;
    Vector2f pos_Wasdbutton;
    Vector2f pos_Keymovebutton;
    Vector2f pos_Placemarker;
    Vector2f pos_Ybutton;
    Vector2f pos_Smallback;
    Vector2f pos_Quitbotton;

    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_Movebutton = Vector2i(19,7);
    Vector2i endpoint_Bbutton = Vector2i(19,7);
    Vector2i endpoint_Xbutton = Vector2i(14,7);
    Vector2i endpoint_Removemarker = Vector2i(60,7);
    Vector2i endpoint_Qbutton= Vector2i(19,7);
    Vector2i endpoint_Wasdbutton = Vector2i(19,7);
    Vector2i endpoint_Keymovebutton = Vector2i(26,7);
    Vector2i endpoint_Placemarker = Vector2i(54,7);
    Vector2i endpoint_Ybutton = Vector2i(14,7);
    Vector2i endpoint_Smallback= Vector2i(19,7);
    Vector2i endpoint_Quitbotton = Vector2i(29,7);

    pos_Movebutton = Vector2f(3,10);
    pos_Wasdbutton = Vector2f(30,10);
    pos_Keymovebutton = Vector2f(55,10);
    pos_Placemarker = Vector2f(3,20);
    pos_Xbutton = Vector2f(60,20);
    pos_Removemarker = Vector2f(3,30);
    pos_Ybutton = Vector2f(66,30);
    pos_Quitbotton = Vector2f(3,40);
    pos_Qbutton =Vector2f(40,40);
    pos_Smallback = Vector2f(3,50);
    pos_Bbutton =Vector2f(40,50);
    scr.renderImg(Movebutton,start,endpoint_Movebutton,pos_Movebutton);
    scr.renderImg(Wasdbutton,start,endpoint_Wasdbutton,pos_Wasdbutton);
    scr.renderImg(Keymovebutton,start,endpoint_Keymovebutton,pos_Keymovebutton);
    scr.renderImg(Placemarker,start,endpoint_Placemarker,pos_Placemarker);
    scr.renderImg(Xbutton,start,endpoint_Xbutton,pos_Xbutton);
    scr.renderImg(Removemarker,start,endpoint_Removemarker,pos_Removemarker);
    scr.renderImg(Ybutton,start,endpoint_Ybutton,pos_Ybutton);
    scr.renderImg(Qbutton,start,endpoint_Qbutton,pos_Qbutton);
    scr.renderImg(Quitbotton,start,endpoint_Quitbotton,pos_Quitbotton);
    scr.renderImg(Smallback,start,endpoint_Smallback,pos_Smallback);
    scr.renderImg(Bbutton,start,endpoint_Bbutton,pos_Bbutton);

}
void Resetscreen(Screen& scr)
{
    Vector2f pos_Back;
    Vector2f pos_Keyforback;
    Vector2f pos_Rbutton;
    Vector2f pos_Rreset;
    

    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_Rreset= Vector2i(37,10);
    Vector2i endpoint_Rbutton = Vector2i(20,10);
    Vector2i endpoint_Keyforback = Vector2i(20,10);
    Vector2i endpoint_Back = Vector2i(30,10);
    
    pos_Rreset = Vector2f(10,10);
    pos_Rbutton=Vector2f(45,25);
    pos_Back = Vector2f(10, 37);
    pos_Keyforback = Vector2f(35,50);

    scr.renderImg(Rreset,start,endpoint_Rreset,pos_Rreset);
    scr.renderImg(Rbutton,start,endpoint_Rbutton,pos_Rbutton);
    scr.renderImg(Back,start,endpoint_Back,pos_Back);
    scr.renderImg(Keyforback,start,endpoint_Keyforback,pos_Keyforback);
}

void Resetsuccess(Screen& scr)
{
    Vector2f pos_Successfully;
    Vector2i start = Vector2i(0,0);
    Vector2i endpoint_Successfully = Vector2i(60,40);
    pos_Successfully = Vector2f(10,10);
    scr.renderImg(Successfully,start,endpoint_Successfully,pos_Successfully);
}

    
    


