// Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	cout << string{ "öçþýðüÖÇÞÝÐÜ" } << endl;

	auto str = string{ "some " "string " "concatenated" };

    return 0;
}
