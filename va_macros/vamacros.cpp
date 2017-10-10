// vamacros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <crtdbg.h>

#define ASSERT _ASSERTE

using namespace std;

void PrintFloats(wchar_t const * format, ...)
{
	printf("Printing floats:");

	va_list vl;
	va_start(vl, format);

	/*double val;
	for (int i = 0; i < 3; i++) {
		val = va_arg(vl, double);
		printf(" [%.2f]", val);
	}*/

	const int bufferSize = 256;
	wchar_t buffer[bufferSize];

	// copy formatted string into buffer
	auto count = swprintf_s(buffer, L"%S(%d): ", __FILE__, __LINE__);
	ASSERT(count != -1);

	// append formatted string with variables to the buffer
	auto count2 = _vsnwprintf_s(
		buffer + count, 
		size_t(bufferSize - count),
		size_t(bufferSize - count - 1),
		format, 
		vl);
	ASSERT(count2 != -1);

	va_end(vl);

	cout << "count: " << count << endl;
	cout << "count2: " << count2 << endl;

	printf("\n");
}

int main()
{
	PrintFloats(L"%.2f, %.2f, %.2f", 3.1234, 2.43243, 1.123123);
    return 0;
}

