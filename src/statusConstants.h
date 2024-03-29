// If the statusConstantConst macro is not defined, define it as 1.
#if !defined(statusConstantConst)
#define statusConstantConst 1

/*
    0: main menu
    1: select screen
    2: help screen
    3: maze
    4: congrats screen after solving maze
    5: pause screen
    6: reset screen
*/

const int M_MainMenu = 0;
const int M_SelectMenu = 1;
const int M_helpMenu = 2;
const int M_maze = 3;
const int M_congratz = 4;
const int M_Pause = 5;
const int M_Reset = 6;

#endif
