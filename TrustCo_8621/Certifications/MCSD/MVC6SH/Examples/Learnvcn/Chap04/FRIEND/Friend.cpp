// Friend.cpp : Defines the entry point for the console application.
//

#include "Stdafx.h"
#include <iostream.h>

class A
{
    friend class B;    // Can declare friends under any
                       //  access specifier; here it 
                       //  happens to be private.

public:
    // Constructor
    A(int n, char* psz) { m_int = n; m_psz = psz; };

private:
    int m_int;
    char* m_psz;
};

class B    // friend of A
{
public:
    // Constructor
    B(A* pA) { m_pA = pA; };

    // Functions allowed to access A's private members
    int GetAInt() { return m_pA->m_int; };
    char* GetAStr() { return m_pA->m_psz; };

private:
    // Pointer to A, declared private so users of B
    //  must use GetAInt or GetAStr to access A
    A* m_pA;
};

int main(int argc, char* argv[])
{
    // Construct an A object.
    A a(4, "This is an A object.");

    // Construct a B object initialized
    //  with a pointer to the A object.
    B b(&a);

    // Demonstrate access to private member of A via a B object.
    cout << b.GetAInt() << "   " << b.GetAStr() << endl;

    return 0;
}