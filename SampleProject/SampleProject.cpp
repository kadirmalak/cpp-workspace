// SampleProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Trace.h"

int main()
{
	TRACE(L"str: %s, float: %.2f", L"some string", 3.14f);
    return 0;
}

