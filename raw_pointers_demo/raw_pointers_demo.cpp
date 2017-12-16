// raw_pointers_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class A {

};

class B {
public:
	void doSomething() {}
};

void useB(B * ptr) {
	ptr->doSomething();
}

B * createB() {
	auto ptr = new B();
	return ptr;
}

int main()
{
	auto bPtr = createB();
	useB(bPtr);
	delete bPtr;
    return 0;
}

