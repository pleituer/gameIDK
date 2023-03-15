#pragma once

#include "helpers.h"
#include "screen.h"
#include "fileRead.h"

class Maze {
    public:
        Maze(int width, int height, Screen& scr, Vector2f pos, bool ShowAnimation);
        void display(Screen& scr, Vector2f& pos, PPMFile& texture, Vector2i* startPos, Vector2i* endPos, Vector2i& startCell, Vector2i& endCell);
        void display(Screen& scr, Vector2f& pos);
        void setMarker(Vector2f& pos);
        void rmMarker(Vector2f& pos);
        int getWidth();
        int getHeight();
        int getCell(int x, int y);
        bool isNotWall(Vector2f& pos);
        bool isNotWall(const Vector2f& pos);
        Vector2i startingPoint;
        Vector2i endingPoint;
        int cellSize;
    private:
        int height=0, width=0;
        int* world;
        bool allowed(int posX, int posY);
};