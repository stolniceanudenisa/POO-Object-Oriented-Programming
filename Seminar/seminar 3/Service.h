//
// Created by user on 4/6/2023.
//

#ifndef SEMINAR3_313_SERVICE_H
#define SEMINAR3_313_SERVICE_H

#include "Repo.h"

class Service {
private:
    Repo r;
public:
    Service();
    Service(Repo&);
    void add(string, double);
    void remove(string, double);
    void update(string, double, string, double);
    int find(string, double);
    int size();
    vector<Student> getAll();
    ~Service();



};


#endif //SEMINAR3_313_SERVICE_H
