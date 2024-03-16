#include "valpexc.h"

ValidationException::ValidationException(string msg)
{
	this->message = msg;
}

const char* ValidationException::what()
{
	return this->message.c_str();
}
