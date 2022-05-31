// Refer3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

struct Object
{
    int a;
    int b;
};

Object& MyFunction();

int main(int argc, char* argv[])
{
    Object& rMyObj = MyFunction();
    cout << "rMyObj.a = " << rMyObj.a << endl;

    delete &rMyObj;    // Delete object referred to
    return 0;
}

Object& MyFunction()
{
    Object* o = new Object;    // Create object on heap
    o->a = 20;                 // Set its value
    o->b = 25;
    return *o;                 // Return the object itself
}