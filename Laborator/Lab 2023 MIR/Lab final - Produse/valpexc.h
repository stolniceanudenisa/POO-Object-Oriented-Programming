#pragma once

#include <exception>
#include <string>

using namespace std;


class ValidationException : public exception {
private:
	string message;
public:
	ValidationException(string msg);
	const char* what();
};


//
//class ValidationException {
//private:
//	string message;
//public:
//	ValidationException(string msg) : message(msg)
//	{}
//
//	string toString()
//	{
//		return message;
//	}
//};
