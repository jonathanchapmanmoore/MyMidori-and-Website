// Pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

int main(int argc, char* argv[])
{
    // Declare and initialize an ordinary integer variable.
    int nVar1 = 100;
    // Declare a pointer to nVar1.
    int* pInt = &nVar1;

    // Show that the pointer does point to nVar1.
    cout << "nVar1 = " << nVar1 << "     *pInt = " << *pInt << endl;
    // Show that the address of nVar1 == the value stored in pInt.
    cout << "&nVar1 = " << &nVar1 << "     pInt = " << pInt << endl;

    // Get the value of nVar1 via the pointer.
    int nVar2 = *pInt;
    // Change the value of nVar1 via the pointer.
    *pInt = 200;

    // Show the value retrieved via the pointer.
    cout << "nVar2 = " << nVar2 <<
    // Also show nVar1's new value.
        "     nVar1 now = " << nVar1 << endl;

    return 0;
}