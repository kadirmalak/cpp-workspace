// ParameterPassing2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A {
public:
	A() { 
		cout << "ctor called" << endl; 
	}
	A(const A & a) { 
		cout << "copy ctor called" << endl; 
	}
};

void f(const A & a) {
	//a = A(); ERROR
}

void f2(A & a) {
	//a = A(); OK
}

void f3(A a) {
	//a = A(); OK
}

int main()
{
	A a;
	f(a);
	f2(a);
	f3(a);
    return 0;
}

