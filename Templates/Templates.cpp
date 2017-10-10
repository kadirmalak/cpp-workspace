// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "MemoryCell.h"

using namespace std;

template<typename T>
T add(T num1, T num2) {
	return num1 + num2;
}

template <typename T>
class MemoryCell
{
public:
	explicit MemoryCell(const T & initialValue = T()) : storedValue(initialValue)
	{
	}
	const T & read() const
	{
		return storedValue;
	}
	void write(const T & x)
	{
		storedValue = x;
	}
private:
	T storedValue;
};

template <typename T>
const T & findMax(const vector<T> & arr)
{
	int maxIndex = 0;
	for (auto i = 0; i < arr.size(); i++)
	{
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}
	return arr[maxIndex];
}

int main()
{
	MemoryCell<int> m1(5);
	MemoryCell<string> m2("hello");

	m1.write(37);
	m2.write(m2.read() + " world!");

	cout << m1.read() << endl;
	cout << m2.read().c_str() << endl;

	cout << "3 + 5 = " << add<int>(3, 5) << endl;
	cout << "3 + 5 = " << add(3, 5) << endl;

	auto a = vector<int>{ 1,2,3,4 };
	auto b = vector<string>{ "qwe", "asd", "zxc" };
	auto c = vector<double>{ 1.2, 3.4, 5.6 };

	cout << "findMax(a): " << findMax(a) << endl;
	cout << "findMax(b): " << findMax(b).c_str() << endl;
	cout << "findMax(c): " << findMax(c) << endl;
	//cout << "findMax(d): " << findMax(d) << endl;

    return 0;
}

