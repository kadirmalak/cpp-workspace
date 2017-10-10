// ConstructorCall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class A {
public:
	A() {
		cout << "A constructor/0 called!" << endl;
	}
	A(const string & val) : value(val) {
		cout << "A constructor/1 called!" << endl;
	}
private:
	string value;
};

class B : public A {
public:
	B() {
		cout << "B constructor/0 called!" << endl;
	}
	B(const string & val) {
		cout << "B constructor/1 called!" << endl;
	}
};

class C : public B {
public:
	C(const string & val) : B(val) {
		cout << "C constructor/1 called!" << endl;
	}
};

int main()
{
	//A a("some string");
	//B b("some other string");
	C c("some other other string");

    return 0;
}

