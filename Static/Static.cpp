// Static.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class A {
public:
	static string str;

	void SomeMethod() {
		A::str = "hello";
		cout << "str: " << A::str << endl;
	}
};

int main()
{
	A a;
	a.SomeMethod();
    return 0;
}

