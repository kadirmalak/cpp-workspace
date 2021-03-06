// pplx-demo.cpp : Defines the entry point for the console application.
//

#include <pplx/pplxtasks.h>
#include <iostream>
#include <string>

int main()
{
	std::string someOuterString = "hello";
	std::cout << "address: " << &someOuterString << std::endl;

	auto t = pplx::create_task([]() {
		return 42;
	});

	t.then([=](int result) {
		std::cout << "result: " << result << std::endl;
		std::cout << "string: " << someOuterString << std::endl;
		std::cout << "address: " << &someOuterString << std::endl;
	}).wait();

	t.then([&](int result) {
		std::cout << "result: " << result << std::endl;
		std::cout << "string: " << someOuterString << std::endl;
		std::cout << "address: " << &someOuterString << std::endl;
	}).wait();

    return 0;
}

