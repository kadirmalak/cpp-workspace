// TempProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

string myreplace(string & s, string & stringToFind, string & replacement)
{
	return s.replace(s.find(stringToFind), stringToFind.length(), replacement);
}

int main() {

	auto str1 = string{ "this is a test sentence." };
	auto str2 = myreplace(str1, string{ "test" }, string{ "demo" });

	cout << "str2: " << str2 << endl;

	return 0;
}