// Macros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define ARRAY_COUNT(x) size_t(sizeof(x) / sizeof(x[0]))

template<typename T>
inline size_t sizeofarray(T arr[])
{
	return size_t(sizeof(*arr) / sizeof(*arr[0]));
}

int main()
{
	int numbers[] = { 1,2,3,4,5 };
	auto count = ARRAY_COUNT(numbers);
	auto count2 = sizeofarray(&numbers);

	cout << "count: " << count << endl;
	cout << "count2: " << count2 << endl;

	printf("first loop:\n");
	for (size_t i = 0; i < count; i++) {
		int number = numbers[i];
		printf("%d\n", number);
	}
	printf("\n\n");

	printf("second loop:\n");
	for (auto item : numbers) {
		printf("%d\n", item);
	}

    return 0;
}

