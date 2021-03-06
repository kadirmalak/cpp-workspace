// pplx-demo-2.cpp : Defines the entry point for the console application.
//

#include <pplx/pplxtasks.h>
#include <iostream>
#include <string>
#include <memory>

struct A {
	int intField;
	std::string stringField;
};

int main()
{
	auto t = pplx::create_task([]() {
		auto a = std::make_shared<A>();
		a->intField = 1;
		a->stringField = 2;
		std::cout << "a: " << a << std::endl;
		std::cout << "ref count: " << a.use_count() << std::endl;
		return std::shared_ptr<A>(a);
	});

	t.then([](std::shared_ptr<A> a) {
		std::cout << "a: " << a << std::endl;
		std::cout << "ref count: " << a.use_count() << std::endl;
	}).wait();

	//t.then([](A a) {
	//	std::cout << "&a: " << &a << std::endl;
	//}).wait();

    return 0;
}

