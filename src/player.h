#pragma once

#include "helpers.h"
#include "screen.h"
#include "maze.h"
#include "fileRead.h"

class Player {
    public:
        Player(Maze& mz, Screen& scr);
        void update(int key, Maze& mz);
        void display(Screen& scr, Maze& mz, PPMFile& icon, PPMFile& texture, Vector2i* startPos, Vector2i* endPos, Vector2f mazeStart);
        bool solvedOrNot(Maze& mz);
        Vector2f pos;
    private:
        int size;
        float speed;
        Vector3i* icon;
        float halfScrwidth;
        float halfScrheight;
        float halfSize;
        Vector2f* hitbox;
        Vector2i fov;
};