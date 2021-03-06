// smart_pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <memory>
#include <iostream>

class A {
public:
	A() {
		std::cout << "constructor called!" << std::endl;
	}
	~A() {
		std::cout << "destructor called!" << std::endl;
	}
	int value(){
		return _value;
	}
	void set_value(int newVal) {
		_value = newVal;
	}
private:
	int _value;
};

auto createA() {
	std::shared_ptr<A> ptr(nullptr);
	ptr.reset(new A());
	return ptr;
}

auto * createA2() {
	return new A();
}

auto createA3() {
	auto a = std::make_shared<A>();
	a->set_value(5);
	return a;
}

int main()
{
	auto a3 = createA3();
	std::cout << "a3 value: " << a3->value() << std::endl;

	auto a2 = createA2();
	delete a2;
	auto a = createA();
	std::cout << "reference count: " << a.use_count() << std::endl;
    return 0;
}

