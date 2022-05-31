// Virtual.cpp: Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

class Base
{
public:
    void Do1() { cout << "Base::Do1\n"; };
    virtual void Do2() { cout << "Base::Do2\n"; };
};

class Derived : public Base
{
public:
    // Override nonvirtual function from Base.
    //  Call is resolved at compile time.
    void Do1() { cout << "Derived::Do2\n"; };

    // Override virtual function from Base.
    //  Call is resolved at run time.
    void Do2() { cout << "Derived::Do2\n"; };
};

int main(int argc, char* argv[])
{
    Derived d;
    Base* pBase;

    // Point to a Derived object through a Base pointer.
    pBase = &d;

    cout << "Use derived object to call Do1 and Do2"
         << "through a pointer to Base.\n";
    pBase->Do1();    // Calls Base::Do1, no polymorphism.
                     //  Call based on pointer type.
    pBase->Do2();    // Calls Derived::Do2 polymorphically.
                     //  Call based on underlying type.
    cout << endl;

    cout << "Call Do1 and Do2 through a Derived object.\n";
    d.Do1();          // Calls Derived::Do1, no polymorphism.
                      //  Call based on pointer type.
    d.Do2();          // Calls Derived::Do2 polymorphically.
                      //  Call based on underlying type.

    return 0;
}
