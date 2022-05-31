// CopyProb.cpp : Defines the entry point for the console application.
//

#include "Stdafx.h"
#include <iostream.h>

// Two classes, HasPtr1 and HasPtr2, with identical data members.

// Class HasPtr1 has no copy constructor; 
//  objects of the class will be copied memberwise.
class HasPtr1
{
public:
    // Default constructor
    HasPtr1() { cout << "In default constructor for HasPtr1.\n"; };
    char m_c;       // Non-pointer member
    int* m_pInt;    // Pointer member
};

// Class HasPtr2 has a copy constructor
//  that will be called for copying.
class HasPtr2
{
public:
    // Default constructor
    HasPtr2() { cout << "In default constructor for HasPtr2.\n"; };
    // Copy constructor
    HasPtr2(const HasPtr2&);
    char m_c;       // Non-pointer member
    int* m_pInt;    // Pointer member
};

// Global function
void Function(HasPtr2 HP2);

int main(int argc, char* argv[])
{
    // Memberwise copy.
    HasPtr1 hp1;
    hp1.m_pInt = new int;
    *hp1.m_pInt = 0;
    hp1.m_c = '0';
    cout << "\n1. Now memberwise copy hp1 into copy1.\n";
    HasPtr1 copy1 = hp1;    // Memberwise copy.
    cout << "*copy1.m_pInt = " << *copy1.m_pInt 
         << "  *hp1.m_pInt = " << *hp1.m_pInt << endl;
    cout << "copy1.m_pInt = " << copy1.m_pInt 
         << "  hp1.m_pInt = " << hp1.m_pInt << endl << endl;
    // The two addresses are the same due to memberwise copy.

    // Copy with copy constructor.
    HasPtr2 hp2;            // Invokes default constructor.
    hp2.m_pInt = new int;
    *hp2.m_pInt = 1;
    hp2.m_c = '1';
    cout << "\n2. Now copy hp2 into copy2 with copy constructor.\n";
    HasPtr2 copy2 = hp2;    // Invokes copy constructor.
    cout << "*copy2.m_pInt = " << *copy2.m_pInt 
         << "  *hp2.m_pInt = " << *hp2.m_pInt << endl;
    cout << "copy2.m_pInt = " << copy2.m_pInt 
         << "  hp2.m_pInt = " << hp2.m_pInt << endl;
    // The two addresses are different; didn't memberwise copy.

    cout << "\n3. Now show the difference between "
         << "initialization and assignment.\n";
    // Initialize a new HasPtr2 object; invokes copy constructor.
    cout << "Initialization: HasPtr2 copy3 = copy2. ";
    HasPtr2 copy3 = copy2;
    // Use assignment; do not invoke copy constructor.
    cout << "Assignment: copy4 = copy2. ";
    HasPtr2 copy4;
    copy4 = copy2;

    // Copy during pass by value.
    cout << "\n4. Now pass a HasPtr2 object by value.\n";
    Function(hp2);

    return 0;
}

HasPtr2::HasPtr2(const HasPtr2& HP2)
{
    cout << "In copy constructor for HasPtr2.\n";
    m_pInt = new int;
    *m_pInt = *HP2.m_pInt;
    m_c = HP2.m_c;
}

void Function(HasPtr2 HP2)
{
    cout << "In Function, HP2.m_pInt = " << HP2.m_pInt << endl;
}
