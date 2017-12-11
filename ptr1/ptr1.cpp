// ptr1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

void doSomething(string & str) {
	str = "hello";
}

int main()
{
	int a = 5;
	int & b = a;

	a++;
	string s = "asd";
	doSomething(s);

	cout << b << endl;


    return 0;
}

