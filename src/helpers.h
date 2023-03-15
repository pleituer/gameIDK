#pragma once

struct Vector2;
struct Vector2f;
struct Vector2i;

struct Vector2i {
    int x, y;

    Vector2i();
    Vector2i(int x, int y);
    bool operator==(const Vector2i& vec);
    bool operator!=(const Vector2i& vec);
    const Vector2i operator+(const Vector2i& vec);
    const Vector2f operator+(const Vector2f& vec);
    const Vector2i operator-(const Vector2i& vec);
    const Vector2f operator-(const Vector2f& vec);
};

struct Vector2f {
    float x, y;

    Vector2f();
    Vector2f(float x, float y);
    bool operator==(const Vector2f& vec);
    bool operator!=(const Vector2f& vec);
    const Vector2f operator+(const Vector2f& vec);
    const Vector2f operator+(const Vector2i& vec);
    const Vector2f operator-(const Vector2f& vec);
    const Vector2f operator-(const Vector2i& vec);
};

struct Vector3i {
    int x, y, z;

    Vector3i();
    Vector3i(int x, int y, int z);
    bool operator==(const Vector3i& vec);
    bool operator!=(const Vector3i& vec);
};
