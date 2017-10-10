// Regex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <regex>

using namespace std;
using namespace std::regex_constants;

int main()
{
	regex pattern1("^boards list (\\d+)$");
	string input("boards list 123123");
	smatch matches;

	cout << (regex_search(input, matches, pattern1) ? "match!" : "mismatch...") << endl;
	for (auto match : matches) {
		cout << match << endl;
	}

	cout << "matches.size(): " << matches.size() << endl;

	auto idStr = matches.str(1);
	auto id = stoi(idStr);

	cout << "board id: " << id << endl;
    return 0;
}

