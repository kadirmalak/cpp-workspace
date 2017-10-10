// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int arr[10];
	int otherArr[20];
	//arr = otherArr; // compiler error

	int n = 5;
	int* dynArr = new int[n];
	int* dynOtherArr = new int[n*n];

	//dynArr = dynOtherArr; // valid

	delete[] dynArr;
	delete[] dynOtherArr;

    return 0;
}

