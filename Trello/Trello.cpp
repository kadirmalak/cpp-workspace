// Trello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Trace.h"
#include <string>
#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

using namespace std;

template <typename T>
T myreplace(T & s, T & stringToFind, T & replacement)
{
	return s.replace(s.find(stringToFind), stringToFind.length(), replacement);
}

int main()
{
	//_setmode(_fileno(stdout), _O_U16TEXT);

	auto baseUrl = U("https://api.trello.com/1");
	auto key = wstring{ U("49e05d1c8b8d8bccb6d54d45828bcf8d") };
	auto token = wstring{ U("e61c1d50c3c9a1adf7001a11ca00243bc6b52e1d92240d771f98db414c70caa0") };
	auto url = wstring{ U("/boards/bw9e78Bf/lists?cards=open&key={KEY}&token={TOKEN}") };
	
	url = myreplace(url, wstring{ U("{KEY}") }, key);
	url = myreplace(url, wstring{ U("{TOKEN}") }, token);

	http_client client(baseUrl);
	auto task = client.request(methods::GET, url.c_str()).then([](http_response response) {
		return response.extract_json();
	}).then([](json::value responseJson) {
		cout << "lists: " << endl;
		for (auto list : responseJson.as_array()) {
			auto name = list[U("name")].as_string();
			wcout << utility::string_t(U("name: ")) << name << endl;
		}
	});

	try
	{
		task.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception: %s\n", e.what());
	}

	cout << "Press enter key to exit..." << endl;
	string line;
	getline(cin, line);

    return 0;
}

