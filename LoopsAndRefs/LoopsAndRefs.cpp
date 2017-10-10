// LoopsAndRefs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> v;
	v.push_back("some string");
	v.push_back("some other string");
	v.push_back("yet another string");

	cout << "&(v[" << 0 << "]): " << &(v[0]) << endl;
	cout << "&(v[" << 1 << "]): " << &(v[1]) << endl;
	cout << "&(v[" << 2 << "]): " << &(v[2]) << endl;

	cout << "---" << endl;

	int i = 0;
	for (auto s : v) {
		cout << "&s: " << &s << endl;
		i++;
	}

	cout << "---" << endl;

	i = 0;
	for (const string & s : v) {
		cout << "&s: " << &s << endl;
		i++;
	}

	cout << "---" << endl;

	for_each(v.begin(), v.end(), [](string s) {
		cout << "&s: " << &s << endl;
	});

	cout << "---" << endl;

	for_each(v.begin(), v.end(), [](const string & s) {
		cout << "&s: " << &s << endl;
	});

    return 0;
}

