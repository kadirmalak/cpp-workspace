// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntCell.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string & findMax(const vector<string> & arr)
{
	int maxIndex = 0;
	for (int i = 0; i < arr.size(); i++) 
	{
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}
	return arr[maxIndex];
}

const string & findMaxWRONG(const vector<string> & arr)
{
	string maxValue = arr[0];
	for (int i = 0; i < arr.size(); i++) 
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
		}
	}
	return maxValue;
}

double avg(const vector<int> & arr, int n, bool & errorFlag)
{
	auto sum = 0;
	for (int i : arr)
	{
		sum += i;
	}

	errorFlag = false;

	return double(sum) / n;
}

int main()
{
	IntCell cell;

	IntCell* m = new IntCell;
	m->write(5);

	cout << "m: " << m->read() << endl;

	delete m;

	cout << "cell: " << cell.read() << endl;

	bool flag;
	auto vec = vector<int>{ 1,2,3,4,5 };
	auto a = avg(vec, 5, flag);

	cout << "avg: " << a << endl;

	// burada max deðeri value ile alýnca, max string'den bir kopya yaratýlmýþ oluyor
	// eðer sadece const string & ile alsaydýk aþaðýdaki maxRef'te olduðu gibi
	// ayný adrese bakan bir referans ile, deðeri kopyalamadan baþka bir deðiþkende tutacaktýk.
	auto strVec = vector<string>{ "some string", "some other string", "yet another string" };
	string max = findMax(strVec);
	const string & maxRef = findMax(strVec);

	cout << "address of max: " << &max << endl;
	cout << "address of maxRef: " << &maxRef << endl;
	cout << "address of strVec[2]: " << &strVec[2] << endl;

	//auto max2 = findMaxWRONG(strVec);

	cout << "press enter key to exit..." << endl;
	string line;
	getline(cin, line);

    return 0;
}

