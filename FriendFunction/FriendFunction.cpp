// FriendFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A {
public:
	A(int width_, int height_) : width(width_), height(height_) {}
	friend void printA(const A & a);
private:
	int width;
	int height;
};

void printA(const A & a) {
	cout << "A: (" << a.width << ", " << a.height << ")" << endl;
}

int main()
{
	A a(800, 600);
	printA(a);
    return 0;
}

