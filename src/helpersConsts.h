#pragma once

#include "helpers.h"

// Define a constant that helps to prevent multiple declarations of constants
#if !defined(HelperConstantConst)
#define HelperConstantConst 1


// Define color constants as references to Vector3i instances
// Red color (255, 0, 0)
const Vector3i& RED = Vector3i(255, 0, 0);
// Green color (0, 255, 0)
const Vector3i& GREEN = Vector3i(0, 255, 0);
// Blue color (0, 0, 255)
const Vector3i& BLUE = Vector3i(0, 0, 255);
// Yellow color (255, 255, 0)
const Vector3i& YELLOW = Vector3i(255, 255, 0);
// Purple color (255, 0, 255)
const Vector3i& PURPLE = Vector3i(255, 0, 255);
// White color (255, 255, 255)
const Vector3i& WHITE = Vector3i(255, 255, 255);
// Black color (0, 0, 0)
const Vector3i& BLACK = Vector3i(0, 0, 0);
// Grey color (127, 127, 127)
const Vector3i& GREY = Vector3i(127, 127, 127);

#endif
