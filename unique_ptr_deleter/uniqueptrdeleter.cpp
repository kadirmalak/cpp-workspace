// uniqueptrdeleter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

struct SomeType
{
	int field1;
	float field2;

	SomeType(int _field1, float _field2) : field1(_field1), field2(_field2)
	{
		cout << "SomeType object (" << field1 << "," << field2 << ") created!" << endl;
	}

	~SomeType()
	{
		cout << "SomeType object (" << field1 << "," << field2 << ") destroyed!" << endl;
	}
};

struct my_deleter
{
	void operator()(SomeType* value)
	{
		//cout << "some custom SomeType delete operation performed!" << endl;
		value->~SomeType();
	}
};

int main()
{
	auto ptr = unique_ptr<SomeType, my_deleter>{ new SomeType(5, 5.14f) };
	//auto ptr = unique_ptr<SomeType>{ new SomeType(5, 5.14f) };

	cout << "ptr->field1: " << ptr->field1 << endl;

    return 0;
}

