#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;
using namespace std;

string response;

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) 
{
	size_t len = size * nmemb;
	response.append(ptr, len);
	return len;
}

int main(void)
{
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, 
			"https://api.trello.com/1/boards/bw9e78Bf/lists?cards=open&key=49e05d1c8b8d8bccb6d54d45828bcf8d&token=e61c1d50c3c9a1adf7001a11ca00243bc6b52e1d92240d771f98db414c70caa0");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
#ifdef SKIP_PEER_VERIFICATION
		/*
		* If you want to connect to a site who isn't using a certificate that is
		* signed by one of the certs in the CA bundle you have, you can skip the
		* verification of the server's certificate. This makes the connection
		* A LOT LESS SECURE.
		*
		* If you have a CA cert for the server stored someplace else than in the
		* default bundle, then the CURLOPT_CAPATH option might come handy for
		* you.
		*/
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
		/*
		* If the site you're connecting to uses a different host name that what
		* they have mentioned in their server certificate's commonName (or
		* subjectAltName) fields, libcurl will refuse to connect. You can skip
		* this check, but this will make the connection less secure.
		*/
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
		else
		{
			Document d;
			d.Parse(response.c_str());

			if (!d.HasParseError()) {
				fprintf(stdout, "lists:\n");
				for (auto& listVal : d.GetArray())
				{
					fprintf(stdout, " - %s\n", listVal.GetObjectW()["name"].GetString());
				}
			}
		}

		/* always cleanup */
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return 0;
}
