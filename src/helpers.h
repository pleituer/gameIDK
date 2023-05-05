#pragma once

// Forward declarations for Vector2, Vector2f, and Vector2i structures
struct Vector2;
struct Vector2f;
struct Vector2i;

// Define the Vector2i structure for representing 2D integer vectors
struct Vector2i {
    int x, y;

    // Default constructor
    Vector2i();
    // Constructor with initialization parameters
    Vector2i(int x, int y);
    // Equality operator
    bool operator==(const Vector2i& vec);
    // Inequality operator
    bool operator!=(const Vector2i& vec);
    // Addition operator
    const Vector2i operator+(const Vector2i& vec);
    // Addition operator with Vector2f
    const Vector2f operator+(const Vector2f& vec);
    // Subtraction operator
    const Vector2i operator-(const Vector2i& vec);
    // Subtraction operator with Vector2f
    const Vector2f operator-(const Vector2f& vec);
};

// Define the Vector2f structure for representing 2D floating-point vectors
struct Vector2f {
    float x, y;

    // Default constructor
    Vector2f();
    // Constructor with initialization parameters
    Vector2f(float x, float y);
    // Equality operator
    bool operator==(const Vector2f& vec);
    // Inequality operator
    bool operator!=(const Vector2f& vec);
    // Addition operator
    const Vector2f operator+(const Vector2f& vec);
    // Addition operator with Vector2i
    const Vector2f operator+(const Vector2i& vec);
    // Subtraction operator
    const Vector2f operator-(const Vector2f& vec);
    // Subtraction operator with Vector2i
    const Vector2f operator-(const Vector2i& vec);
};

// Define the Vector3i structure for representing 3D integer vectors
struct Vector3i {
    int x, y, z;

    // Default constructor
    Vector3i();
    // Constructor with initialization parameters
    Vector3i(int x, int y, int z);
    // Equality operator
    bool operator==(const Vector3i& vec);
    // Inequality operator
    bool operator!=(const Vector3i& vec);
};
