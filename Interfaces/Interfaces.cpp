// Interfaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

template <typename T>
void println(const T & t) {
	cout << t << endl;
}

struct Interface1 {
	virtual int returnInt() = 0;
	virtual string returnString(int someParam) = 0;
};

struct Interface2 {
	virtual void doSomething() = 0;
};

class A : 
	public Interface1, 
	public Interface2 {
public:
	virtual int returnInt() {
		return 1;
	}
	virtual string returnString(int someParam) {
		return "hello";
	}
	virtual void doSomething() {
		println("did something");
	}
};

int main()
{
	A a; // not allowed if not properly implemented!
	println(a.returnInt());
	println(a.returnString(1));
	a.doSomething();
    return 0;
}

