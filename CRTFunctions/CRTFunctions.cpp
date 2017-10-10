// CRTFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int main()
{
	wchar_t buffer[256];

	auto count = swprintf_s(
		buffer, L"%S(%d): ", __FILE__, __LINE__);
	
	cout << "count: " << count << endl;
	cout << "buffer: " << &buffer << endl;

	va_list args;
	//va_start(args, )

	//_vsnwprintf_s()

    return 0;
}

