// weakptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <crtdbg.h>
#include <iostream>

#define ASSERT(x) _ASSERTE(x)

using namespace std;


int main()
{
	auto sp = make_shared<int>(5);

	auto wp = weak_ptr<int>(sp);

	ASSERT(!wp.expired());
	ASSERT(wp.use_count() == 1); // shared pointers strong reference count

	if (auto locked = wp.lock())
	{
		cout << "wp locked!" << endl;
		locked.reset();
	}

	sp = nullptr;
	ASSERT(wp.expired());
	ASSERT(wp.use_count() == 0);

	if (auto locked = wp.lock())
	{
		cout << "wp locked!" << endl;
	}
	else {
		wp.reset();
	}

    return 0;
}

