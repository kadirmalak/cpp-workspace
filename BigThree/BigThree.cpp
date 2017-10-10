// BigThree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class IntCell
{
	int m_value;

public:

	IntCell(int value) : m_value(value)
	{
		cout << "constructor called!" << endl;
	}

	IntCell(const IntCell & rhs) : m_value(rhs.m_value) 
	{
		cout << "copy constructor called!" << endl;
	}

	const IntCell & operator=(const IntCell & rhs)
	{
		cout << "= operator called!" << endl;
		if (this != &rhs) {
			m_value = rhs.m_value;
		}
		return *this;
	}

	~IntCell()
	{
		cout << "destructor called!" << endl;
	}
};

class SomeClass
{
private:
	int m_someValue;

public:
	SomeClass(int value = 0) : m_someValue(value) 
	{
		cout << "default constructor called!" << endl;
	}

	SomeClass(const SomeClass & rhs)
	{
		cout << "copy constructor called!" << endl;
	}

	const SomeClass & operator=(const SomeClass & rhs) 
	{
		cout << "= operator called!" << endl;
		this->m_someValue = rhs.m_someValue;
		return *this;
	}

	void SetSomeValue(int value)
	{
		m_someValue = value;
	}

	~SomeClass() {
		cout << "destructor called!" << endl;
	}
};

int main()
{
	SomeClass A(5);
	SomeClass B = A;

	SomeClass X = 5;
	SomeClass Y{ 5 };
	SomeClass Z(5);

	SomeClass C;
	C = A;
	C.SetSomeValue(3);

	IntCell cellA(5);
	IntCell cellB = cellA;
	IntCell cellC(cellA);

	IntCell cellD(9);
	cellD = cellA;

    return 0;
}

