#if O_WIN32
#include <windows.h>
void sleeps(float time) {Sleep(time);}
#elif __APPLE__ || __linux__
#include <unistd.h>
void sleeps(float time) {sleep(time);}
#else
void sleeps(float time) {return;}
#endif