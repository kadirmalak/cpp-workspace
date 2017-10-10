// CopyMoveConstructor1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct A
{
	std::string s;
	A() : s("test") { }
	A(const A& o) : s(o.s) { 
		cout << "move failed!\n"; 
	}
	A(A&& o) noexcept : s(move(o.s)) { }
};

A f(A a)
{
	return a;
}

int main()
{
	cout << "Trying to move A\n";
	A a1 = f(A()); // move-constructs from rvalue temporary
	A a2 = move(a1); // move-constructs from xvalue
    return 0;
}

