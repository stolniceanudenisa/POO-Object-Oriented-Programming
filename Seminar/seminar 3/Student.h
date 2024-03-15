//
// Created by user on 4/6/2023.
//

#ifndef SEMINAR3_313_STUDENT_H
#define SEMINAR3_313_STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    string nume;
    double medie;
public:
    Student();
    Student(string, double);
    Student(const Student &);
    string getNume();
    double getMedie();
    void setNume(string);
    void setMedie(double);
    Student& operator=(const Student&);
    bool operator==(const Student&)const;
    bool operator<(const Student&);
    friend ostream& operator<<(ostream& os, const Student&s);//{
//        os<<s.nume<<" "<<s.medie;
//        return os;
//    }
    ~Student();
    string toString();





};


#endif //SEMINAR3_313_STUDENT_H
