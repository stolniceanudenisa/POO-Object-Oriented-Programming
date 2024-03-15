//
// Created by user on 27-Apr-23.
//

#include "Student.h"

Student::Student() {
    nume="";
    nrMatricol=-1;
}

Student::Student(int nr, string nume) {
    nrMatricol=nr;
    this->nume=nume;
}

Student::Student(const Student & student) {
    nrMatricol= student.nrMatricol;
    nume=student.nume;
}

int Student::getMatricol() {
    return nrMatricol;
}

void Student::setMatricol(int nr) {
    nrMatricol=nr;
}

string Student::getNume() {
    return nume;
}

void Student::setNume(string name) {
    nume=name;
}

Student &Student::operator=(const Student & student) {
    if(this != &student)
    {
        nrMatricol=student.nrMatricol;
        nume=student.nume;
    }
    return *this;
}

bool Student::operator==(const Student &student) {
    return student.nrMatricol==nrMatricol&&student.nume==nume;
}

bool Student::operator<(const Student &student) {
    return nume<student.nume;
}

string Student::tostring() {
    return to_string(nrMatricol)+" "+nume;
}

Student::~Student() {
    nume="";
    nrMatricol=-1;
}
