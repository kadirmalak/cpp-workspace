// effective_pointers2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class A {
public:
	A(const string & str) : _str(str) { cout << "A created!" << endl; }
	virtual ~A() { cout << "A destroyed!" << endl; };
protected:
	string _str;
};

class B : public A {
public:
	B(const string & str) : A(str) { cout << "B created!" << endl; }
	~B() { cout << "B destroyed!" << endl; }
};

class C : public A {
public:
	C(const string & str) : A(str) { cout << "C created!" << endl; }
	~C() { cout << "C destroyed!" << endl; }
};

auto deleteObject = [](A * obj) {
	cout << "custom deleter" << endl;
	delete obj;
};

template<typename... Ts>
auto createObject(string type, Ts&&... params) {
	unique_ptr<A, decltype(deleteObject)> uptr(nullptr, deleteObject);
	if (type == "one") {
		uptr.reset(new B(forward<Ts>(params)...));
	}
	else {
		uptr.reset(new C(forward<Ts>(params)...));
	}
	return uptr;
}


int main()
{
	{
		auto obj1 = createObject("one", "obj1");
		auto obj2 = createObject("two", "obj2");

		shared_ptr<A> sp = createObject("one", "third");
	}
    return 0;
}

