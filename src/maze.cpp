#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <Windows.h>

#include "maze.hpp"
#include "screen.hpp"

const Vector3i& white = Vector3i(255, 255, 255);
const Vector3i& black = Vector3i(0, 0, 0);
const Vector3i& red = Vector3i(255, 0, 0);
const Vector3i& yellow = Vector3i(255, 255, 0);
const Vector3i& green = Vector3i(0, 255, 0);

using namespace std;

bool Maze::allowed(int posX, int posY) {
    if (posX > -1 && posY > -1 && posX < width && posY < height) {return true;}
    else {return false;}
}

Maze::Maze(int width, int height, Screen& scr, Vector2f pos, bool ShowAnimation) {
    srand(time(NULL));
    this->width = width;
    this->height = height;
    int startPos = width*(rand()%(height/2))*2;
    world = new int[width*height];
    vector<int> frontiers;
    vector<int> neighbors;
    vector<int> temp;
    frontiers.clear();
    neighbors.clear();
    for (int i = 0; i < width*height; ++i) {world[i] = 1;}
    world[startPos] = 0;
    int sY = startPos/width;
    startingPoint = Vector2i(0, sY);
    if (allowed(0, sY-2) && getCell(0, sY-2)==1) {frontiers.push_back(startPos-2*width);}
    if (allowed(2, sY) && getCell(2, sY)==1) {frontiers.push_back(startPos+2);}
    if (allowed(0, sY+2) && getCell(0, sY+2)==1) {frontiers.push_back(startPos+2*width);}
    while (!frontiers.empty()) {
        temp.clear();
        if (ShowAnimation){
            scr.display();
            scr.moveUp();
        }
        neighbors.clear();
        int randomCellIndex = rand() % frontiers.size();
        int randomCell = frontiers[randomCellIndex];
        int X = randomCell%width, Y = randomCell/width;
        if (allowed(X-2, Y)) {getCell(X-2, Y)==0?neighbors.push_back(randomCell-2):frontiers.push_back(randomCell-2);}
        if (allowed(X, Y-2)) {getCell(X, Y-2)==0?neighbors.push_back(randomCell-2*width):frontiers.push_back(randomCell-2*width);}
        if (allowed(X+2, Y)) {getCell(X+2, Y)==0?neighbors.push_back(randomCell+2):frontiers.push_back(randomCell+2);}
        if (allowed(X, Y+2)) {getCell(X, Y+2)==0?neighbors.push_back(randomCell+2*width):frontiers.push_back(randomCell+2*width);}
        int selectedCellIndex = rand() % neighbors.size();
        int selectedCell = neighbors[selectedCellIndex];
        int centerCell = (randomCell + selectedCell)/2;
        world[centerCell] = 0;
        world[randomCell] = 0;
        if (ShowAnimation) {
            display(scr, pos);
            scr.setPixel(X+pos.x, Y+pos.y, red);
            scr.setPixel(selectedCell%width +pos.x,selectedCell/width + pos.y, yellow);
            scr.setPixel(Vector2i(0, sY)+pos, green);
        }
        for (vector<int>::iterator it = frontiers.begin(); it < frontiers.end(); ++it) {if (world[*it] == 1) {temp.push_back(*it);}}
        frontiers = temp;
        if (ShowAnimation) {Sleep(3);}
    }
    temp.clear();
    for (int row = 0; row < height; ++row) {if (getCell(width-1, row) == 0) {temp.push_back(row);}}
    endingPoint = Vector2i(width-1, temp[rand() % temp.size()]);
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

void Maze::display(Screen& scr, Vector2f& pos) {
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            if (getCell(column, row) == 1) {scr.setPixel(pos.x+column, pos.y+row, white);}
            else {scr.setPixel(pos.x+column, pos.y+row, black);}
        }
    }
}

int Maze::getWidth() {return width;}

int Maze::getCell(int x, int y) {return world[x + y*width];}