// Include the standard input/output library
#include <iostream>
// Include the math library
#include <cmath>

// Include the custom header for player class
// Include the custom header for helper functions
// Include the custom header for screen manipulation
// Include the custom header for maze generation and display
// Include the custom header for handling user input
// Include the custom header for reading files
#include "player.h"
#include "helpers.h"
#include "screen.h"
#include "maze.h"
#include "input.h"
#include "fileRead.h"

using namespace std;

// Player class constructor definition
Player::Player(Maze& mz, Screen& scr) {
    // Set player's speed
    speed = 1.0f;
    // Set player's size
    size = 3;
    // Set player's initial position
    pos = Vector2f(float(mz.cellSize)/2 + 1, mz.startingPoint.y*mz.cellSize + float(mz.cellSize)/2);
    // Calculate half of the screen width
    halfScrwidth = float(scr.getWidth())/2;
    // Calculate half of the screen height
    halfScrheight = float(scr.getHeight())/2;
    // Calculate half of the player's size
    halfSize = size/2;
    // Initialize player's hitbox with four corner points
    hitbox = new Vector2f[4] {Vector2f(halfSize, halfSize), Vector2f(-halfSize, halfSize), Vector2f(halfSize, -halfSize), Vector2f(-halfSize, -halfSize)};
    fov = Vector2i(16, 12);
}

// Function to update the player's position based on user input
void Player::update(int key, Maze& mz) {
    // Store the current position of the player
    Vector2f curPos = pos;
    // Handle user input for movement and actions
    switch (key) {
    case K_w:
    case K_W:
    case K_UP:
    // Move player up
        curPos.y -= speed;
        break;
    case K_s:
    case K_S:
    case K_DOWN:
    // Move player down
        curPos.y +=speed;
        break;
    case K_a:
    case K_A:
    case K_LEFT:
     // Move player left
        curPos.x -= speed;
        break;
    case K_d:
    case K_D:
    case K_RIGHT:
    // Move player right
        curPos.x += speed;
        break;
    case K_x:
    case K_X:
        // Set a marker at the player's position
        mz.setMarker(pos);
        break;
    case K_y:
    case K_Y:
        // Remove a marker at the player's position
        mz.rmMarker(pos);
        break;
    }
    // Check if the new position is valid (not inside a wall)
    if (mz.isNotWall(curPos + hitbox[0]) && mz.isNotWall(curPos + hitbox[1]) && mz.isNotWall(curPos + hitbox[2]) && mz.isNotWall(curPos + hitbox[3]) && curPos.x - float(size)/2 > 0 && curPos.x + float(size)/2 < mz.getWidth()*mz.cellSize && curPos.y - float(size)/2 > 0 && curPos.y + float(size)/2 < mz.getHeight()*mz.cellSize) {pos = curPos;}
}

// Function to display the player and the maze on the screen
void Player::display(Screen& scr, Maze& mz, PPMFile& icon, PPMFile& texture, Vector2i* startPos, Vector2i* endPos, Vector2f mazeStart) {
    // Initialize the starting point for rendering the player icon
    Vector2i start = Vector2i(0, 0);
    // Initialize the end point for rendering the player icon
    Vector2i end = Vector2i(size, size);
    // Initialize the render position for the player
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
     // Calculate the end cell for the maze rendering
    Vector2i endCell = startCell + Vector2i(fov.x+1, fov.y+1);
    // Display the maze on the screen
    mz.display(scr, mazeStart, texture, startPos, endPos, startCell, endCell);
    // Render the player's icon on the screen
    scr.renderImg(icon, start, end, renderPos);
}

// Function to check if the player has reached the end of the maze
bool Player::solvedOrNot(Maze& mz) {
    return (int(pos.x/mz.cellSize) == mz.endingPoint.x && int(pos.y/mz.cellSize) == mz.endingPoint.y);
}
