// Functional.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <memory>
#include <list>

#include "gtest/gtest.h"
#include "Functional.h"

using namespace std;
using namespace testing;
using namespace testing::internal;
using namespace kadir;

class FunctionalTests : public Test {
protected:
	vector<string> v{"some", "things", "cannot", "change", "easily", "you", "know"};
	list<string> l{ "change", "is", "what", "we", "need" };
	FunctionalTests() {
	}
};

TEST_F(FunctionalTests, ListUsage) {
	auto modified = fmap(l, [](const string & s) {
		return s + "x";
	});
	ASSERT_EQ(l.size(), modified->size());
	ASSERT_STREQ("changex", modified->front().c_str());
}

TEST_F(FunctionalTests, Filter) {
	auto filtered = ffilter(l, [](const string & s) {
		return s.length() > 3;
	});
	ASSERT_EQ(3, filtered->size());
}

TEST_F(FunctionalTests, FilterMap) {
	auto filtered = ffilter(l, [](const string & s) {
		return s.length() > 3;
	});
	auto newList = fmap(*filtered.get(), [](const string & s) {
		return s + "x";
	});
	ASSERT_EQ(3, newList->size());
	ASSERT_STREQ("changex", newList->front().c_str());
;}

TEST_F(FunctionalTests, map) {
	auto modified = fmap(v, [](const string & s) {
		return s + "x";
	});
	ASSERT_TRUE(v.size() == modified->size());
}

TEST_F(FunctionalTests, for_each) {
	int i = 0;
	ffor_each(v, [&i](const string & s) {
		i++;
	});
	ASSERT_EQ(v.size(), i);
}

TEST_F(FunctionalTests, SampleTest) {
	ASSERT_EQ(7, v.size());
}

int main(int argc, char** argv)
{
	InitGoogleTest(&argc, argv);
	auto res = RUN_ALL_TESTS();
	println("press enter key to exit...");
	string line;
	getline(cin, line);
	return res;
}

