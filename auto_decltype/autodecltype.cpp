// autodecltype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Trace.h"
#include <string>

using namespace std;

//void changeStr(string & ref)
//{
//	ref = string{ "changed!!!" };
//}
//
//void useStr(const string & ref)
//{
//	ref = string{ "this should be erroneous" };
//}

int main()
{
	auto s = string{};

	s = basic_string<char>{};

	auto ws = wstring{};

	ws = basic_string<wchar_t>{};

	// already checked by the compiler prior to linking
	static_assert(sizeof(string::value_type) == 1, "1 byte");
	static_assert(sizeof(wstring::value_type) == 2, "1 byte");

	s = string{ "sample" };

	ASSERT(!s.empty());
	ASSERT(s.size() == 6);

	TRACE(L"%S\n", s.c_str());

	s = string{ 'h', 'e', 'l', 'l', 'o' };

	TRACE(L"%S\n", s.c_str());

	s.clear();

	ASSERT(s.empty());
	ASSERT(s.size() == 0);
	ASSERT(0 == strcmp(s.c_str(), ""));

	s = string{ "some big string" };
	auto sub = string{ s, 5, 3 };

	ASSERT(sub == "big");

	for (auto c : sub) {
		TRACE(L"%C\n", c);
	}

	auto user = string{ "kadirmalak" };
	auto domain = string{ "gmail.com" };
	auto id = user + "@" + domain;

	TRACE(L"%S\n", id.c_str());

	auto pos = id.find('@');
	auto temp = id.substr(pos);

	ASSERT(temp == "@gmail.com");

    return 0;
}

