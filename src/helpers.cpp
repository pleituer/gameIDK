#include "helpers.h"

Vector2i::Vector2i() {
    x = 0;
    y = 0;
}

Vector2i::Vector2i(int x, int y) {
    this->x = x;
    this->y = y;
}


bool Vector2i::operator==(const Vector2i& vec) {return (x==vec.x && y==vec.y);}
bool Vector2i::operator!=(const Vector2i& vec) {return (x!=vec.x || y!=vec.y);}
const Vector2i Vector2i::operator+(const Vector2i& vec) {return Vector2i(x+vec.x, y+vec.y);}
const Vector2f Vector2i::operator+(const Vector2f& vec) {return Vector2f(x+vec.x, y+vec.y);}
const Vector2i Vector2i::operator-(const Vector2i& vec) {return Vector2i(x-vec.x, y-vec.y);}
const Vector2f Vector2i::operator-(const Vector2f& vec) {return Vector2f(x-vec.x, y-vec.y);}

Vector2f::Vector2f() {
    x = 0.0f;
    y = 0.0f;
}

Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

bool Vector2f::operator==(const Vector2f& vec) {return (x==vec.x && y==vec.y);}
bool Vector2f::operator!=(const Vector2f& vec) {return (x!=vec.x || y!=vec.y);}
const Vector2f Vector2f::operator+(const Vector2f& vec) {return Vector2f(x+vec.x, y+vec.y);}
const Vector2f Vector2f::operator+(const Vector2i& vec) {return Vector2f(x+vec.x, y+vec.y);}
const Vector2f Vector2f::operator-(const Vector2f& vec) {return Vector2f(x-vec.x, y-vec.y);}
const Vector2f Vector2f::operator-(const Vector2i& vec) {return Vector2f(x-vec.x, y-vec.y);}

Vector3i::Vector3i() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3i::Vector3i(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

bool Vector3i::operator==(const Vector3i& vec) {return (x==vec.x && y==vec.y && z==vec.z);}
bool Vector3i::operator!=(const Vector3i& vec) {return (x!=vec.x || y!=vec.y || z!=vec.z);}