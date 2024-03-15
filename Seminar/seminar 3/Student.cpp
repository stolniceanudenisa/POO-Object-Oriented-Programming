//
// Created by user on 4/6/2023.
//

#include "Student.h"

Student::Student() {
    nume = "";
    medie = 0;

}

Student::Student(string new_nume, double new_medie) {
    nume = new_nume;
    medie = new_medie;

}

Student::Student(const Student &s) {
    nume = s.nume;
    medie = s.medie;

}

string Student::getNume() {
    return nume;
}

double Student::getMedie() {
    return medie;
}

void Student::setNume(string new_nume) {
    nume = new_nume;
}

void Student::setMedie(double new_medie) {
    medie = new_medie;
}

Student &Student::operator=(const Student &s) {
    if (this != &s)
    {
        nume = s.nume;
        medie = s.medie;
    }


}

bool Student::operator==(const Student &s) const {
    return (nume == s.nume && medie == s.medie);

}

bool Student::operator<(const Student &s) {
    return ( medie< s.medie);
}

ostream &operator<<(ostream &os, const Student &s) {
    os<<s.nume<<" "<<s.medie<<endl;
    return os;
}

Student::~Student() {}

string Student::toString() {
    return nume+" "+std::to_string(medie);
}
