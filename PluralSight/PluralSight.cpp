// PluralSight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <crtdbg.h>
#include <stdio.h>

#define ASSERT _ASSERTE // release mode'da i�e yaram�yor

// static_assert burada da kullan�labilir

auto main() -> int
{
	//ASSERT(4 == 5);
	//printf("success\n");

	//static_assert(sizeof(double) == 4, "can't serialize floats!");
	static_assert(sizeof(float) == 4, "can't serialize floats!");
}

