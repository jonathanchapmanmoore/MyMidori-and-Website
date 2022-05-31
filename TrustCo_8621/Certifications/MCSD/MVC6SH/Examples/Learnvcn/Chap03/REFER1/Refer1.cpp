// Refer1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

int main(int argc, char* argv[])
{
    // Declare an int variable and a reference to it.
    int myInt = 3;
    int& rMyRef = myInt;

    // Show that rMyRef does refer to myInt.
    cout << rMyRef << endl;    // Outputs 3

    // Change rMyRef by changing myInt.
    myInt += 1;                // Now equals 4
    cout << rMyRef << endl;    // Outputs 4

    // Change myInt through rMyRef.
    rMyRef += 1;
    // Next line outputs "rMyRef = 5    myInt = 5".
    cout << "rMyRef = " << rMyRef << "    myInt = " << myInt << endl;
    
    return 0;
}