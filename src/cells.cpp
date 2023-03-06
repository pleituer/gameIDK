#include "cells.hpp"
#include "helpers.hpp"
#include "fileRead.hpp"

Air::Air(Vector2f& pos, Vector3i* src, Vector2i& start, Vector2i& end) {
    this->pos = pos;
    size = end - start;
    texture = new Vector3i[size.x * size.y];
    for (int row = 0; row < size.y; ++row) {
        for (int column = 0; column < size.x; ++column) {
            texture[column + row*size.x] = src[(column + start.x) + (row + start.y)*size.y];
        }
    }
    corners = new Vector2f[8];
}

Air::Air(Air& src) {
    this->pos = src.pos;
    this->size = src.size;
    this->texture = src.texture;
}

Vector2f* Air::getCorners() {return corners;}

Wall::Wall(Vector2f& pos, Vector3i* src, Vector2i& start, Vector2i& end) {
    this->pos = pos;
    size = end - start;
    texture = new Vector3i[size.x * size.y];
    for (int row = 0; row < size.y; ++row) {
        for (int column = 0; column < size.x; ++column) {
            texture[column + row*size.x] = src[(column + start.x) + (row + start.y)*size.y];
        }
    }
    corners = new Vector2f[8];
}

Wall::Wall(Wall& src) {
    this->pos = src.pos;
    this->size = src.size;
    this->texture = src.texture;
}

Vector2f* Wall::getCorners() {return corners;}