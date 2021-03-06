// precompiled-demo-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

namespace logging = boost::log;

void init()
{
	logging::core::get()->set_filter
	(

		logging::trivial::severity >= logging::trivial::info
	);
}

int main()
{
	init();

	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
	BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
	BOOST_LOG_TRIVIAL(info) << "An informational severity message";
	BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
	BOOST_LOG_TRIVIAL(error) << "An error severity message";
	BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    return 0;
}

