// MockDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;
using namespace testing::internal;
using namespace std;

template <typename T>
void println(const T & t) {
	cout << t << endl;
}

class Turtle {
public:
	virtual ~Turtle() {}
	virtual void PenUp() = 0;
	virtual void PenDown() = 0;
	virtual void Forward(int distance) = 0;
	virtual void Turn(int degrees) = 0;
	virtual void GoTo(int x, int y) = 0;
	virtual int GetX() const = 0;
	virtual int GetY() const = 0;
};

class MockTurtle : public Turtle {
public:
	MOCK_METHOD0(PenUp, void());
	MOCK_METHOD0(PenDown, void());
	MOCK_METHOD1(Forward, void(int distance));
	MOCK_METHOD1(Turn, void(int degrees));
	MOCK_METHOD2(GoTo, void(int x, int y));
	MOCK_CONST_METHOD0(GetX, int());
	MOCK_CONST_METHOD0(GetY, int());
};

class Program {
public:
	Program(Turtle & turtle) {
		turtle.PenDown();
	}
};

TEST(PainterTest, CanDrawSomething) {
	MockTurtle turtle;

	// first expect
	EXPECT_CALL(turtle, PenDown())
		.Times(AtLeast(2));
	
	// then call
	Program program(turtle);
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
