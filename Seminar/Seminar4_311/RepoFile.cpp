//
// Created by user on 4/13/2023.
//

#include "RepoFile.h"
#include<algorithm>
#include<fstream>
using namespace std;

RepoFile::RepoFile() {
    this->fileName = nullptr;
}

RepoFile::RepoFile(char *fileName) {
    this->fileName = fileName;
    ifstream f(fileName);
    while(!f.eof()){
        string nume;
        int matricol;
        f>>nume>>matricol;
        Student s(nume,matricol);
        elems.push_back(s);
    }
    f.close();
}

void RepoFile::add(Student &student) {
    this->elems.push_back(student);
    saveToFile();
}

bool RepoFile::find(Student &student) {
    vector<Student>::iterator it = std::find(elems.begin(),elems.end(),student);
    if(it == elems.end())
        return false;
    return true;
}

bool RepoFile::del(Student &student) {
    vector<Student>::iterator it = std::find(elems.begin(),elems.end(),student);
    if(it!=elems.end()){
        elems.erase(it);
        saveToFile();
        return true;
    }
    return false;
}

bool RepoFile::update(Student &student1, Student &student2) {
    vector<Student>::iterator it = std::find(elems.begin(),elems.end(),student1);
    if(it!=elems.end()){
        elems[it-elems.begin()] = student2;
        saveToFile();
        return true;
    }
    return false;
//    for(Student crt:elems)
//        if(crt == student1)
//        {
//            crt = student2;
//            saveToFile();
//            return true;
//        }
//    return false;
}

vector<Student> RepoFile::getAll() {
    return this->elems;
}

RepoFile::~RepoFile() {

}

void RepoFile::saveToFile() {
    ofstream  f(fileName);
    for(Student crt:elems)
        f<<crt.ToString()<<endl;
    f.close();
}
