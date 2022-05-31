// arPtrs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

int main(int argc, char* argv[])
{
    int** arInt = new int*[10];      // Allocate array of pointers.
    // Fill it with pointers.
    for(int i = 0; i < 10; i++)
    {
        arInt[i] = new int;   // Allocate pointer element.
        *arInt[i] = i;        // Initialize value pointed to.
    }
    // Print out the values or the pointers.
    //   Syntax shown prints the values.
    //   Remove the * to print the addresses stored in array.
    for(int j = 0; j < 10; j++)
    {
        cout << *arInt[j] << ", ";
    }
    cout << endl;
    // Delete all pointers stored in array
    for(int k = 0; k < 10; k++)
    {
        delete arInt[k];    // Delete each pointer element individually
    }
    delete [] arInt;        // Delete array itself.

    return 0;
}
