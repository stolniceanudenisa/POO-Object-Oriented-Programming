//
// Created by user on 4/13/2023.
//

#include "Student.h"

Student::Student() {
    nume = "";
    matricol = 0;
}

Student::Student(string nume, int matricol) {
    this->nume = nume;
    this->matricol = matricol;
}

Student::Student(const Student &student) {
    this->nume = student.nume;
    this->matricol = student.matricol;
}

string Student::getNume() {
    return this->nume;
}

int Student::getMatricol() {
    return this->matricol;
}

void Student::setNume(string nume) {
    this->nume = nume;
}

void Student::setMatricol(int matricol) {
    this->matricol = matricol;
}

Student &Student::operator=(const Student &student) {
    if(this!=&student){
        this->nume = student.nume;
        this->matricol = student.matricol;
    }
    return *this;
}

bool Student::operator==(const Student &student) {
    return (this->nume == student.nume and this->matricol == student.matricol);
}

bool Student::operator<(const Student &student) {
    return (this->nume<student.nume);
}

string Student::ToString() {
    return this->nume+" "+std::to_string(this->matricol);
}

Student::~Student() {

}
