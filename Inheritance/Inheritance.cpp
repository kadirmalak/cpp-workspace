// Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class A {
private:
	int x;
protected:
	int y;
public:
	int z;
};

class B : private A {
public:
	B() {
		//x = 1;
		y = 1;
		z = 1;
	}
};

class C : protected A {
public:
	C() {
		//x = 1;
		y = 1;
		z = 1;
	}
};

class D : public A {
public:
	D() {
		//x = 1;
		y = 1;
		z = 1;
	}
};

int main()
{
	B b;
	//b.z = 1;

	C c;
	//c.z = 1;

	D d;
	d.z = 1;

    return 0;
}

