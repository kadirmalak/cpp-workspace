// SmartPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
void println(T t) {
	cout << t << endl;
}

class A {
public:
	A() {
		println("constructed");
	}
	~A() {
		println("destructed");
	}
	void DoSomething() {
		println("A did something");
	}
};

auto createA() {
	auto newObj = make_shared<A>();
	return newObj;
}

auto createUniqueA() {
	auto newObj = make_unique<A>();
	return move(newObj);
}

auto useUniqueObject(unique_ptr<A> ptr) {
	ptr->DoSomething();
	return move(ptr);
}

int main()
{
	auto a = createA();
	a->DoSomething();

	auto ua = createUniqueA();
	ua->DoSomething();

	//useUniqueObject(ua);
	ua = useUniqueObject(move(ua));

    return 0;
}

