// Ch3ex1.cpp : Defines the entry point for the console application.
//

// Put the alphabet into an array. Use a pointer
// to walk the array backwards, printing letters
// in reverse alphabetical order.

#include "stdafx.h"
#include <iostream.h>

int main(int argc, char* argv[])
{
    // Create the array either as an array of char
    // or as a pointer to char (char* arAlpha = ...).
    // Initialize with the string.
    char arAlpha[27] = "abcdefghijklmnopqrstuvwxyz";

    // Create a separate pointer to char.
    // Use pointer arithmetic to point it at 'z'.
    char* pc = arAlpha + 25;

    // Loop down from 25 to 0, using this form of
    // the for loop:
    for(int i = 25; i >= 0; i--)
    {
        // Print character, then decrement pointer.
        cout << *pc--;
    }
    cout << endl;    // End the line

    return 0;
}