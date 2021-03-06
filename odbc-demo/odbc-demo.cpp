/*
	based on 
	https://github.com/Microsoft/VCSamples/blob/master/VC2015Samples/ODBC%20database%20sample%20(linux)/odbcconnector/odbcconnector.c
*/

#include "stdafx.h"
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <stdlib.h>
#include <sal.h>
#include <iostream>

#define RESULT_LEN  256

void extract_error(char *desc, SQLHANDLE handle, SQLSMALLINT type)
{
	SQLINTEGER i = 0;
	SQLINTEGER NativeError;
	SQLTCHAR SQLState[7];
	SQLTCHAR MessageText[256];
	SQLSMALLINT TextLength;
	SQLRETURN ret;

	fprintf(stderr, "\nThe driver reported the following error %s\n", desc);
	do
	{
		ret = SQLGetDiagRec(type, handle, ++i, SQLState, &NativeError,
			MessageText, sizeof(MessageText), &TextLength);
		if (SQL_SUCCEEDED(ret)) {
			printf("%s:%ld:%ld:%s\n",
				SQLState, (long)i, (long)NativeError, MessageText);
		}
	} while (ret == SQL_SUCCESS);
}

void CHECK_ERROR(SQLRETURN code, char *desc, SQLHANDLE handle, SQLSMALLINT type) {
	if (code != SQL_SUCCESS && code != SQL_SUCCESS_WITH_INFO) { 
		extract_error(desc, handle, type);
		throw std::exception();
	}
}

int main() {
	auto connStr = L"DSN=localhost-deneme";

	SQLHENV   henv = SQL_NULL_HENV;   // Environment
	SQLHDBC   hdbc = SQL_NULL_HDBC;   // Connection handle
	SQLHSTMT  hstmt = SQL_NULL_HSTMT;  // Statement handle
	SQLRETURN retcode, retcode1, retcode2, retcode3;
	
	SQLTCHAR outstr[1024];
	SQLSMALLINT outstrlen;
	int i = 0;

	try {
		// Allocate environment handle
		retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
		CHECK_ERROR(retcode, "SQLAllocHandle(SQL_HANDLE_ENV)", henv, SQL_HANDLE_ENV);
		// Set the ODBC version environment attribute
		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
			(SQLPOINTER*)SQL_OV_ODBC3, 0);
		CHECK_ERROR(retcode, "SQLSetEnvAttr(SQL_ATTR_ODBC_VERSION)",
			henv, SQL_HANDLE_ENV);

		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
			(SQLPOINTER*)SQL_OV_ODBC3, 0);
		CHECK_ERROR(retcode, "SQLSetEnvAttr(SQL_ATTR_ODBC_VERSION)",
			henv, SQL_HANDLE_ENV);
		// Allocate connection handle
		retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
		CHECK_ERROR(retcode, "SQLAllocHandle(SQL_HANDLE_DBC)",
			hdbc, SQL_HANDLE_DBC);
		// Set login timeout to 5 seconds
		SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);
		CHECK_ERROR(retcode, "SQLSetConnectAttr(SQL_LOGIN_TIMEOUT)",
			hdbc, SQL_HANDLE_DBC);
		// Connect to data source, replace with your connection string
		retcode = SQLDriverConnect(hdbc, NULL, (SQLTCHAR*)connStr, SQL_NTS, outstr, sizeof(outstr), &outstrlen, SQL_DRIVER_NOPROMPT);
		// Allocate statement handle
		retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		CHECK_ERROR(retcode, "SQLAllocHandle(SQL_HANDLE_STMT)",
			hstmt, SQL_HANDLE_STMT);
		retcode = SQLExecDirect(hstmt,
			(SQLTCHAR*) L"SELECT TOP 3 Id, Title, Author from dbo.Books", SQL_NTS);
		CHECK_ERROR(retcode, "SQLExecDirect()", hstmt, SQL_HANDLE_STMT);

		// Bind columns

		SQLTCHAR strResult1[RESULT_LEN];
		SQLTCHAR strResult2[RESULT_LEN];
		SQLTCHAR strResult3[RESULT_LEN];

		SQLBindCol(hstmt, 1, SQL_C_TCHAR, &strResult1, RESULT_LEN, 0);
		SQLBindCol(hstmt, 2, SQL_C_TCHAR, &strResult2, RESULT_LEN, 0);
		SQLBindCol(hstmt, 3, SQL_C_TCHAR, &strResult3, RESULT_LEN, 0);

		// Fetch and print each row of data until SQL_NO_DATA returned.
		for (i = 0; ; i++) {
			retcode = SQLFetch(hstmt);
			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
				wprintf(L"Result is: %s\n", strResult1);
				wprintf(L"Result is: %s\n", strResult2);
				wprintf(L"Result is: %s\n", strResult3);
			}
			else {
				if (retcode != SQL_NO_DATA) {
					CHECK_ERROR(retcode, "SQLFetch()", hstmt, SQL_HANDLE_STMT);
				}
				else {
					break;
				}
			}
		}
	}
	catch (const std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	printf("\nComplete.\n");
	// Free handles
	// Statement
	if (hstmt != SQL_NULL_HSTMT)
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	// Connection
	if (hdbc != SQL_NULL_HDBC) {
		SQLDisconnect(hdbc);
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	}
	// Environment
	if (henv != SQL_NULL_HENV)
		SQLFreeHandle(SQL_HANDLE_ENV, henv);

	return 0;
}
