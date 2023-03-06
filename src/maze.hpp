#pragma once

#include "helpers.hpp"
#include "screen.hpp"

class Maze {
    public:
        Maze(int width, int height, Screen& scr, Vector2f pos, bool ShowAnimation);
        void display(Screen& scr, Vector2f& pos);
        int getWidth();
        int getCell(int x, int y);
        Vector2i startingPoint;
        Vector2i endingPoint;
    private:
        int height=0, width=0;
        int* world;
        bool allowed(int posX, int posY);
};