// pplx-demo-3.cpp : Defines the entry point for the console application.
//

#include <pplx/pplxtasks.h>
#include <iostream>

int main()
{
	auto t = pplx::create_task([]() {
		throw std::exception("some exception");
		return 42;
	});

	auto r = t.get();
	std::cout << "r: " << r << std::endl;

	t.then([](pplx::task<int> t) {
		try {
			auto res = t.get();
			std::cout << "res: " << res << std::endl;
		}
		catch (const std::exception & ex) {
			std::cout << "ex: " << ex.what() << std::endl;
		}
	}).wait();

    return 0;
}

