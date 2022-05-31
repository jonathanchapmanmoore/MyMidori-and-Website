// string.cpp
//

#include <stdafx.h>
#include <iostream.h>

int main(int argc, char* argv[])
{
    cout << "---Using Pointer Notation on an Array---\n";
    char arStr1[] = "Programming";
    char* pStr1 = arStr1;   
    cout << arStr1 << endl;    // Show the full string first.
    while(*pStr1)
    {
        cout << "*pStr1 =" << *pStr1++ << endl;
    }

    return 0;
}
