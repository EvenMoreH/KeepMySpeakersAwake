#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

DWORD frequency = 160;  // Base frequency
DWORD duration = 21;    // More than 20ms was required for my speakers to register
// One Beep is enough for these speakers, other required two beeps in sequence
// DWORD frequency2 = 200; 
// DWORD duration2 = 22;


int main() {            // Main function
    FreeConsole();      // Thanks to <windows.h> library it should not create a console window

    srand(time(NULL));      // Initialization for randomize that should be called ony once
    
    printf("\t\n*KEEP MY SPEAKERS AWAKE*\n\n");

    while (true)
    {
        // Get time for speakers woken up message
        time_t orig_format;
        time(&orig_format);

        int interval;       // interval variable for Sleep fuction in miliseconds
        interval = 700000 + rand() % 800000;        // Generates random value in milliseconds that fall between 11.67 and 13.33 minutes

        // Beep uses DWORD values declared on top to produce frequency sound for specified duration (built in feature into windows)
        Beep(frequency, duration);
        
        // One Beep is enough for my speakers, other required two beeps in sequence
        // Beep(frequency2, duration2);

        printf ("> Speakers woken up at: %s\n",asctime(gmtime(&orig_format)));    // time format taken from include <time.h> document (outputs universal time)

        // Sleep function uses interval argument to pause execution of a loop for specified in interval amount of seconds
        Sleep(interval);
    }
    return 0;               // Ends main function
}