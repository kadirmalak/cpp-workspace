// WeakPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

weak_ptr<int> gw;

void observe() {
	cout << "use count: " << gw.use_count() << endl;
	if (auto spt = gw.lock()) {
		cout << "val: " << *spt << endl;
	}
	else {
		cout << "gw is expired!" << endl;
	}
	cout << endl;
}

int main()
{
	{
		auto sp = make_shared<int>(42);
		gw = sp;
		observe();
	}
	observe();
    return 0;
}

