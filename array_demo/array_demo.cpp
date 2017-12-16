// array_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	array<int, 3> arr{ 1,2,3 };
	array<string, 2> strarr{ "hello", "mello" };

	arr[2] = 2;

	for_each(arr.begin(), arr.end(), [](int val) {
		cout << val << endl;
	});

    return 0;
}

