#ifndef MENU_H
#define MENU_H
// Include the string library for handling strings
#include <string>
using namespace std;

// Include the custom header for screen manipulation
#include "screen.h"

// Function prototypes
// Function to fill the screen background
void fillbackground(PPMFile backgroud,Screen& scr);
// Function to display the Play menu
void PlayMenu(Screen& scr);
// Function to display the Select menu
int SelectMenu(Screen& scr);

// Button class definition
class button {
public:
    // Start position of the button
    Vector2i start;
    // End position of the button
    Vector2i end;
    // Value associated with the button
    int value;
    // Color to use when the button is selected
    Vector3i selectedColor;
    // Constructors with different argument types
    button(Vector2i s, Vector2i e, int v, Vector3i& c);
    button(Vector2f s, Vector2i e, int v, Vector3i& c);
    button(int sx, int ex, int sy, int ey, int v, Vector3i& c);
    // Member function to highlight the button on the screen
    void highlight(Screen& scr) const;
};

// Function prototypes with detailed argument descriptions

// Function to display and handle the Play menu with user input
void PlayMenu(int& status, Screen& scr, int key, int& currentSelect);

// Function to render a number on the screen
void RenderNumber(string current, Vector2f& pos_U, Vector2i& start, Vector2i& endpoint_U, Screen& scr);

// Function to display and handle the Select menu with user input
void SelectMenu(int& status, int& seed, Screen& scr, int key);
// Function to display the Congratulations menu
void CongratsMenu(Screen& scr);

#endif
