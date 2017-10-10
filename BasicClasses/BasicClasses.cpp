// BasicClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
struct Sample
{
	typedef int myint;

	T m_obj;

	Sample(T obj) : m_obj{ obj } 
	{
		cout << "constructor called!" << endl;
	}

	static void StaticSampleMethod()
	{
		cout << "sample method called!" << endl;
	}

	static void StaticTypeMethod()
	{
		T::StaticSomeMethod();
	}

	void TypeMethod()
	{
		m_obj.SomeMethod();
	}
};

struct inner_type
{
	static void StaticSomeMethod()
	{
		cout << "some static method of the inner type!" << endl;
	}

	void SomeMethod() {
		cout << "some method of the inner type!" << endl;
	}
};

int main()
{
	Sample<inner_type>::StaticSampleMethod();
	Sample<inner_type>::StaticTypeMethod();

	auto sample = Sample<inner_type>(inner_type());
	sample.TypeMethod();

	typedef Sample<inner_type>::myint myint;

	myint a = 3;

	cout << "a: " << a << endl;

    return 0;
}

