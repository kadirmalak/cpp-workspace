// effective_pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <memory>
#include <iostream>

class A {
public:
	A(const std::string & value) : _value(value) {
		std::cout << "A ctor called, value: " << _value << std::endl;
	}
private:
	std::string _value;
};

class Investment {
public:
	Investment(const A & name, int amount) 
		: _name(name), _amount(amount) {
		std::cout 
			<< "constructing Investment with name(" 
			<< &name 
			<< ") and amount(" 
			<< &amount 
			<< ")" 
			<< std::endl;
	}
private:
	A _name;
	int _amount;
};

template<typename... Ts>
std::unique_ptr<Investment> makeInvestment(Ts&&... params) {
	return std::make_unique<Investment>(params...);
}

template<typename... Ts>
auto makeInvestment2(Ts&&... params) {
	return std::make_unique<Investment>(params...); // FORWARD kullanmayınca ne oluyor?
}

template<typename... Ts>
auto makeInvestment3(Ts&&... params) {
	return std::make_unique<Investment>(std::forward<Ts>(params)...);
}

auto my_deleter = [](Investment* investment) {
	std::cout << "deleting investment!" << std::endl;
	delete investment;
};

template<typename... Ts>
std::unique_ptr<Investment, decltype(my_deleter)> 
makeInvestment4(Ts&&... params) {
	std::unique_ptr<Investment, decltype(my_deleter)> sptr(nullptr, my_deleter);
	sptr.reset(new Investment(std::forward<Ts>(params)...));
	return sptr;
}

template<typename... Ts>
auto makeInvestment5(Ts&&... params) {
	std::unique_ptr<Investment, decltype(my_deleter)> sptr(nullptr, my_deleter);
	sptr.reset(new Investment(std::forward<Ts>(params)...));
	return sptr;
}


int main()
{
	//auto investment = makeInvestment("an investment", 123);
	//auto investment2 = makeInvestment2(A("another investment"), 234);
	//auto investment3 = makeInvestment3(A("yet another"), 345);


	auto investment4 = makeInvestment4(A("custom deleter"), 456);
	auto investment5 = makeInvestment5(A("custom deleter"), 456);

    return 0;
}

