// RestDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

int main(int argc, char* argv[])
{
	auto fileStream = std::make_shared<ostream>();

	pplx::task<void> requestTask = fstream::open_ostream(U("results.html"))
		.then([=](ostream outFile) {
			*fileStream = outFile;
			http_client client(U("http://www.bing.com/"));
			uri_builder builder(U("/search"));
			builder.append_query(U("q"), U("cpprestsdk github"));
			return client.request(methods::GET, builder.to_string());
		})
		.then([=](http_response response) {
			printf("received response status code: %u\n", response.status_code());
			return response.body().read_to_end(fileStream->streambuf());
		})
		.then([=](size_t) {
			fileStream->close();
		});

	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception: %s\n", e.what());
	}

    return 0;
}

