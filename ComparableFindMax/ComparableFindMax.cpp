// ComparableFindMax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename Comparable>
const Comparable & findMax(const vector<Comparable> & arr)
{
	int maxIndex = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}
	}
	return arr[maxIndex];
}

class Employee
{
public:
	void setValue(const string & n, int s)
	{
		_name = n;
		_salary = s;
	}

	bool operator < (const Employee & rhs) const // buradaki const önemli
	{
		return _salary < rhs._salary;
	}

	void print(ostream & out) const
	{
		out << _name << " (" << _salary << ")";
	}

private:
	string _name;
	int _salary;
};

ostream & operator << (ostream & out, const Employee & rhs)
{
	rhs.print(out);
	return out;
}


int main()
{
	vector<Employee> employees(3);
	employees[0].setValue("kadir malak", 1500);
	employees[1].setValue("orhan dalak", 3000);

	cout << findMax(employees) << endl;

    return 0;
}

