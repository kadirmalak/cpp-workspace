// Virtual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A {
public:
	void Print() const {
		cout << "printing from A!" << endl;
	}
};

class B : public A {
public:
	virtual void Print() const {
		cout << "printing from B!" << endl;
	}
};

class C : public B {
public:
	void Print() const {
		cout << "printing from C!" << endl;
	}
};

void PrintObjectA(const A & a) {
	a.Print();
}

void PrintObjectB(const B & b) {
	b.Print();
}

void PrintObjectC(const C & c) {
	c.Print();
}

int main()
{
	A a;
	B b;
	C c;

	PrintObjectA(a);
	PrintObjectA(b);
	PrintObjectA(c);

	PrintObjectB(b);
	PrintObjectB(c);

	PrintObjectC(c);

    return 0;
}

