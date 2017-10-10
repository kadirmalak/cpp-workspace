// SharedPtrVec1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class A {
public:
	A(int val) : value(val){
		cout << "constructed" << endl;
	}
	~A() {
		cout << "deleted" << endl;
	}
	virtual void Print(ostream & out) const {
		out << "A (" << value << ")";
	}
	int value;
};

class B : public A {
public:
	B(int val) : A(val) {}
	virtual void Print(ostream & out) const {
		out << "B (" << value << ")";
	}
};

class C : public B {
public:
	C(int val) : B(val) {}
	virtual void Print(ostream & out) const {
		out << "C (" << value << ")";
	}
};

void increment(shared_ptr<A> a) {
	a->value++;
}

void increment(A* a) {
	a->value++;
}

ostream & operator << (ostream & out, const A & el)
{
	el.Print(out);
	return out;
}

void DoSomething() {

	auto a = make_shared<A>(1);
	auto b = shared_ptr<B>{ new B(2) };
	C *c = new C(3);

	increment(a);
	increment(b);
	increment(c);

	auto list = vector< shared_ptr<A> >();
	list.push_back(a);
	list.push_back(b);
	list.push_back(make_shared<C>(*c));

	for (auto el : list) {
		cout << *el << endl;
	}

	delete c;
}

int main()
{
	DoSomething();

    return 0;
}

