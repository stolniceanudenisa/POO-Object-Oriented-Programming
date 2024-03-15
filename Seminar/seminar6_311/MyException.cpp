//
// Created by user on 18-May-23.
//

#include "MyException.h"

MyException::MyException(const char *msg) {
    if(msg != nullptr) {
        this->msg = new char[strlen(msg) + 1];
        strcpy(this->msg, msg);
    }
}

MyException::~MyException() {
    if (msg != nullptr){
        delete[] msg;
    }
}

const char *MyException::what() throw() {
    return msg;
}
