#pragma once

#include "helpers.h"
#include "fileRead.h"

class Screen {
    public:
        Screen(int p_width, int p_height);
        void Init();
        void Done();
        int getHeight();
        int getWidth();
        Vector3i& getPixel(int x, int y);
        Vector3i& getPixel(float x, float y);
        void setPixel(int x, int y, const Vector3i& pixel);
        void setPixel(float x, float y, const Vector3i& pixel);
        void setPixel(Vector2i& pos, const Vector3i& pixel);
        void setPixel(Vector2f& pos, const Vector3i& pixel);
        void setPixel(const Vector2i& pos, const Vector3i& pixel);
        void setPixel(const Vector2f& pos, const Vector3i& pixel);
        void setBoarders(const Vector3i& color);
        void drawHorizontalLine(float startX, float endX, float y, const Vector3i& color);
        void drawVerticalLine(float x, float startY, float endY, const Vector3i& color);
        void drawLineNaive(Vector2f& start, Vector2f& end, const Vector3i& color, float precision);
        void drawLine(Vector2f& start, Vector2f& end, const Vector3i& color);
        void drawCircle(Vector2f& center, float radius, const Vector3i& color);
        void renderImg(PPMFile& src, Vector2i& start, Vector2i& end, Vector2f& pos);
        void renderImg(Vector3i* src, Vector2i& start, Vector2i& end, Vector2f& pos, int width);
        void display();
        void clear();
        void moveUp();
    private:
        int width;
        int height;
        Vector3i* screen;
        void LineLow(Vector2f& start, Vector2f& end, const Vector3i& color);
        void LineHigh(Vector2f& start, Vector2f& end, const Vector3i& color);
};