// FunctionObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Employee
{
	void setValue(const string & n, int s)
	{
		name = n;
		salary = s;
	}

	void print(ostream & out) const //  TODO: bunu neden koyuyoruz anlamadým halen
	{
		out << name << " (" << salary << ")";
	}

	string name;
	int salary;
};

ostream & operator << (ostream & out, const Employee & emp)
{
	emp.print(out); // TODO: yukarýdaki const neden?
	return out;
}

template <typename T, typename Comparer>
const T & findMax(const vector<T> & arr, const Comparer & cmp)
{
	int maxIndex = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (cmp(arr[i], arr[maxIndex]) == 1)
		{
			maxIndex = i;
		}
	}
	return arr[maxIndex];
}

struct EmployeeComparer
{
	int operator () (const Employee & lhs, const Employee & rhs) const
	{
		if (lhs.salary < rhs.salary)
		{
			return -1;
		}
		else if (lhs.salary > rhs.salary)
		{
			return 1;
		}
		else {
			return 0;
		}
	}
};

int main()
{
	vector<Employee> employees{ 3 };
	employees[0].setValue("kadir malak", 1500);
	employees[1].setValue("orhan dalak", 3500);
	employees[2].setValue("hello mello", 2500);

	EmployeeComparer comparer;

	cout << "employee with max salary: " << findMax(employees, comparer) << endl;

    return 0;
}

