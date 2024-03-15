//
// Created by user on 25-May-23.
//

#ifndef SEM_6_313_MYEXCEPTION_H
#define SEM_6_313_MYEXCEPTION_H
#include <exception>
#include <cstring>

class MyException : public std::exception{
protected:
    char* msg;
public:
    MyException(const char* msg);
    char* what() const throw();
    ~MyException();
};


#endif //SEM_6_313_MYEXCEPTION_H
