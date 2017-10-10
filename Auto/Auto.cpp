// Auto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <initializer_list>
#include <iostream>
#include <typeinfo>

using namespace std;

auto func1()
{
	return 1;
}

int main()
{
	auto A = { 1, 2 };
	auto C = 4;
	//auto D = { 5, 6.7 }; 
	auto E{ 9 };

	cout << "A is " << typeid(A).name() << endl;

    return 0;
}
