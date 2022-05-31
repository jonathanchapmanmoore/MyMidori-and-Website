// Refer2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

struct BigObject
{
    int Var1;
    double arDbl[2000];    // Allocates space for 2,000 doubles
};

void MyFunction(BigObject& bo);

int main(int argc, char* argv[])
{
    BigObject myBo;
    myBo.Var1 = 0;
    cout << "Before MyFunction call, myBo.Var1 = " <<
        myBo.Var1 << endl;

    MyFunction(myBo);
    cout << "After MyFunction call, myBo.Var1 now = " <<
        myBo.Var1 << endl;

    return 0;
}

void MyFunction(BigObject& bo)
{
    cout << "Entering MyFunction, bo.Var1 = " << bo.Var1 << endl;
    bo.Var1 = 100;
}