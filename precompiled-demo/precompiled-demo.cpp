// precompiled-demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "unstable_class.hpp"

int main()
{
	stable_class o1;
	unstable_class o2;

	o1.doSomething();
	o2.doSomething();

    return 0;
}

