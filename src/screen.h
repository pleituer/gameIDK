// The #pragma once directive ensures that this header file is included only once in a compilation unit
// to prevent duplicate declarations and definitions.
#pragma once

// Include necessary header files.
#include "helpers.h"
#include "fileRead.h"

// Declare the Screen class.
class Screen {
    public:
        // Constructor that initializes the screen width and height.
        Screen(int p_width, int p_height);
        // Initializes the screen by setting all pixels to black.
        void Init();
        // Frees up any memory used by the screen
        void Done();
        // Returns the screen height.
        int getHeight();
        // Returns the screen width.
        int getWidth();
        // Returns a reference to the pixel at the given (x, y) integer coordinates.
        Vector3i& getPixel(int x, int y);
        // Returns a reference to the pixel at the given (x, y) floating-point coordinates.
        Vector3i& getPixel(float x, float y);
        // Sets the pixel at the given (x, y) integer coordinates to the given color.
        void setPixel(int x, int y, const Vector3i& pixel);
        // Sets the pixel at the given (x, y) floating-point coordinates to the given color.
        void setPixel(float x, float y, const Vector3i& pixel);
        // Sets the pixel at the given integer vector position to the given color.
        void setPixel(Vector2i& pos, const Vector3i& pixel);
        // Sets the pixel at the given floating-point vector position to the given color.
        void setPixel(Vector2f& pos, const Vector3i& pixel);
        // Sets the pixel at the given integer vector position to the given color.
        void setPixel(const Vector2i& pos, const Vector3i& pixel);
        // Sets the pixel at the given floating-point vector position to the given color.
        void setPixel(const Vector2f& pos, const Vector3i& pixel);
        // Sets the border of the screen to the given color.
        void setBoarders(const Vector3i& color);
        // Draws a horizontal line from startX to endX at the given y-coordinate with the given color.
        void drawHorizontalLine(float startX, float endX, float y, const Vector3i& color);
        // Draws a vertical line from startY to endY at the given x-coordinate with the given color.
        void drawVerticalLine(float x, float startY, float endY, const Vector3i& color);
        // Draws a rectangle from the given start and end coordinates with the given color, overwriting any pixels in its path.
        void drawExclusiveRectangle(Vector2i start, Vector2i end, const Vector3i &color);
        // Draws a rectangle from the given start and end coordinates with the given color, overwriting any pixels in its path.
        void drawExclusiveRectangle(int startX, int endX, int startY, int endY, const Vector3i& color);
        // Draws a line from the given start and end coordinates with the given color, using a naive method that may not be very precise.
        void drawLineNaive(Vector2f& start, Vector2f& end, const Vector3i& color, float precision);
        // Draws a line from the given start and end coordinates with the given color, using a more precise method.
        void drawLine(Vector2f& start, Vector2f& end, const Vector3i& color);
        void drawCircle(Vector2f& center, float radius, const Vector3i& color);
        // Renders an image from a PPM file onto the screen, starting from the given start and end coordinates and positioned at the given position.
        void renderImg(PPMFile& src, Vector2i& start, Vector2i& end, Vector2f& pos);
        // Renders an image from a pixel array onto the screen, starting from the given start and end coordinates and positioned at the given position, using the given width.
        void renderImg(Vector3i* src, Vector2i& start, Vector2i& end, Vector2f& pos, int width);
        // Displays the current contents of the screen.
        void display();
        // Clears the screen by setting all pixels to black.
        void clear();
        // Scrolls the screen up by one row, shifting all pixels up by one row and filling in the bottom row with black.
        void moveUp();
    private:
        int width;
        int height;
        // A pointer to the screen's pixel array.
        Vector3i* screen;
        // Draws a line with a low slope between the given start and end coordinates with the given color.
        void LineLow(Vector2f& start, Vector2f& end, const Vector3i& color);
        // Draws a line with a high slope between the given start and end coordinates with the given color.
        void LineHigh(Vector2f& start, Vector2f& end, const Vector3i& color);
};
