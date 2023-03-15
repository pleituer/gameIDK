#pragma once

#include <cstring>

#include "helpers.h"

class PPMFile {
    public:
        PPMFile(const char* filename);
        int getType();
        int getHeight();
        int getWidth();
        Vector3i* getImg();
    private:
        size_t size;
        int PPMType;
        int height = 0, width = 0;
        Vector3i* Img;
};