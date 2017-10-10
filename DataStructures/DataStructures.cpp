// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <list>

#include "gtest/gtest.h"

using namespace std;
using namespace testing;
using namespace testing::internal;

class VectorTests : public Test {
protected:
	vector<string> v;

	VectorTests() {
		v.push_back("some string");
		v.push_back("some other string");
		v.push_back("yet another string");
	}
};

class MapTests : public Test {
protected:
	map<string, string> m;

	MapTests() {
		m["some key"] = "some value";
		m["some other key"] = "some other value";
		m["yet another key"] = "yet another value";
	}
};

TEST_F(VectorTests, CopyPartial) {
	size_t count = 2;
	vector<string> other(count);
	copy(v.begin(), next(v.begin(), count), other.begin());
	ASSERT_EQ(count, other.size());
}

TEST_F(VectorTests, Filter) {
	vector<string> filtered(v.size());
	auto it3 = copy_if(v.begin(), v.end(), filtered.begin(), [](const string & str) {
		return str == string{ "some string" };
	});
	filtered.resize(distance(filtered.begin(), it3));
	ASSERT_EQ(1, filtered.size());
}

TEST_F(MapTests, SampleUsage) {
	ASSERT_STREQ("some value", m["some key"].c_str());
}

TEST_F(MapTests, SampleUsage2) {
	m.insert_or_assign("some key", "some value changed");
	ASSERT_STREQ("some value changed", m["some key"].c_str());
}

int main(int argc, char** argv)
{
	InitGoogleTest(&argc, argv);
	auto res = RUN_ALL_TESTS();
	cout << "press enter key to exit..." << endl;
	string line;
	getline(cin, line);
	return res;
}

