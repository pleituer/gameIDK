#include "helpers.h"

// Define default constructor for Vector2i
Vector2i::Vector2i() {
    x = 0;
    y = 0;
}

// Define constructor for Vector2i with initialization parameters
Vector2i::Vector2i(int x, int y) {
    this->x = x;
    this->y = y;
}


// Define comparison and arithmetic operators for Vector2i
bool Vector2i::operator==(const Vector2i& vec) {return (x==vec.x && y==vec.y);}
bool Vector2i::operator!=(const Vector2i& vec) {return (x!=vec.x || y!=vec.y);}
const Vector2i Vector2i::operator+(const Vector2i& vec) {return Vector2i(x+vec.x, y+vec.y);}
const Vector2f Vector2i::operator+(const Vector2f& vec) {return Vector2f(x+vec.x, y+vec.y);}
const Vector2i Vector2i::operator-(const Vector2i& vec) {return Vector2i(x-vec.x, y-vec.y);}
const Vector2f Vector2i::operator-(const Vector2f& vec) {return Vector2f(x-vec.x, y-vec.y);}

// Define default constructor for Vector2f
Vector2f::Vector2f() {
    x = 0.0f;
    y = 0.0f;
}

// Define constructor for Vector2f with initialization parameters
Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

// Define comparison and arithmetic operators for Vector2f
bool Vector2f::operator==(const Vector2f& vec) {return (x==vec.x && y==vec.y);}
bool Vector2f::operator!=(const Vector2f& vec) {return (x!=vec.x || y!=vec.y);}
const Vector2f Vector2f::operator+(const Vector2f& vec) {return Vector2f(x+vec.x, y+vec.y);}
const Vector2f Vector2f::operator+(const Vector2i& vec) {return Vector2f(x+vec.x, y+vec.y);}
const Vector2f Vector2f::operator-(const Vector2f& vec) {return Vector2f(x-vec.x, y-vec.y);}
const Vector2f Vector2f::operator-(const Vector2i& vec) {return Vector2f(x-vec.x, y-vec.y);}

// Define default constructor for Vector3i
Vector3i::Vector3i() {
    x = 0;
    y = 0;
    z = 0;
}

// Define constructor for Vector3i with initialization parameters
Vector3i::Vector3i(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Define comparison operators for Vector3i
bool Vector3i::operator==(const Vector3i& vec) {return (x==vec.x && y==vec.y && z==vec.z);}
bool Vector3i::operator!=(const Vector3i& vec) {return (x!=vec.x || y!=vec.y || z!=vec.z);}
