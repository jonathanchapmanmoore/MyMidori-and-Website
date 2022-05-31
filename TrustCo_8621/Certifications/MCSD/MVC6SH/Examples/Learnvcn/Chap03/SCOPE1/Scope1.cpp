// Scope1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

int n1;    // Global n1

// Two function prototypes (global functions)
void f1(int n);
void f2(int n);

int main(int argc, char* argv[])
{
    // n2 not visible here; not declared yet
    // Error if next line not commented
    // cout << "n2 = " << n2 << "    Error: n2 not visible here\n";
    int n2 = 9;
    cout << "In main, n2 = " << n2 << endl;

    n1 = 1;    // Initialize global n1
    cout << "In main, n1 = " << n1 << endl;

    // Call the functions.
    f1(2);
    f2(3);

    return 0;
}

void f1(int n)
{
    int n1 = 10;    // Local n1, hides global n1
    cout << "In f1, n1 = " << n1 << ", n = " << n << endl;
}

void f2(int n)
{
    // In f2, n1 is the global n1.
    cout << "In f2, n1 = " << n1 << ", n = " << n << endl;
    for(int i = 0; i < 10; i++)
    {
        // In the for loop, n1 is the global n1.
        if(i == 0)
            cout << "In f2's for loop, n1 = " << n1 <<
                ", n = " << n << ", i = " << i << endl;
    }
    cout << "After the for loop, i = " << i << endl;

    {   // Local block in f2 establishes a subordinate local scope.
        // Inside this block, n1 is the global n1.
        cout << "In f2's local block, n1 = " << n1 <<
            ", n = " << n << endl;
        int x = 7;    // x is local to this block
    }
    // Error if next line is uncommented.
    // cout << "Outside local block, x = " << x << endl;      
}