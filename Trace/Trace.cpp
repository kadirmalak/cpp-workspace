// Trace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Trace.h"

auto main() -> int
{
	TRACE(L"1 + 2 = %d", 1 + 2);
	return 0;
}
