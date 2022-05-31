// scope3.cpp : Defines the entry point for the console application.
//

// Demonstrates use of the static keyword.

// Two .cpp files define variables of the same type and name.  
// We want them to be seen as different variables rather than 
// as a redefinition of the same variable. Try commenting out 
// the 'static' prefix to variable c in file scope3.cpp. 
// Build and see what errors you get.

#include "stdafx.h"
#include <iostream.h>

static char* c = "static";

int main(int argc, char* argv[])
{
	cout << c << endl;
	return 0;
}
