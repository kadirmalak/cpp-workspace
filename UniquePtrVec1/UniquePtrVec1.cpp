// UniquePtrVec1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A {
  public:
	A(int val) : value(val) {
		cout << "constructor(" << value << ") called!" << endl;
	}
	~A() {
		cout << "destructor(" << value << ") called!" << endl;
	}
	virtual string GetValue() {
		return "hello from class A";
	}
	friend unique_ptr<A> modify(unique_ptr<A> a);
	friend void modify2(shared_ptr<A> a);
  private:
	int value;
};

class B : public A {
public:
	B(int val) : A(val){}
	virtual string GetValue() {
		return "hello from class B";
	}
};

unique_ptr<A> modify(unique_ptr<A> a) {
	a->value++;
	return a;
}

void modify2(shared_ptr<A> a) {
	a->value *= 9;
}

int main()
{
	auto list = vector< unique_ptr<A> >();
	list.push_back(move(make_unique<A>(11)));
	list.push_back(move(make_unique<B>(12)));

	for (auto& item : list) {
		cout << item->GetValue().c_str() << endl;
	}

	A* ptr = new A(1);
	auto uptr = unique_ptr<A>{ new A(2) };
	uptr = modify(move(uptr));
	auto sptr = shared_ptr<A>{ new A(3) };
	modify2(sptr);
	delete ptr;
    return 0;
}

