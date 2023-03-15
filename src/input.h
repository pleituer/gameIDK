#pragma once

#include "platform.h"
#include "inputConstants.h"

#if OSType == 0
    #include "inputWindows.h"
#elif OSType == 1 || OSType == 2
    #include "inputLinuxMac.h"
#endif