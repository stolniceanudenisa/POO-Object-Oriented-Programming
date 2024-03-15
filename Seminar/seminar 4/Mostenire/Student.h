//
// Created by user on 27-Apr-23.
//

#ifndef UNTITLED1_STUDENT_H
#define UNTITLED1_STUDENT_H

#include <string>
using namespace std;

class Student {
protected:
    int nrMatricol;
    string nume;
public:
    Student();
    Student(int ,string);
    Student(const Student&);
    int getMatricol();
    void setMatricol(int);
    string getNume();
    void setNume(string);
    Student& operator=(const Student&);
    bool operator==(const Student&);
    bool operator<(const Student&);
    string tostring();
    ~Student();
};


#endif //UNTITLED1_STUDENT_H
