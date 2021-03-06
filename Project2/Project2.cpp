// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

class A {
public:
	A() {}
	A(const string & val) : value(val) {

	}
	A(unique_ptr<A> a) {
		cout << "A created with unique a" << endl;
		value = a->value;
	}
	string value;
};

class B {
public:
	B(shared_ptr<A> a) {
		cout << "B created with shared a" << endl;
		value = a->value;
	}
	~B() {
		cout << "B freed" << endl;
	}
	string value;
};

int main()
{
	auto unique = make_unique<A>("un");
	auto shared = make_shared<A>("sh");

	A a(move(unique));
	B b(shared);

    return 0;
}

