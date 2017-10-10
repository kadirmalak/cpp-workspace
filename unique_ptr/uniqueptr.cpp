// uniqueptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;
//using std::unique_ptr;

struct Hen
{
	unsigned id;
	float eggs;

	Hen(unsigned id, float eggs) : id(id), eggs(eggs)
	{}

	~Hen()
	{
		cout << "Hen " << id << " is destroyed" << endl;
	}

	void Update(unsigned newId, float newEggs)
	{
		this->id = newId;
		this->eggs = newEggs;
	}
};

unique_ptr<Hen> GetHen()
{
	return make_unique<Hen>(3, 9.99);
}

unique_ptr<Hen> UpdateHen(unique_ptr<Hen> hen)
{
	hen->eggs *= 2;
	return hen;
}

int main()
{
	//auto sp = unique_ptr<int>{ new int {123} };
	//auto sp = make_unique<int>(123);

	auto hen = make_unique<Hen>(1, 13.5);
	auto hen2 = move(hen);

	if (hen)
	{
		cout << "hen owns the object" << endl;
	}
	
	if (hen2) {
		cout << "hen2 owns the object" << endl;
	}

	cout << "-----------------------" << endl;

	Hen copyOfHen = *hen2;
	copyOfHen.eggs += 1;

	Hen & ref = *hen2;
	ref.eggs += 2;

	Hen* ptr = hen2.release();

	if (hen)
	{
		cout << "hen owns the object" << endl;
	}

	if (hen2) {
		cout << "hen2 owns the object" << endl;
	}

	if (ptr) {
		cout << "ptr owns the object" << endl;
	}

	cout << "-----------------------" << endl;

	hen.reset(ptr);

	if (hen)
	{
		cout << "hen owns the object" << endl;
	}

	if (hen2) {
		cout << "hen2 owns the object" << endl;
	}

	if (ptr) {
		cout << "ptr owns the object" << endl;
	}

	auto newHen = GetHen();
	cout << "newHen->eggs: " << newHen->eggs << endl;

	newHen = UpdateHen(move(newHen));
	cout << "newHen->eggs: " << newHen->eggs << endl;

	newHen->Update(99, 333);
	cout << "newHen->eggs: " << newHen->eggs << endl;

    return 0;
}

