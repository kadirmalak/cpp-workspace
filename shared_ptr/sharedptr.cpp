// sharedptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <crtdbg.h>
#include <memory>
#include <iostream>

using namespace std;

#define ASSERT(x) _ASSERTE(x)

void display(int& num)
{
	cout << "num: " << num << endl;
}

int main()
{
	auto sp = shared_ptr<int>{};
	cout << "sp: " << sp << endl;

	ASSERT(!sp);
	ASSERT(sp.use_count() == 0);
	ASSERT(!sp.unique());

	sp = make_shared<int>(3);
	cout << "sp: " << sp << endl;

	ASSERT(sp);
	ASSERT(sp.use_count() == 1);
	ASSERT(sp.unique());

	auto sp2 = sp;
	
	ASSERT(sp.use_count() == 2);
	ASSERT(!sp.unique());


	ASSERT(sp2.use_count() == 2);
	ASSERT(!sp2.unique());

	int copy = *sp;
	int& ref = *sp;
	int* ptr = sp.get();

	cout << "copy: " << copy << endl;
	cout << "ref: " << ref << endl;
	cout << "ptr: " << ptr << endl;
	cout << "*ptr: " << *ptr << endl;

	ASSERT(sp.get() == sp2.get());
	ASSERT(sp == sp2);

	display(*sp);

    return 0;
}

