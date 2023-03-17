#pragma once

#include "inputConstants.h"

#if _WIN32
    #include "inputWindows.h"
#elif __APPLE__ || __linux__
    #include "inputLinuxMac.h"
#endif