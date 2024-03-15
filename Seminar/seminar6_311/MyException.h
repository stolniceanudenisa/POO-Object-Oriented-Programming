//
// Created by user on 18-May-23.
//

#ifndef SEMINAR6_311_MYEXCEPTION_H
#define SEMINAR6_311_MYEXCEPTION_H
#include <exception>
#include <string>
#include <cstring>



using namespace std;

class MyException {
private:
    char* msg;
public:
    const char* what() throw ();
    MyException(const char* msg);
    ~MyException();
};


#endif //SEMINAR6_311_MYEXCEPTION_H
