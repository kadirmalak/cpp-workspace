// ParameterPassing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <memory>

using namespace std;

class A {
public:
	A() : str("test") {
		cout << "A constructed!" << endl;
	}
	A(const A & a) {
		cout << "A constructed from copy" << endl;
		str = a.str;
	}
	~A() {
		cout << "A destructed!" << endl;
	}
	string str;
};

A f(A a) {
	return a;
}

void f2(A a) {
	cout << a.str << endl;
}

void f3(const A & a) {
	cout << a.str << endl;
}

void f4(unique_ptr<A> a) {
	cout << a->str << endl;
}

int main()
{
	//A a1 = f(A());
	//A a2;
	//f2(a2);
	//f3(a2);

	auto a = make_unique<A>();
	f4(move(a));

    return 0;
}

