// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mutex>
#include <string>
#include <iostream>
#include <fstream>
#include <thread>

void f1() {
	static std::string someStaticString;
	if (someStaticString.empty()) {
		someStaticString = "hello";
	}
}

void f2() {
	std::string someString;
	if (someString.empty()) {
		someString = "hello";
	}
}

void write_to_file(const std::string & message, const std::string & threadName) {
	static std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);
	std::cout << "[" << threadName << "] opening file..." << std::endl;
	std::ofstream file("example.txt");
	if (!file.is_open()) {
		throw std::runtime_error("unable to open file");
	}
	file << message << std::endl;
	file.close();
	std::cout << "[" << threadName << "] closed file..." << std::endl;
}

int main()
{
	std::thread first(write_to_file, "hello", "first");
	std::thread second(write_to_file, "mello", "second");

	first.join();
	second.join();

    return 0;
}

