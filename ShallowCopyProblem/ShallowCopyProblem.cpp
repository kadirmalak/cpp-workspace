// ShallowCopyProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class IntCell
{
	int* storedValue;

public:

	explicit IntCell(int value = 0) 
	{
		storedValue = new int(value);
	}

	int read()
	{
		return *storedValue;
	}

	void write(int value)
	{
		*storedValue = value;
	}
};

int main()
{
	IntCell a(2);
	IntCell b = a;
	IntCell c;
	c = b;

	a.write(4);

	cout << a.read() << endl << b.read() << endl << c.read() << endl;

    return 0;
}

