// ExplicitConstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class IntCell
{
	int _storedValue;

public:
	explicit IntCell(int initialValue = 0) : _storedValue(initialValue) {
		cout << "explicit constructor called!" << endl;
	}
	int read() const { 
		//_storedValue++; const keyword prevents this!
		return _storedValue; 
	}
	void write(int x) { _storedValue = x; }
};

int main()
{
	IntCell obj;
	cout << "obj.read(): " << obj.read() << endl;

	IntCell obj2 = IntCell(1);
	cout << "obj2.read(): " << obj2.read() << endl;

	// explicit constructor prevents compilation
	/*IntCell temp = 3;
	cout << "temp.read(): " << temp.read() << endl;*/

	// explicit constructor prevents compilation
	//obj2 = 2;
	//cout << "obj2.read(): " << obj2.read() << endl;

	cout << "press enter key to exit...";
	string line;
	getline(cin, line);

    return 0;
}

