// type-deduction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T(&)[N]) noexcept {
	return N;
}

int main()
{
	int keyVals[] = { 1, 3, 5, 7, 9 };
	int mappedVals[arraySize(keyVals)];

	std::array<int, 5> arr1 = { 1,2,3,4,5 };
	std::array<int, arr1.size()> arr2 = { 2,3,4,5,6 };

    return 0;
}

