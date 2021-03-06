// Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class A {
public:
	A() {
		cout << "A created!" << endl;
	}
	~A() {
		cout << "A destroyed" << endl;
	}
	A(const A & other) = delete;
	string value;
};

A* createA() {
	auto a = new A();
	a->value = "some value";
	return a;
}

auto createA2() {
	auto a = make_unique<A>();
	a->value = "some";
	return a;
}

auto useA(unique_ptr<A> a) {
	cout << "printing a: " << a->value << endl;
}

int main()
{
	//auto a = createA();
	//cout << a->value << endl;
	//delete a;

	auto a2 = createA2();
	useA(move(a2));

    return 0;
}

