// Structs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <crtdbg.h>
#include <iostream>

using namespace std;

#define ASSERT _ASSERTE

struct Employee
{
	short id = -1;
	int age = 0;
	double wage = 0;
};

struct Company
{
	Employee CEO;
	int numberOfEmployees = 0;

	Company()
	{
		cout << "Parameterless Company constructor called!" << endl;
	}

	Company(Employee CEO, int numberOfEmployees) : 
		CEO(CEO), numberOfEmployees(numberOfEmployees)
	{
		cout << "A company with CEO " << CEO.id << " is being created!" << endl;
	}

	~Company()
	{
		cout << "A company with CEO " << CEO.id << " is being destroyed!" << endl;
	}
};

struct Triangle {
	double length = 1.0;
	double width = 1.0;
};

void printInformation(Employee e) {
	cout << "ID  : " << e.id << endl;
	cout << "Age : " << e.age << endl;
	cout << "Wage: " << e.wage << endl;
}


int main()
{
	Triangle x; // 1.0, 1.0
	ASSERT(x.length < 2 && x.length > 0);
	x = { 3, 5 };
	printf("triangle l: %.2f, %.2f\n", x.length, x.width);

	//Employee joe;
	//joe.id = 14;
	//joe.age = 31;
	//joe.wage = 5000;

	//Employee joe = { 1, 31, 10000 };
	Employee joe{ 1, 31, 10000 };

	printInformation(joe);

	//Employee frank;
	//frank.id = 15;
	//frank.age = 22;
	//frank.wage = 3000;

	Employee frank = { 2, 20 };

	ASSERT(joe.wage > frank.wage);
	ASSERT(frank.wage < 1);

	Company company = { {1, 42, 100000}, 13 };
	ASSERT(company.CEO.age == 42);
	ASSERT(company.numberOfEmployees == 13);

	Company emptyCompany;
	ASSERT(emptyCompany.numberOfEmployees == 0);

	printf("finished...\n");
	printf("%.2f", 1.0 / 3);

	auto result = 1.0 / 3;

    return 0;
}

