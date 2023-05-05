#pragma once

// Include the header file containing input-related constants
#include "inputConstants.h"

// Check the platform being used for compilation
#if _WIN32
    // If compiling for Windows, include the inputWindows.h header
    #include "inputWindows.h"
#elif __APPLE__ || __linux__
    // If compiling for macOS or Linux, include the inputLinuxMac.h header
    #include "inputLinuxMac.h"
#endif
