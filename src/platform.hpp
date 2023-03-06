#pragma once

#if _WIN32
    const int OSType = 0;
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_MAC
        const int OSType = 1;
    #else
        const int OSType = 3;
    #endif
#elif __linix__
    const int OSType = 2;
#else
    const int OSType = 3;
#endif

/*
Windows: 0
MacOS: 1
Linux: 2
Others: 3
*/
