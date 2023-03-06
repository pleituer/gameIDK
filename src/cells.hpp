#pragma once

#include "helpers.hpp"
#include "fileRead.hpp"

class Air {
    public:
        Air(Vector2f& pos, Vector3i* src, Vector2i& start, Vector2i& end);
        Air(Air& src);
        Vector2f* getCorners();
    private:
        int id = 0;
        Vector2f pos;
        Vector2i size;
        Vector3i* texture;
        Vector2f* corners;
};

class Wall {
    public:
        Wall(Vector2f& pos, Vector3i* src, Vector2i& start, Vector2i& end);
        Wall(Wall& src);
        Vector2f* getCorners();
    private:
        int id = 1;
        Vector2f pos;
        Vector2i size;
        Vector3i* texture;
        Vector2f* corners;
};