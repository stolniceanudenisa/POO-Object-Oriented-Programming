//
// Created by user on 4/6/2023.
//

#include "Service.h"

Service::Service(Repo &r1) {
    r = r1;
}

void Service::add(string n, double m) {
    Student s(n,m);
    r.add(s);
}

void Service::remove(string n, double m) {
    Student s(n,m);
    r.remove(s);
}

void Service::update(string n1, double m1, string n2, double m2) {
    Student s1(n1, m1);
    Student s2(n2, m2);
    r.update(s1, s2);
}

int Service::find(string n, double m) {
    Student s(n, m);
    r.find(s);
}

int Service::size() {
    r.size();
}

vector<Student> Service::getAll() {
    return r.getAll();
}

Service::~Service() {}

Service::Service() {
}


