// bind.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <functional>
#include <string>

void f(int n1, int n2, int n3, const int & n4, int n5) {
	std::cout << "f: " << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << std::endl;
}

struct Foo {
	void print_sum(int n1, int n2) {
		std::cout <<  "print_sum: " << n1 + n2 << std::endl;
	}
	int data = 10;
};

int main()
{
	using namespace std::placeholders;

	// function call
	int n = 7;
	auto ref = std::cref(n);
	auto f1 = std::bind(f, _2, _1, 42, ref, n);
	f1(1, 2, 1001);

	// member function call
	Foo foo;
	auto foo_handler = std::bind(&Foo::print_sum, &foo, _1, _2);
	foo_handler(10, 20);

    return 0;
}

