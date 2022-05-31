// Ch3ex2.cpp : Defines the entry point for the console application.
//

// Create a stack using an array of char
// and a separate pointer to the stack's top.
// The stack can hold 20 characters.
// Push the word "purtsuorts" and then pop it,
// outputting the letters as you pop them.
// Here's one way to do it.

#include "stdafx.h"
#include <iostream.h>
#include <string.h>    // For strlen

int main(int argc, char* argv[])
{
    // Characters to push are in this string.
    char* bjarne = "purtsuorts";
    // Create the stack.
    char stack[20];
    // Start the stack pointer at element 0.
    char* pTop = stack;

    // Loop through bjarne, pushing letters.
    for(unsigned int i = 0; i < strlen(bjarne); i++)
    {
        *pTop++ = bjarne[i];    // Push: assign, increment pointer
    }

    // Loop, popping and outputting as many letters as we pushed.
    // Prints bjarne's last name.
    for(int j = i; j >= 0; j--)
    {
        pTop--;
        cout << *pTop;    // Pop: decrement pointer, get character
    }
    cout << endl;    // End the line

    return 0;
}