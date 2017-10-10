// ShallowCopySolution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "IntCell.h"

using namespace std;

int main()
{
	IntCell a(1);
	IntCell b(a);
	IntCell c = a;
	IntCell d;
	d = a;

	a.write(2);

	cout << a.read() << endl << b.read() << endl << c.read() << endl << d.read() << endl;

    return 0;
}

