#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>

DWORD frequency = 160;  // Base frequency
DWORD duration = 21;    // More than 20ms was required for my speakers to register
// One Beep is enough for these speakers, other required two beeps in sequence thus I leave below variables just in case
// DWORD frequency2 = 200; 
// DWORD duration2 = 22;

int main() {
    FreeConsole();          // Thanks to <windows.h> library it should not create a console window
    srand(time(NULL));      // Initialization for randomize that should be called ony once
    while (true)
    {
        int interval;                               // interval variable for Sleep fuction must be in miliseconds
        interval = 700000 + rand() % 800000;        // Generates random value in milliseconds that fall between 11.67 and 13.33 minutes

        // Beep uses DWORD values declared on top to produce frequency sound for specified duration (built in feature)
        Beep(frequency, duration);
        
        // One Beep is enough for my speakers, other required two beeps in sequence so I commented it out
        // Beep(frequency2, duration2);

        Sleep(interval);
    }
    return 0;
}