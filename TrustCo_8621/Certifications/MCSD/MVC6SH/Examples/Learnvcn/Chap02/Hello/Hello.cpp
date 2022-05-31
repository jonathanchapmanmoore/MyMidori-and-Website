// Hello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

// Function prototypes
bool SayHello(char* szTo, int nCalc);
void SayGoodbye();

// Constants
#define NUMERO_UNO 1
const char* OLD_FRIEND = "old friend, for now.";

int main(int argc, char* argv[])
{
    char* szCpp = "C++!";  // Declare a variable.

    // Call a function with a Boolean result.
    if(SayHello(szCpp, 2))
    {
        // Call a function with no result.
        SayGoodbye();
    }
    return 0;
}

////////////////////////////////////////
// Global function definitions

// SayHello takes two parameters and returns a result.
bool SayHello(char* szTo, int nCalc)
{
    // Use an iostream object for output.
    cout << "Hello, " << szTo << " You're Number " << NUMERO_UNO 
        << ".\n";
    return (nCalc + (nCalc * 2)) < (24/nCalc);
}

// SayGoodbye takes no parameters and returns no result.
void SayGoodbye()
{
    cout << "Bye, " << OLD_FRIEND << endl;
}
