// ch5ex2.cpp : Defines the entry point for the console application.
// For Try It Yourself, exercise 2, Chapter 5

#include <stdafx.h>
#include <iostream.h>

// COne is a totally private class, inaccessible from outside.
class COne
{
// It's as if there's a private access specifier here.
//protected:
    COne() { m_one = 0; m_one_c = 'a'; };
    int m_one;
    char m_one_c;
    void DoOne() { cout << m_one << " " << m_one_c << endl; };
};

class CTwo : protected COne		// Note protected keyword here
{
public:
	// Constructor and DoTwo member function 
	//  try to access COne members, but they're private.
    CTwo() { m_one = 1; m_one_c = 'b'; };
    int m_two;
    void DoTwo() { cout << m_one << " " << m_two << endl; };
};

int main(int argc, char* argv[])
{
	COne one;			// Can't call this constructor 
	                    //  because it's private.
	CTwo two;			// Tries to access COne members,
	                    //  but they're private.
	two.DoTwo();		// Ditto

	return 0;
}