//
// Created by user on 4/13/2023.
//

#ifndef UNTITLED_REPOFILE_H
#define UNTITLED_REPOFILE_H
#include<vector>
#include "Student.h"


class RepoFile {
private:
    vector<Student> elems;
    char* fileName;
    void saveToFile();
public:
    RepoFile();
    RepoFile(char* fileName);
    void add(Student& student);
    bool find(Student& student);
    bool del(Student& student);
    bool update(Student& student1, Student& student2);
    vector<Student> getAll();
    ~RepoFile();
};


#endif //UNTITLED_REPOFILE_H
