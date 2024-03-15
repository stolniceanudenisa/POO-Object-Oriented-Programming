//
// Created by user on 25-May-23.
//

#include "MyException.h"

MyException::MyException(const char *msg) {
    this->msg = new char [strlen(msg)+1];
    strcpy(this->msg,msg);
}

char *MyException::what() const throw() {
    return msg;
}

MyException::~MyException() {
    if(msg != nullptr)
        delete [] msg;
}
