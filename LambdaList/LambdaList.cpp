// LambdaList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <functional>
#include <map>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Request {
public:
	Request(const string & path) : _path(path) {}
	const string & path() const { return _path; }
private:
	string _path;
};

class BaseController {
public:
	BaseController(){
		cout << "base controller constructed" << endl;
	}
	~BaseController(){
		cout << "base controller destructed" << endl;
	}
protected:
	void OnException(Request request, const exception & ex) {};
};

class SampleController : public BaseController {
public:
	SampleController() {
		cout << "sample controller created!" << endl;
	}
	~SampleController() {
		cout << "sample controller destructed!" << endl;
	}
	void login(Request request) {
		throw exception("some exception!");
	}
	void logout(Request request) {
		cout << "user logged out..." << endl;
	}
	void OnException(Request request, const exception & ex) {
		cout << "exception occurred in SampleController: " << request.path() << endl;
		cout << "exception: " << ex.what() << endl;
	}
};

struct RoutingRule {
	string url;
	function<void(const Request & request)> handler;
};

vector<RoutingRule> routingRules;

#define HANDLER(controller, action) [](Request request) {\
	auto c = controller();\
	try {\
		c.action(request);\
	} catch (const exception & ex) {\
		c.OnException(request, ex);\
	} catch (...) {\
		c.OnException(request, exception("unhandled exception"));\
	}\
}

void initRouting() {

	routingRules.push_back(RoutingRule{
		"user/login",
		HANDLER(SampleController, login)
	});

	routingRules.push_back(RoutingRule{
		"user/logout",
		HANDLER(SampleController, logout)
	});
}

int main()
{
	initRouting();

	Request request("user/login");

	for (auto & rule : routingRules) {
		if (request.path() != rule.url) {
			continue;
		}
		rule.handler(request);
	}

	Request request2("user/logout");

	for (auto & rule : routingRules) {
		if (request2.path() != rule.url) {
			continue;
		}
		rule.handler(request2);
	}

    return 0;
}

