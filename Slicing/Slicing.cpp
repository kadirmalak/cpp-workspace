// Slicing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class A {
public:
	A() {
		cout << "A constructed!" << endl;
	}
	~A() {
		cout << "A destructed!" << endl;
	}
	virtual void Print() {
		cout << "hello from class A!" << endl;
	}
};

class B : public A {
public:
	B() {
		cout << "B constructed!" << endl;
	}
	~B() {
		cout << "B destructed!" << endl;
	}
	virtual void Print() {
		cout << "hello from class B!" << endl;
	}
};

class C : public B {
public:
	C() {
		cout << "C constructed!" << endl;
	}
	~C() {
		cout << "C destructed!" << endl;
	}
	virtual void Print() {
		cout << "hello from class C!" << endl;
	}
};


int main()
{
	auto objects = vector<A*>();
	auto a = A();
	auto b = B();
	auto c = C();

	objects.push_back(&a);
	objects.push_back(&b);
	objects.push_back(&c);

	for (auto obj : objects) {
		obj->Print();
	}

    return 0;
}

