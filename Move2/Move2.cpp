// Move2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class A {
public:
	string s;
	A(string && str) : s(move(str)) {
		cout << "&str: " << &str << endl;
		cout << "&s: " << &s << endl;
	}
	A(const string & str) : s(str) {
		cout << "constructor called" << endl;
	}
	void change(string && str) {
		s = move(str);
	}
};

class B {
public:
	string s;
	B(string & str) : s(move(str)) {
		cout << "&str: " << &str << endl;
		cout << "&s: " << &s << endl;
	}
	void change(string & str) {
		s = move(str);
	}
};

class C {
public:
	string s;
	C(const string & str) : s(str) {
		cout << "&str: " << &str << endl;
		cout << "&s: " << &s << endl;
	}
	void change(const string & str) {
		s = str;
	}
};

void ex1() {
	A a("hello");
	a.change("mello");
	//B b("hello");
	//b.change("mello");
	C c("hello");
	c.change("mello");
}

void ex2() {
	B b(string("hello"));
	b.change(string("mello"));
}

void ex3() {
	string str1("hello");
	A a(str1);
	A a2("hello");
	B b(str1); // str1 deðerini bozuyor move yüzünden
	C c(str1);
}

int main()
{
	//ex1();
	//ex2();
	ex3();
    return 0;
}

