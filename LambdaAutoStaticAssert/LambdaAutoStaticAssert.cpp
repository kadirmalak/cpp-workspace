// LambdaAutoStaticAssert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>

using namespace std;

void ex1() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });
}

void ex2() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	deque<int> d;
	transform(v.begin(), v.end(), front_inserter(d), [](int n) {return n*n*n; });
	for_each(d.begin(), d.end(), [](int n) {cout << n << " "; });
}

void ex3() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	deque<int> d;
	transform(v.begin(), v.end(), front_inserter(d), [](int n) -> double { // explicit return type
		if (n % 2 == 0) {
			return n*n*n;
		}
		else {
			return n / 2.0;
		}
	});
	for_each(d.begin(), d.end(), [](int n) {cout << n << " "; });
}

const string* addr;

void mutate(string & str) {

}

void observe(const string & str) {
	cout << "string: " << str.c_str() << endl;
	cout << "address: " << &str << endl;
	addr = &str;
}

void ex4() {
	observe("hello");
	cout << "*addr: " << (*addr).c_str() << endl;
}

string three() { return "three"; }
const string four() { return "four"; }

void ex5() {
	string one("one");
	const string two("two");
	
	mutate(one);
	//mutate(two);
	mutate(three());
	//mutate(four());
	//mutate("five");

	observe(one);
	observe(two);
	observe(three());
	observe(four());
	observe("five");
}

int main()
{
	ex5();

    return 0;
}

