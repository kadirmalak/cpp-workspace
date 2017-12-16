// multi_dim_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	int ** arr = new int *[3];
	for (int i = 0; i < 3; i++) {
		arr[i] = new int[i * 2];
		for (int j = 0; j < i * 2; j++) {
			arr[i][j] = i * j;
		}
	}

	for (int i = 0; i < 3; i++) {
		delete[] arr[i];
	}
	delete[] arr;

    return 0;
}

