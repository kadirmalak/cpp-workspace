// CmdParse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <regex>
#include <memory>

using namespace std;

class Command {
public:
	Command(const string & exp_) : exp(regex("^" + exp_ + "$")), expStr(exp_) {}
	~Command() {
		cout << "command " << expStr << " destructed!" << endl;
	}
	bool IsMatch(const string & input) {
		return regex_search(input, matches, exp);
	}
	virtual void operator()(){}
protected:
	smatch matches;
private:
	regex exp;
	string expStr;
};

class ListBoardsCommand : public Command {
public:
	ListBoardsCommand() : Command("boards list (\\d+)") {}
	virtual void operator()() {
		int id = stoi(matches.str(1));
		cout << "listing board " << id << " ..." << endl;
	}
};

class DeleteBoardCommand : public Command {
public:
	DeleteBoardCommand() : Command("board delete ([a-zA-Z0-9]+)") {}
	virtual void operator()() {
		auto id = matches.str(1);
		cout << "deleting board " << id << " ..." << endl;
	}
};

class AddBoardCommand : public Command {
public:
	AddBoardCommand() : Command("boards add") {}
	virtual void operator()() {
		cout << "adding board..." << endl;
	}
};

int main(int argc, char* argv[])
{
	auto commands = vector< shared_ptr<Command> >();
	auto cmd1 = make_shared<ListBoardsCommand>();
	auto cmd2 = make_shared<AddBoardCommand>();
	auto cmd3 = make_shared<DeleteBoardCommand>();

	commands.push_back(cmd1);
	commands.push_back(cmd2);
	commands.push_back(cmd3);

	string input;
	bool didFind;
	while (true) {
		cout << "> ";
		getline(cin, input);

		if (input.compare("exit") == 0) {
			cout << "exiting..." << endl;
			break;
		}
		
		didFind = false;
		for (auto& command : commands) {
			if (command->IsMatch(input)) {
				(*command)();
				didFind = true;
			}
		}

		if (!didFind) {
			cout << "command not found!" << endl;
		}
	}

	/*for (int i = 1; i < argc; i++) {
		cout << argv[i] << endl;
	}*/

    return 0;
}

