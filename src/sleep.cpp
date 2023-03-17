#include <stdlib.h>

#if _WIN32
#include <windows.h>
void sleeps(float time) {Sleep(time);}
void clears() {system("cls");}
#elif __APPLE__ || __linux__
#include <unistd.h>
void sleeps(float time) {sleep(time);}
void clears() {system("clear");}
#else
void sleeps(float time) {return;}
void clears() {return;}
#endif