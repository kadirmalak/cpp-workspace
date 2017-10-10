// Lambdas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

template <typename T>
const T & findMax(const vector<T> & arr, function<int (T, T)> comparer)
{
	size_t maxIndex = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (comparer(arr[i], arr[maxIndex]) == 1)
		{
			maxIndex = i;
		}
	}
	return arr[maxIndex];
}

int main()
{
	auto func = []() {cout << "hello from lambda!" << endl; };
	func();

	auto funcWithParams = [](int p1, const string & p2) {
		cout << "int: " << p1 << ", string: " << p2 << endl;
	};
	funcWithParams(13, "hello");

	auto comparer = [](int lhs, int rhs) {
		if (lhs < rhs) return -1;
		if (lhs > rhs) return 1;
		return 0;
	};

	vector<int> numbers = { 5,1,2,7,3,9,8 };
	vector<string> words = { "hello", "mello", "cello" };
	cout << "max: " << findMax<int>(numbers, comparer) << endl;
	auto maxStr = findMax<string>(words, [](const string & lhs, const string & rhs)
	{
		return 1;
	});
	cout << "max word: " << maxStr << endl;

    return 0;
}

