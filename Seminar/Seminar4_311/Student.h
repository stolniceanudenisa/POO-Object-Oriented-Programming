//
// Created by user on 4/13/2023.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include<cstring>
#include <string>

using namespace std;

class Student {
private:
    string nume;
    int matricol;
public:
    Student();
    Student(string nume, int matricol);
    Student(const Student& student);
    string getNume();
    int getMatricol();
    void setNume(string nume);
    void setMatricol(int matricol);
    Student& operator=(const Student& student);
    bool operator==(const Student& student);
    bool operator<(const Student& student);
    string ToString();
    ~Student();
};


#endif //UNTITLED_STUDENT_H
