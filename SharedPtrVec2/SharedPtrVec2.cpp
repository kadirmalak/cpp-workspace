// SharedPtrVec2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A {
public:
	virtual void SomeMethod() {
		cout << "hello from A!" << endl;
	}
};

class B : public A {
	virtual void SomeMethod() {
		cout << "hello from B!" << endl;
	}
};

class Program {

public:
	Program() {
		auto a = make_shared<A>();
		auto b = make_shared<B>();
		objects.push_back(a);
		objects.push_back(b);
	}
	void iterate() {
		for (auto& obj : objects) {
			obj->SomeMethod();
		}
	}
private:
	vector< shared_ptr<A> > objects;
};

int main()
{
	Program program;
	program.iterate();
    return 0;
}

