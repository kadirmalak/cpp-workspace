// DoubleAmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void someFunc(const string && str) {
	cout << "&&: " << str << endl;
}

void someFunc(const string & str) {
	cout << "&:" << str << endl;
}

int main()
{
	auto&& r = "some string";

	someFunc("some string");

	auto str = "some other string";
	someFunc(str);

    return 0;
}

