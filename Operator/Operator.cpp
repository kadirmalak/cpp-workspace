// Operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Accumulator
{
	int counter = 0;
	auto operator()(int i) { return counter += i; }
	auto operator()() { return "hello"; }
};


int main()
{
	/*
	bu sayede farklý parametre tipleri ile farklý
	çalýþan fonksiyonlar yazýlabilir
	*/
	Accumulator acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl;
	cout << acc() << endl;

    return 0;
}

