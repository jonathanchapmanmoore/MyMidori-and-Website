// scope2.cpp : Defines the entry point for the console application.
//

// Demonstrates use of the extern keyword.
// A separate .cpp file, cpp2.cpp, defines a character string s.
// That definition is not visible in this file unless we use
// the extern keyword as shown. Try commenting out the extern line.
// Build and see what errors you get.

#include "stdafx.h"
#include <iostream.h>

extern char* s;

int main(int argc, char* argv[])
{
	cout << s << endl;
	return 0;
}
