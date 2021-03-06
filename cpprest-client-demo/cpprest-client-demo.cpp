// cpprest-client-demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	using namespace web;
	using namespace web::http;
	using namespace web::http::client;
	using namespace concurrency::streams;

	http_client client(U("http://bing.com"));
	
	uri_builder builder(U("/search"));
	builder.append_query(U("q"), U("cpprestsdk github"));

	container_buffer<std::string> buffer;

	client.request(methods::GET, builder.to_string()).then([=](http_response response) {
		std::cout << "status: " << response.status_code() << std::endl;
		return response.body().read_to_end(buffer);
	}).then([=](size_t) {
		std::cout << "response: " << buffer.collection().substr(0, 100) << std::endl;
	}).wait();

    return 0;
}

