#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>

#include "screen.hpp"
#include "helpers.hpp"
#include "fileRead.hpp"

using namespace std;

Screen::Screen(int p_width, int p_height) {
    width = p_width;
    height = p_height;
    screen = new Vector3i[width * height];
    system("cls");
}

void Screen::Init() {cout << "\x1b[?25l";}

void Screen::Done() {cout << "\x1b[?25h";}

int Screen::getHeight() {return height;}

int Screen::getWidth() {return width;}

Vector3i& Screen::getPixel(int x, int y) {return screen[x + y*width];}

Vector3i& Screen::getPixel(float x, float y) {return screen[int(round(x)) + int(round(y))*width];}

void Screen::setPixel(int x, int y, const Vector3i& pixel) {
    if(x>-1 && y>-1 && x<width && y<height) {screen[x + y*width] = pixel;}
}

void Screen::setPixel(float x, float y, const Vector3i& pixel) {
    int X = int(round(x)), Y = int(round(y));
    if(X>-1 && Y>-1 && X<width && Y<height) {screen[X + Y*width] = pixel;}
}

void Screen::setPixel(Vector2i& pos, const Vector3i& pixel) {
    if(pos.x>-1 && pos.y>-1 && pos.x<width && pos.y<height) {screen[pos.x + pos.y*width] = pixel;}
}

void Screen::setPixel(Vector2f& pos, const Vector3i& pixel) {
    int X = int(round(pos.x)), Y = int(round(pos.y));
    if(X>-1 && Y>-1 && X<width && Y<height) {screen[X + Y*width] = pixel;}
}

void Screen::setPixel(const Vector2i& pos, const Vector3i& pixel) {
    if(pos.x>-1 && pos.y>-1 && pos.x<width && pos.y<height) {screen[pos.x + pos.y*width] = pixel;}
}

void Screen::setPixel(const Vector2f& pos, const Vector3i& pixel) {
    int X = int(round(pos.x)), Y = int(round(pos.y));
    if(X>-1 && Y>-1 && X<width && Y<height) {screen[X + Y*width] = pixel;}
}

void Screen::setBoarders(const Vector3i& color) {
    for (int column = 0; column < width; ++column) {
        setPixel(column, 0, color);
        setPixel(column, height-1, color);
    }
    for (int row = 0; row < height; ++row) {
        setPixel(0, row, color);
        setPixel(width-1, row, color);
    }
}

void Screen::drawHorizontalLine(float startX, float endX, float y, const Vector3i& color) {
    if (startX < endX) {for (float x = startX; x < endX; ++x) {setPixel(x, y, color);}}
    else {for (float x = startX; x > endX; --x) {setPixel(x, y, color);}}
}

void Screen::drawVerticalLine(float x, float startY, float endY, const Vector3i& color) {
    if (startY < endY) {for (float y = startY; y < endY; ++y) {setPixel(x, y, color);}}
    else  {for (float y = startY; y > endY; --y) {setPixel(x, y, color);}}
}

void Screen::drawLineNaive(Vector2f& start, Vector2f& end, const Vector3i& color, float precision) {
    if (start != end) {
        float delX = end.x - start.x;
        float delY = end.y - start.y;
        float vectorlen = sqrt(pow(delX,2) + pow(delY, 2));
        Vector2f dir = Vector2f(delX/vectorlen, delY/vectorlen);
        for (float len = 0; len < vectorlen+precision; len+=precision) {
            setPixel(start.x + len*dir.x, start.y + len*dir.y, color);
        }
    }
}

void Screen::LineLow(Vector2f& start, Vector2f& end, const Vector3i& color) {
    float dx = end.x - start.x;
    float dy = end.y - start.y;
    int yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    float D = (2 * dy) - dx;
    float y = start.y;
    for (float x = start.x; x < end.x; ++x) {
        setPixel(x, y, color);
        if (D > 0) {
            y += yi;
            D += (2 * (dy - dx));
        } else {
            D += 2*dy;
        }
    }
}

void Screen::LineHigh(Vector2f& start, Vector2f& end, const Vector3i& color) {
    float dx = end.x - start.x;
    float dy = end.y - start.y;
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    float D = (2 * dx) - dy;
    float x = start.x;
    for (float y = start.y; y < end.y; ++y) {
        setPixel(x, y, color);
        if (D > 0) {
            x += xi;
            D += (2 * (dx - dy));
        } else {
            D += 2*dx;
        }
    }
}

void Screen::drawLine(Vector2f& start, Vector2f& end, const Vector3i& color) {
    if (start == end) {return;}
    else if (start.x == end.x) {drawVerticalLine(start.x, start.y, end.y, color);}
    else if (start.y == end.y) {drawHorizontalLine(start.x, end.x, start.y, color);}
    else if (abs(end.y - start.y) < abs(end.x - start.x)) {
        if (start.x > end.x) {LineLow(end, start, color);}
        else {LineLow(start, end, color);}
    } else {
        if (start.y > end.y) {LineHigh(end, start, color);}
        else {LineHigh(start, end, color);}
    }
}

void Screen::drawCircle(Vector2f& center, float radius, const Vector3i& color) {
    float x = radius, y = 0.0f;
    setPixel(x + center.x, y + center.y, color);
    if (radius > 0) {
        setPixel(-x + center.x, y + center.y, color);
        setPixel(y + center.x, x + center.y, color);
        setPixel(y + center.x, -x + center.y, color);
    }
    float P = 1 - radius;
    while (x > y) {
        y++;
        if (P <= 0) {P = P + 2*y + 1;}
        else {
            x--;
            P = P + 2*y - 2*x + 1;
        }
        if (x < y) {break;}
        setPixel(x + center.x, y + center.y, color);
        setPixel(-x + center.x, y + center.y, color);
        setPixel(x + center.x, -y + center.y, color);
        setPixel(-x + center.x, -y + center.y, color);
        if (x != y) {
            setPixel(y + center.x, x + center.y, color);
            setPixel(-y + center.x, x + center.y, color);
            setPixel(y + center.x, -x + center.y, color);
            setPixel(-y + center.x, -x + center.y, color);
        }
    }
}

void Screen::renderImg(PPMFile& src, Vector2i& start, Vector2i& end, Vector2f& pos) {
    for (int row = 0; row < end.y - start.y; ++row) {
        for (int column = 0; column < end.x - start.x; ++column) {
            setPixel(pos.x + column, pos.y + row, src.getImg()[(row + start.y)*src.getWidth() + column + start.x]);
        }
    }
}

void Screen::display() {
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            Vector3i pixel = getPixel(column, row);
            string pix = "\x1b[48;2;" + to_string(pixel.x) + ";" + to_string(pixel.y) + ";" + to_string(pixel.z) + "m  ";
            cout << pix;
        }
        cout << "\x1b[0m\n";
    }
}

void Screen::clear() {
    for (int i = 0; i < width*height; ++i) {screen[i] = Vector3i(0,0,0);}
    system("cls");
}

void Screen::moveUp() {
    for (int i = 0; i < width*height; ++i) {screen[i] = Vector3i(0,0,0);}
    string up = "\x1b[" + to_string(height) + "A";
    cout << up;
}