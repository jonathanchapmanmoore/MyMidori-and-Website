// InitList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

// An Inner object will be embedded in an Outer object.
class Inner
{
public:
    // Default constructor
    Inner() { i = 0; j = 0; cout << "Default Inner\n"; };

    // Constructor
    Inner(int n, int o);

    // Data members
    int i;
    int j;
};

// An Outer object will contain an Inner object.
class Outer
{
public:
    // Constructor with parameters
    Outer(int j, int o, int k, int& m, char chr);

    // Embedded object
    Inner ic;

    // Const member 
    const int c;

    // Reference member
    int& ri;

    // Ordinary member
    char ch;
};

int main(int argc, char* argv[])
{
    // Create existing object to pass as reference parameter.
    int nInt = 5;
    // Construct Outer object with embedded Inner object.
    //  Initialize everything.
    Outer out(3, 9, 4, nInt, 'a');    

    // Show that embedded Inner object as well as
    //  const, reference, and ordinary members were initialized.
    cout << "out.ic.i = " << out.ic.i << "   out.ic.j = " << out.ic.j
         << endl;
    cout << "out.c = " << out.c << "   out.ri = " << out.ri << endl;
    cout << "out.ch = " << out.ch << endl;

    return 0;
}

// Outer constructor with member initialization list
Outer::Outer(int j, int o, int k, int& m, char chr)
: ic(j, o), c(k), ri(m), ch(chr)    // Member initialization list
{
    cout << "Outer constructor with parameters\n";
}

// Inner constructor, which initializes Inner::i and Inner::j
Inner::Inner(int n, int o)
{
    i = n;
    j = o;
    cout << "Inner constructor with parameters\n";
}
 