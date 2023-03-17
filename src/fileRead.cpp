#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

#include "fileRead.h"
#include "helpers.h"

using namespace std;

PPMFile::PPMFile(const char* filename) {
    ifstream file;
    file.open(filename, ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
        file.seekg(0, ios::end);
        size = file.tellg();
        file.seekg(0, ios::beg);
        char* data = new char[size];
        file.read(data, size);
        file.close();
        int ptr = 2;
        while (data[ptr] < '0' || data[ptr] > '9') {ptr++;}
        while (data[ptr] >= '0' && data[ptr] <= '9') {
            width = width*10 + int(data[ptr]) - 48;
            ptr++;
        }
        ptr++;
        while (data[ptr] >= '0' && data[ptr] <= '9') {
            height = height*10 + data[ptr] - 48;
            ptr++;
        }
        ptr++;
        int maxPix = 0;
        while (data[ptr] >= '0' && data[ptr] <= '9') {
            maxPix = maxPix*10 + data[ptr] - 48;
            ptr++;
        }
        ptr++;
        cout << ptr << '\n';
        int pixIndex = 0;
        float trimmer = 255.0f/maxPix;
        Img = new Vector3i[height*width];
        cout << width << ' ' << height << ' ' << maxPix << ' ' << trimmer << '\n';
        if (data[0] == 'P' && data[1] == '6') {
            PPMType = 6;
            while(ptr < int(size) && pixIndex < height*width) {
                Img[pixIndex] = Vector3i(
                    int(trimmer*(int(data[ptr])+(int(data[ptr])<0?(maxPix+1):0))), 
                    int(trimmer*(int(data[ptr+1])+(int(data[ptr+1])<0?(maxPix+1):0))), 
                    int(trimmer*(int(data[ptr+2])+(int(data[ptr+2])<0?(maxPix+1):0)))
                    );
                ptr += 3;
                pixIndex++;
            }
        } else if (data[0] == 'P' && data[1] == '3') {
            PPMType = 3;
            while(ptr < int(size) && pixIndex < height*width) {
                while (data[ptr] < '0' || data[ptr] > '9') {ptr++;}
                cout << ptr << '\n';
                int r = 0;
                while (data[ptr] >= '0' && data[ptr] <= '9') {
                    r = r*10 + data[ptr] - 48;
                    ptr++;
                }
                ptr++;
                int g = 0;
                while (data[ptr] >= '0' && data[ptr] <= '9') {
                    g = g*10 + data[ptr] - 48;
                    ptr++;
                }
                ptr++;
                int b = 0;
                while (data[ptr] >= '0' && data[ptr] <= '9') {
                    b = b*10 + data[ptr] - 48;
                    ptr++;
                }
                ptr++;
                cout << r << ' ' << g << ' ' << b << '\n';
                Img[pixIndex] = Vector3i(
                    int(trimmer*r), 
                    int(trimmer*g), 
                    int(trimmer*b)
                );
                cout<<"debug "<<height*width - pixIndex<<' '<<int(size)<<endl;
                pixIndex++;
            }
        }
    } else {cout << "Error: Unale to open " << filename << '\n';}
}

int PPMFile::getType() {return PPMType;}

int PPMFile::getWidth() {return width;}

int PPMFile::getHeight() {return height;}

Vector3i* PPMFile::getImg() {return Img;}