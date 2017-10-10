// CopyMoveConstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A {
public:
	explicit A(int val) : value(val){
		cout << "constructor called!" << endl;
	}
	A(const A & other) {
		value = other.value;
		cout << "copy constructor called!" << endl;
	}
	int value;
};

class B {
public:
	B(const string & other) {
		str = other;
	}
	string str;
};

class C {
public:
	C(string && ref) {
		str = &ref;
	}
	C(C && other) {
		str = other.str;
		other.str = nullptr;
	}
	C(const C & other) {
		*str = *other.str;
	}
	string* str;
};

/*
OLMADI, DAHA ANLAMADIM.
*/
int main()
{
	auto a1 = A{ 1 };
	auto a2 = a1;
	A& a3 = a1;
	//A a4 = 3; // explicit denince compiler error veriyor
	A a4(3);

	cout << "a1 addr: " << &a1 << endl;
	cout << "a2 addr: " << &a2 << endl;
	cout << "a3 addr: " << &a3 << endl;
	cout << "a4 addr: " << &a4 << endl;

	B b1 = "hello";

	C c1 = "some string"; // alt satýra geçince yok oluyor.
	C c2 = c1;
	C c3 = C(c1);
	
    return 0;
}

