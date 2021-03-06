// override_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class base_class {
public:
	virtual void do_something() = 0;
	virtual void do_another_thing() {}
	virtual ~base_class() {}
};

class derived_class : public base_class {
public:
	void do_something() override;
	void do_another_thing() override;
};

void derived_class::do_something() {

}

void derived_class::do_another_thing() {

}


int main()
{
	auto obj = derived_class();
	obj.do_something();
	obj.do_another_thing();
    return 0;
}

