#pragma once

#include "platform.hpp"
#include "inputConstants.hpp"

#if OSType == 0
    #include "inputWindows.hpp"
#elif OSType == 1 || OSType == 2
    #include "inputLinuxMac.hpp"
#endif