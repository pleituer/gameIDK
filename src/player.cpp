#include <iostream>
#include <cmath>

#include "player.h"
#include "helpers.h"
#include "screen.h"
#include "maze.h"
#include "input.h"
#include "fileRead.h"

using namespace std;

Player::Player(Maze& mz, Screen& scr) {
    speed = 1.0f;
    size = 3;
    pos = Vector2f(float(mz.cellSize)/2 + 1, mz.startingPoint.y*mz.cellSize + float(mz.cellSize)/2);
    halfScrwidth = float(scr.getWidth())/2;
    halfScrheight = float(scr.getHeight())/2;
    halfSize = size/2;
    hitbox = new Vector2f[4] {Vector2f(halfSize, halfSize), Vector2f(-halfSize, halfSize), Vector2f(halfSize, -halfSize), Vector2f(-halfSize, -halfSize)};
    fov = Vector2i(16, 12);
}

void Player::update(int key, Maze& mz) {
    Vector2f curPos = pos;
    switch (key) {
    case K_w:
    case K_W:
    case K_UP:
        curPos.y -= speed;
        break;
    case K_s:
    case K_S:
    case K_DOWN:
        curPos.y +=speed;
        break;
    case K_a:
    case K_A:
    case K_LEFT:
        curPos.x -= speed;
        break;
    case K_d:
    case K_D:
    case K_RIGHT:
        curPos.x += speed;
        break;
    case K_x:
    case K_X:
        mz.setMarker(pos);
        break;
    case K_y:
    case K_Y:
        mz.rmMarker(pos);
        break;
    }
    if (mz.isNotWall(curPos + hitbox[0]) && mz.isNotWall(curPos + hitbox[1]) && mz.isNotWall(curPos + hitbox[2]) && mz.isNotWall(curPos + hitbox[3]) && curPos.x - float(size)/2 > 0 && curPos.x + float(size)/2 < mz.getWidth()*mz.cellSize && curPos.y - float(size)/2 > 0 && curPos.y + float(size)/2 < mz.getHeight()*mz.cellSize) {pos = curPos;}
}

void Player::display(Screen& scr, Maze& mz, PPMFile& icon, PPMFile& texture, Vector2i* startPos, Vector2i* endPos, Vector2f mazeStart) {
    Vector2i start = Vector2i(0, 0);
    Vector2i end = Vector2i(size, size);
    Vector2f renderPos;
    Vector2i startCell;
    if (pos.x < halfScrwidth) {renderPos.x = pos.x;startCell.x = 0;}
    else if (mz.getWidth()*mz.cellSize - pos.x < halfScrwidth) {renderPos.x = 2*halfScrwidth - mz.getWidth()*mz.cellSize + pos.x;startCell.x = mz.getWidth() - fov.x;}
    else {renderPos.x = halfScrwidth;startCell.x = int(pos.x)/mz.cellSize - fov.x/2;mazeStart.x -= int(pos.x)%mz.cellSize;}
    renderPos.x -= float(size)/2;
    if (pos.y < halfScrheight) {renderPos.y = pos.y;startCell.y = 0;}
    else if (mz.getHeight()*mz.cellSize - pos.y < halfScrheight) {renderPos.y = 2*halfScrheight - mz.getHeight()*mz.cellSize + pos.y;startCell.y = mz.getHeight() - fov.y;}
    else {renderPos.y = halfScrheight;startCell.y = int(pos.y)/mz.cellSize - fov.y/2;mazeStart.y -= int(pos.y)%mz.cellSize;}
    renderPos.y -= float(size)/2;
    Vector2i endCell = startCell + Vector2i(fov.x+1, fov.y+1);
    mz.display(scr, mazeStart, texture, startPos, endPos, startCell, endCell);
    scr.renderImg(icon, start, end, renderPos);
}