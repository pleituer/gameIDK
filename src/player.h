#pragma once

// Include necessary header files
#include "helpers.h"
#include "screen.h"
#include "maze.h"
#include "fileRead.h"

// Define the Player class
class Player {
    public:
    // Constructor for Player class, taking a reference to a Maze object and a reference to a Screen
        Player(Maze& mz, Screen& scr);
        // Function to update the player's position based on the key pressed and the Maze object
        void update(int key, Maze& mz);
        // Function to display the player on the screen, including the icon, texture, starting and ending positions, and the maze starting point
        void display(Screen& scr, Maze& mz, PPMFile& icon, PPMFile& texture, Vector2i* startPos, Vector2i* endPos, Vector2f mazeStart);
        // Function to check if the player has reached the end of the maze
        bool solvedOrNot(Maze& mz);
        // Public member variable to store the player's position
        Vector2f pos;
    private:
    // Private member variables
        // Size of the player icon
        int size;
        // Speed at which the player moves
        float speed;
        // Pointer to the player's icon
        Vector3i* icon;
        // Half of the screen width
        float halfScrwidth;
        // Half of the screen height
        float halfScrheight;
        // Half of the player's size
        float halfSize;
        // Pointer to the player's hitbox array
        Vector2f* hitbox;
        // Field of view for the player
        Vector2i fov;
};
