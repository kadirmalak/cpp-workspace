// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

bool isLong(const string & str) {
	return str.length() > 15;
}

int main()
{
	vector<string> v;
	v.push_back(move("some string"));
	v.push_back(move("some other string"));
	v.push_back(move("third string"));

	vector<string> target;
	target.resize(v.size());

	transform(v.begin(), v.end(), target.begin(), [](const string & str){
		return str + "x";
	});
	cout << "transformed vector:" << endl;
	for_each(target.begin(), target.end(), [](const string & str) {
		cout << str << endl;
	});
	cout << "after find:" << endl;
	auto it = find(v.begin(), v.end(), "some string");
	if (it == v.end()) {
		cout << "some string not found!" << endl;
	}
	else {
		cout << "some string found!" << endl;
	}

	auto it2 = find_if(v.begin(), v.end(), [](const string & str) {
		return str.length() > 15;
	});
	cout << "first long string: " << *it2 << endl;

	vector<string> filtered(v.size());
	auto it3 = copy_if(v.begin(), v.end(), filtered.begin(), [](const string & str) {
		return str.length() > 15;
	});
	filtered.resize(distance(filtered.begin(), it3));

	cout << "filtered:" << endl;
	for (auto & item : filtered) {
		cout << "> " << item << endl;
	}

	cout << "iterate:" << endl;
	for (auto & i = v.begin(); i < v.end(); i++) {
		cout << *i << endl;
	}

    return 0;
}

