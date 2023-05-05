// Include necessary header files.
#include <stdlib.h>


// Check if the operating system is Windows.
#if _WIN32
// Include necessary Windows header file.
#include <windows.h>

// Define a function that sleeps for the given time in seconds.
void sleeps(float time) {Sleep(time);}
// Define a function that clears the console screen.
void clears() {system("cls");}
// Check if the operating system is macOS or Linux.
#elif __APPLE__ || __linux__
// Include necessary UNIX header file.
#include <unistd.h>
// Define a function that sleeps for the given time in seconds.
void sleeps(float time) {sleep(time);}
// Define a function that clears the console screen.
void clears() {system("clear");}
// If the operating system is not recognized, define dummy functions.
#else
void sleeps(float time) {return;}
void clears() {return;}
#endif
