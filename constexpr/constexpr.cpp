// constexpr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

constexpr long long factorial(int n)
{
	return n <= 1 ? 1 : (n * factorial(n - 1));
}

int main()
{
	auto i = factorial(10);
    return 0;
}

