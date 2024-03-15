//
// Created by user on 4/6/2023.
//

#ifndef SEMINAR3_313_REPO_H
#define SEMINAR3_313_REPO_H

#include "Student.h"
#include <vector>

class Repo {
private:
    vector<Student> elems;
    const char *file_name;
    void saveToFile();
public:
    Repo();
    Repo(const char*);
    void add(Student &);
    void remove(Student &);
    void update(Student &, Student &);
    vector<Student> getAll();
    int size();
    int find(Student &);
    ~Repo();


};


#endif //SEMINAR3_313_REPO_H
