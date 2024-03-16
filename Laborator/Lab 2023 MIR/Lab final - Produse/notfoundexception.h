#pragma once
#include <exception>
#include <string>

using namespace std;

class NotFoundException : public exception {
private:
	string message;
public:
	NotFoundException(string msg);
	const char* what();
};
