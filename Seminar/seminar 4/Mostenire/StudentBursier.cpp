//
// Created by user on 27-Apr-23.
//

#include "StudentBursier.h"

StudentBursier::StudentBursier():Student() {
    tip="";
}

StudentBursier::StudentBursier(int nr, string name, string type):Student(nr,name) {
    tip=type;
}

StudentBursier::StudentBursier(const StudentBursier &student): Student(student) {
    tip=student.tip;
}

string StudentBursier::getTip() {
    return tip;
}

void StudentBursier::setTip(string type) {
    tip=type;
}

StudentBursier &StudentBursier::operator=(const StudentBursier &student) {
    if (this!=&student)
    {
        Student::operator=(student);
        tip=student.tip;
    }
    return *this;
}

bool StudentBursier::operator==(const StudentBursier &student) {
    return Student::operator==(student)&&tip==student.tip;
}

bool StudentBursier::operator<(const StudentBursier &student) {
    return tip<student.tip;
}

string StudentBursier::toString() {
    return Student::tostring()+" "+tip;
}

StudentBursier::~StudentBursier() {
    tip="";
}
