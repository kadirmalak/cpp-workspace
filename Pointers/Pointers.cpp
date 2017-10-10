// Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

void getSeconds(unsigned long* par);
double getAverage(int* arr, int size);
int* getRandom();

using namespace std;

int main()
{
	int var1 = 3;
	char var2[] = { 'a', 'b', 'c' };

	int* intPointer = &var1;

	cout << "address of var1 variable: " << &var1 << endl;
	cout << "address of var2 variable: " << &var2 << endl;
	cout << "address of intPointer: " << intPointer << endl;
	cout << "value of intPointer: " << *intPointer << endl;

	intPointer = NULL;
	if (intPointer) {
		cout << "intPointer is not null" << endl;
	}
	else if (!intPointer) {
		cout << "intPointer is null" << endl;
	}

	const int MAX = 3;
	int arr[MAX] = { 1,2,3 };
	int* ptr = arr;

	cout << "arr: " << arr << endl;
	cout << "ptr: " << ptr << endl;

	for (int i = 0; i < MAX; i++) {
		cout << "addr: " << ptr << endl;
		cout << "*ptr: " << *ptr << endl;
		ptr++;
	}

	ptr = &arr[MAX - 1];
	for (int i = 0; i < MAX; i++) {
		cout << "addr: " << ptr << endl;
		cout << "*ptr: " << *ptr << endl;
		ptr--;
	}

	*(arr + 2) = 500;

	ptr = arr;
	int i = 0;
	while (ptr <= &arr[MAX - 1]) {
		cout << "arr[" << i << "] = " << *ptr << endl;
		i++;
		ptr++;
	}

	int* ptrArr[MAX];
	for (int i = 0; i < MAX; i++) {
		ptrArr[i] = &arr[i];
	}

	for (int i = 0; i < MAX; i++) {
		cout << "ptrArr[" << i << "] = " << *ptrArr[i] << endl;
	}

	int intVal = 5;
	int* intValPtr = &intVal;
	int** intValPtrPtr = &intValPtr;

	cout << "intVal: " << intVal << endl;
	cout << "intValPtr: " << intValPtr << endl;
	cout << "*intValPtr: " << *intValPtr << endl;
	cout << "intValPtrPtr: " << intValPtrPtr << endl;
	cout << "*intValPtrPtr: " << *intValPtrPtr << endl;
	cout << "**intValPtrPtr: " << **intValPtrPtr << endl;

	unsigned long sec = 999;
	cout << "sec: " << sec << endl;
	getSeconds(&sec);
	cout << "sec: " << sec << endl;

	unsigned long* sec2 = new unsigned long;
	*sec2 = 999;
	cout << "*sec2: " << *sec2 << endl;
	getSeconds(sec2);
	cout << "*sec2: " << *sec2 << endl;

	int someNumbers[5] = { 11, 13, 41, 22, 31 };
	auto avg = getAverage(someNumbers, 5);
	cout << "avg: " << avg << endl;

	int* rndArr = getRandom();
	for (int i = 0; i < 10; i++) {
		cout << "*(rndArr + " << i << "): " << *(rndArr + i) << endl;
	}

	void* pointsToAny = &intVal;
	cout << "pointsToAny: " << pointsToAny << endl;
	cout << "*pointsToAny: " << *((int*)pointsToAny) << endl;

    return 0;
}

void getSeconds(unsigned long* par)
{
	*par = time(NULL);
}

double getAverage(int* arr, int size) 
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return double(sum) / size;
}

int* getRandom()
{
	static int r[10];
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		r[i] = rand();
	}

	return r;
}
