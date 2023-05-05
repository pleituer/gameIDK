// Include necessary libraries
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

// Include custom headers
#include "fileRead.h"
#include "helpers.h"

using namespace std;

// Constructor to read and process a PPM file from disk
PPMFile::PPMFile(const char* filename) {
    ifstream file;
    // Open the file in binary mode and set the file pointer to the end
    file.open(filename, ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
        cout << "processing " << filename << endl;
        file.seekg(0, ios::end);
        // Get the file size
        size = file.tellg();
        file.seekg(0, ios::beg);
        cout << "ppm size " << size << endl;

        // Create a buffer to read the entire file into memory
        char* data = new char[size];
        file.read(data, size);
        file.close();

        // Initialize the pointer to read the width, height, and max pixel value
        int ptr = 2;
        // Read the width
        while (data[ptr] < '0' || data[ptr] > '9') {ptr++;}
        while (data[ptr] >= '0' && data[ptr] <= '9') {
            width = width*10 + int(data[ptr]) - 48;
            ptr++;
        }

        // Read the height
        while (data[ptr] < '0' || data[ptr] > '9') {ptr++;}
        while (data[ptr] >= '0' && data[ptr] <= '9') {
            height = height*10 + data[ptr] - 48;
            ptr++;
        }

        // Read the max pixel value
        while (data[ptr] < '0' || data[ptr] > '9') {ptr++;}
        int maxPix = 0;
        while (data[ptr] >= '0' && data[ptr] <= '9') {
            maxPix = maxPix*10 + data[ptr] - 48;
            ptr++;
        }

        cout << ptr << '\n';
        int pixIndex = 0;
        // Calculate the trimmer value to normalize pixel values to 255
        float trimmer = 255.0f/maxPix;
        // Allocate memory for the image data
        Img = new Vector3i[height*width];
        cout << width << ' ' << height << ' ' << maxPix << ' ' << trimmer << '\n';
        
        // If PPM type is P6 (binary)
        if (data[0] == 'P' && data[1] == '6') {

            PPMType = 6;
            // Read pixel data
            while(ptr < int(size) && pixIndex < height*width) {
                Img[pixIndex] = Vector3i(
                    int(trimmer*(int(data[ptr])+(int(data[ptr])<0?(maxPix+1):0))), 
                    int(trimmer*(int(data[ptr+1])+(int(data[ptr+1])<0?(maxPix+1):0))), 
                    int(trimmer*(int(data[ptr+2])+(int(data[ptr+2])<0?(maxPix+1):0)))
                    );
                ptr += 3;
                pixIndex++;
            }
        // If PPM type is P3 (ASCII)
        } else if (data[0] == 'P' && data[1] == '3') {

            PPMType = 3;
            // Read pixel data
            while(ptr < int(size) && pixIndex < height*width) {

                // Read red value
                while (data[ptr] < '0' || data[ptr] > '9') {ptr++;}
                cout << ptr << '\n';
                int r = 0;
                while (data[ptr] >= '0' && data[ptr] <= '9') {
                    r = r*10 + data[ptr] - 48;
                    ptr++;
                }

                // Read green value
                while (data[ptr] < '0' || data[ptr] > '9') {ptr++;}
                int g = 0;
                while (data[ptr] >= '0' && data[ptr] <= '9') {
                    g = g*10 + data[ptr] - 48;
                    ptr++;
                }

                // Read blue value
                while (data[ptr] < '0' || data[ptr] > '9') {ptr++;}
                int b = 0;
                while (data[ptr] >= '0' && data[ptr] <= '9') {
                    b = b*10 + data[ptr] - 48;
                    ptr++;
                }

                cout << r << ' ' << g << ' ' << b << '\n';
                // Create a Vector3i object and normalize the pixel values
                Img[pixIndex] = Vector3i(
                    int(trimmer*r), 
                    int(trimmer*g), 
                    int(trimmer*b)
                );
                cout<<"debug "<<height*width - pixIndex<<' '<<int(size)<<endl;
                pixIndex++;
            }

        }
        cout << "loading complete" << endl;
        // Free the buffer used to read the file
        delete[] data;
        readable = true;
    } else {cout << "Error: Unale to open " << filename << '\n';readable=false;}
}

// Default constructor
PPMFile::PPMFile() {}

// Getter methods
int PPMFile::getType() {return PPMType;}

int PPMFile::getWidth() {return width;}

int PPMFile::getHeight() {return height;}

Vector3i* PPMFile::getImg() {return Img;}
