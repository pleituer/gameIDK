#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>

#include "maze.h"
#include "screen.h"
#include "sleep.h"

// Define color constants
const Vector3i& white = Vector3i(255, 255, 255);
const Vector3i& black = Vector3i(0, 0, 0);
const Vector3i& red = Vector3i(255, 0, 0);
const Vector3i& yellow = Vector3i(255, 255, 0);
const Vector3i& green = Vector3i(0, 255, 0);

using namespace std;

// Check if given position (posX, posY) is within maze bounds
bool Maze::allowed(int posX, int posY) {
    if (posX > -1 && posY > -1 && posX < width && posY < height) {return true;}
    else {return false;}
}

// Constructor for the Maze class
Maze::Maze(int width, int height, Screen& scr, Vector2f pos, bool ShowAnimation) {
    this->width = width;
    this->height = height;
    cellSize = 5;
    
    // Initialize starting position
    int startPos = width*(rand()%(height/2))*2;
    world = new int[width*height];
    vector<int> frontiers;
    vector<int> neighbors;
    vector<int> temp;
    frontiers.clear();
    neighbors.clear();
    
    // Set all cells to state Blocked (1)
    for (int i = 0; i < width*height; ++i) {world[i] = 1;}
    world[startPos] = 0;
    
    // Compute frontier cells for starting position
    int sY = startPos/width;
    startingPoint = Vector2i(0, sY);
    if (allowed(0, sY-2) && getCell(0, sY-2)==1) {frontiers.push_back(startPos-2*width);}
    if (allowed(2, sY) && getCell(2, sY)==1) {frontiers.push_back(startPos+2);}
    if (allowed(0, sY+2) && getCell(0, sY+2)==1) {frontiers.push_back(startPos+2*width);}
    
    // Randomized Prim's Algorithm for maze generation
    while (!frontiers.empty()) {
        temp.clear();
        if (ShowAnimation){
            scr.display();
            scr.moveUp();
        }
        neighbors.clear();
        
        // Pick a random frontier cell
        int randomCellIndex = rand() % frontiers.size();
        int randomCell = frontiers[randomCellIndex];
        int X = randomCell%width, Y = randomCell/width;
        
        // Add neighbors of the chosen frontier cell
        if (allowed(X-2, Y)) {getCell(X-2, Y)==0?neighbors.push_back(randomCell-2):frontiers.push_back(randomCell-2);}
        if (allowed(X, Y-2)) {getCell(X, Y-2)==0?neighbors.push_back(randomCell-2*width):frontiers.push_back(randomCell-2*width);}
        if (allowed(X+2, Y)) {getCell(X+2, Y)==0?neighbors.push_back(randomCell+2):frontiers.push_back(randomCell+2);}
        if (allowed(X, Y+2)) {getCell(X, Y+2)==0?neighbors.push_back(randomCell+2*width):frontiers.push_back(randomCell+2*width);}
        int selectedCellIndex = rand() % neighbors.size();
        int selectedCell = neighbors[selectedCellIndex];
        int centerCell = (randomCell + selectedCell)/2;
        world[centerCell] = 0;
        world[randomCell] = 0;
        // Display the animation if enabled
        if (ShowAnimation) {
            display(scr, pos);
            scr.setPixel(X+pos.x, Y+pos.y, red);
            scr.setPixel(selectedCell%width +pos.x,selectedCell/width + pos.y, yellow);
            scr.setPixel(Vector2i(0, sY)+pos, green);
        }
        // Update the list of frontier cells
        for (vector<int>::iterator it = frontiers.begin(); it < frontiers.end(); ++it) {if (world[*it] == 1) {temp.push_back(*it);}}
        frontiers = temp;
        // Add a small delay for the animation
        if (ShowAnimation) {sleeps(0.03f);}
    }
    // Set the ending point
    temp.clear();
    for (int row = 0; row < height; ++row) {if (getCell(width-1, row) == 0) {temp.push_back(row);}}
    endingPoint = Vector2i(width-1, temp[rand() % temp.size()]);
    // Update the starting and ending points
    world[startPos] = 2;
    world[endingPoint.x + endingPoint.y*width] = 3;
    // Update the cell states based on surrounding cells
    for (int i = 0; i < height*width; ++i) {
        int x = i%width, y = i/width;
        if (world[i] == 1) {
            world[i] = 4;
            if (allowed(x + 1, y) && (world[i+1] == 1 || (getCell(x+1, y) > 3 && getCell(x+1, y) < 20))) {world[i] += 1;}
            if (allowed(x, y + 1) && (world[i+width] == 1 || (getCell(x, y+1) > 3 && getCell(x, y+1) < 20))) {world[i] += 2;}
            if (allowed(x - 1, y) && (world[i-1] == 1 || (getCell(x-1, y) > 3 && getCell(x-1, y) < 20))) {world[i] += 4;}
            if (allowed(x, y - 1) && (world[i-width] == 1 || (getCell(x, y-1) > 3 && getCell(x, y-1) < 20))) {world[i] += 8;}
        }
    }
} 

/*
A Grid consists of a 2 dimensional array of cells.
A Cell has 2 states: Blocked or Passage.
Start with a Grid full of Cells in state Blocked.
Pick a random Cell, set it to state Passage and Compute its frontier cells. A frontier cell of a Cell is a cell with distance 2 in state Blocked and within the grid.
While the list of frontier cells is not empty:
Pick a random frontier cell from the list of frontier cells.
Let neighbors(frontierCell) = All cells in distance 2 in state Passage. Pick a random neighbor and connect the frontier cell with the neighbor by setting the cell in-between to state Passage. Compute the frontier cells of the chosen frontier cell and add them to the frontier list. Remove the chosen frontier cell from the list of frontier cells.
*/

void Maze::display(Screen& scr, Vector2f& pos, PPMFile& texture, Vector2i* startPos, Vector2i* endPos, Vector2i& startCell, Vector2i& endCell) {
    for (int row = startCell.y; row < endCell.y; ++row) {
        for (int column = startCell.x; column < endCell.x; ++column) {
            if (-1 < column && column < width && -1 < row && row < height) {
                int cellID = getCell(column, row);
                Vector2i start = startPos[cellID];
                Vector2i end = endPos[cellID];
                Vector2f cellPos = pos + Vector2f((column-startCell.x)*cellSize, (row-startCell.y)*cellSize);
                scr.renderImg(texture, start, end, cellPos);
            }
        }
    }
}

// Display the maze using colors
void Maze::display(Screen& scr, Vector2f& pos) {
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            if (getCell(column, row) == 1) {scr.setPixel(pos.x+column, pos.y+row, white);}
            else {scr.setPixel(pos.x+column, pos.y+row, black);}
        }
    }
}

void Maze::setMarker(Vector2f& pos) {if (world[int(pos.x/cellSize) + int(pos.y/cellSize)*width] == 0) {world[int(pos.x/cellSize) + int(pos.y/cellSize)*width] = 1;}}

void Maze::rmMarker(Vector2f& pos) {if (world[int(pos.x/cellSize) + int(pos.y/cellSize)*width] == 1) {world[int(pos.x/cellSize) + int(pos.y/cellSize)*width] = 0;}}

int Maze::getWidth() {return width;}

int Maze::getHeight() {return height;}

int Maze::getCell(int x, int y) {return world[x + y*width];}

bool Maze::isNotWall(Vector2f& pos) {
    int cell = getCell(int(pos.x/cellSize), int(pos.y/cellSize));
    return !(cell > 3 && cell < 20);
}

bool Maze::isNotWall(const Vector2f& pos) {
    int cell = getCell(int(pos.x/cellSize), int(pos.y/cellSize));
    return !(cell > 3 && cell < 20);
}
