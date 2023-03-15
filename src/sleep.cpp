#include "platform.h"

#if OSType == 0
#include <windows.h>
void sleeps(float time) {Sleep(time);}
#elif OSType == 1 || OSType == 2
#include <unistd.h>
void sleeps(float time) {sleep(time);}
#else
void sleeps(float time) {return;}
#endif