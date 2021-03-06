// decltype_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <memory>

template<typename Container, typename Index>
auto authAndAccess1(Container & c, Index i) {
	return c[i];
}

template<typename Container, typename Index>
auto authAndAccess2(Container & c, Index i) -> decltype(c[i]) {
	return c[i];
}

template<typename Container, typename Index>
decltype(auto) authAndAccess3(Container & c, Index i) {
	return c[i];
}

template<typename Container, typename Index>
decltype(auto) authAndAccess4(Container && c, Index i) {
	return std::forward<Container>(c)[i];
}

template<typename Container, typename Index>
auto authAndAccess5(Container && c, Index i) -> decltype(std::forward<Container>(c)[i]) {
	return std::forward<Container>(c)[i];
}


auto createUsers() {
	auto users = std::make_shared<std::vector<int>>();
	for (int i = 0; i < 5; i++) {
		users->push_back(i);
	}
	return users;
}

auto createUsers2() {
	std::vector<int> users = { 1,2,3,4,5 };
	return users;
}

decltype(auto) f1() {
	int y = 5;
	int & x = y;
	return x;
}

auto f2() {
	int y = 5;
	int & x = y;
	return x;
}

int main()
{
	auto users2 = createUsers();
	auto users2_2 = createUsers2();
	std::vector<int> users = { 1,2,3,4,5 };
	//authAndAccess1(users, 1) = 10; // DOES NOT COMPILE

	authAndAccess2(users, 1) = 10;

	authAndAccess3(users, 1) = 10;

	//authAndAccess3(createUsers2(), 1) = 10; // DOES NOT COMPILE

	auto s = authAndAccess4(createUsers2(), 1);

	auto s2 = authAndAccess5(createUsers2(), 1);

	auto & ret1 = f1();
	auto ret2 = f1();

	auto ret3 = f2();

    return 0;
}

