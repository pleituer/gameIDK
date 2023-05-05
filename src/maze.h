// Include header guards to prevent multiple inclusions
#pragma once

// Include necessary header files
#include "helpers.h"
#include "screen.h"
#include "fileRead.h"

// Declare the Maze class
class Maze {
    public:
        // Constructor for the Maze class
        Maze(int width, int height, Screen& scr, Vector2f pos, bool ShowAnimation);
        // Display the maze using textures, taking in references to a Screen object,
        // a position vector, a PPMFile object for the texture, pointers to startPos and
        // endPos arrays, and references to startCell and endCell
        void display(Screen& scr, Vector2f& pos, PPMFile& texture, Vector2i* startPos, Vector2i* endPos, Vector2i& startCell, Vector2i& endCell);
        // Display the maze without textures, taking in a reference to a Screen object and a position vector
        void display(Screen& scr, Vector2f& pos);
        // Set a marker at the specified position
        void setMarker(Vector2f& pos);
        // Remove a marker at the specified position
        void rmMarker(Vector2f& pos);
        // Get the width of the maze
        int getWidth();
        // Get the height of the maze
        int getHeight();
        // Get the cell value at the specified (x, y) coordinate
        int getCell(int x, int y);
        // Check if the specified position is not a wall
        bool isNotWall(Vector2f& pos);
        // Check if the specified position is not a wall (const version)
        bool isNotWall(const Vector2f& pos);
        // Public member variables for starting and ending points of the maze
        Vector2i startingPoint;
        Vector2i endingPoint;
        // Public member variable for the size of each cell in the maze
        int cellSize;
    private:
        // Private member variables for the height and width of the maze
        int height=0, width=0;
        // Private member variable for the maze's world array (representing cells)
        int* world;
        // Private helper function to check if the specified position is allowed (within maze bounds)
        bool allowed(int posX, int posY);
};
