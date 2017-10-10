// UnitTestDemo.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;
using namespace testing;
using namespace testing::internal;

int factorial(int n)
{
	if (n < 2) return 1;

	return n * factorial(n - 1);
}

TEST(_, FactorialHandlesZeroInput) {
	EXPECT_EQ(1, factorial(0));
}

TEST(_, FactorialHandlesPositiveInput) {
	EXPECT_EQ(1, factorial(1));
	EXPECT_EQ(2, factorial(2));
	EXPECT_EQ(6, factorial(3));
	EXPECT_EQ(24, factorial(4));
	EXPECT_EQ(120, factorial(5));
}

TEST(_, StringWideCharSupport) {
	ASSERT_STRCASEEQ("öçþýðü", "ÖÇÞÝÐÜ");
}

class FactorialTest : public Test {
protected:

	FactorialTest() {
		cout << "test constructor called!" << endl;
	}

	~FactorialTest() {
		cout << "test destructor called!" << endl;
	}

	virtual void SetUp() {
		sampleData.push_back(1);
		sampleData.push_back(2);
		sampleData.push_back(3);
		cout << "test set up called!" << endl;
	}

	virtual void TearDown() {
		cout << "test tear down called!" << endl;
	}

	vector<int> sampleData;
};

TEST_F(FactorialTest, IsFilledUp) {
	ASSERT_EQ(3, sampleData.size());
}

TEST_F(FactorialTest, RemoveElement) {
	sampleData.pop_back();
	ASSERT_EQ(2, sampleData.size());
}

int main(int argc, char** argv)
{
	InitGoogleTest(&argc, argv);
	auto res = RUN_ALL_TESTS();
	string line;
	getline(cin, line);
	cout << "press enter key to exit..." << endl;
	return res;
}
