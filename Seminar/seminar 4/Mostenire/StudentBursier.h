//
// Created by user on 27-Apr-23.
//

#ifndef UNTITLED1_STUDENTBURSIER_H
#define UNTITLED1_STUDENTBURSIER_H

#include "Student.h"

class StudentBursier : public Student {
private:
    string tip;
public:
    StudentBursier();
    StudentBursier(int,string,string);
    StudentBursier(const StudentBursier& );
    string getTip();
    void setTip(string);
    StudentBursier& operator=(const StudentBursier&);
    bool operator==(const StudentBursier&);
    bool operator<(const StudentBursier&);
    string toString();
    ~StudentBursier();
};


#endif //UNTITLED1_STUDENTBURSIER_H
