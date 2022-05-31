// array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

int main(int argc, char* argv[])
{
	cout << "-------1. Using Array Notation----------\n";
	int arInt[] = {6, 5, 4, 3, 2};
	for(int i = 0; i < 5; i++)
		cout << "arInt[" << i << "] = " << arInt[i] << endl;

	cout << "------2. Using Pointer Arithmetic-------\n";
	int* pArray = arInt;
	for(int j = 0; j < 5; j++)
	{
		cout << "arInt[" << j << "] = " << *pArray++ << endl;
	}

	return 0;
}