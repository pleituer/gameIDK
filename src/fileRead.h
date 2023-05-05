#pragma once

// Include necessary libraries
#include <cstring>

#include "helpers.h"

// Define the PPMFile class to handle PPM files
class PPMFile {
    public:
        // Constructor to read and process a PPM file from disk
        PPMFile(const char* filename);
        // Default constructor
        PPMFile();
        // Getter methods for PPM file properties
        
        // Get the PPM file type (P3 or P6)
        int getType();
        // Get the height of the image
        int getHeight();
        // Get the width of the image
        int getWidth();
        // Get the image data as an array of Vector3i
        Vector3i* getImg();
        
    private:
        // Flag to indicate if the file is readable
        bool readable;
        // The size of the file in bytes
        size_t size;
        // The type of the PPM file (P3 or P6)
        int PPMType;
        // The dimensions of the image
        int height = 0, width = 0;
        // Pointer to an array of Vector3i to store the image data
        Vector3i* Img;
};
