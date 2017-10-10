// this.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Sample
{
	int value = 0;

public:
	Sample(int value_) : value(value_)
	{
	}

	Sample* GetPointer()
	{
		return this;
	}

	Sample& GetReference()
	{
		return *this;
	}

	Sample GetCopy()
	{
		return *this;
	}

	void increment()
	{
		value++;
	}

	int GetValue()
	{
		return value;
	}
};


int main()
{
	auto obj = Sample(1);

	auto p = obj.GetPointer();
	p->increment();

	auto c = obj.GetCopy();
	c.increment();

	auto& r = obj.GetReference();
	r.increment();

	int a = 3;
	int& b = a;

	b = 5;

	auto obj1 = Sample(5);
	Sample& obj1ref = obj1;

	obj1ref.increment();


    return 0;
}

