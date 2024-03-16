#include "NotFoundException.h"

NotFoundException::NotFoundException(string msg)
{
	this->message = msg;
}

const char* NotFoundException::what()
{
	return this->message.c_str();
}
