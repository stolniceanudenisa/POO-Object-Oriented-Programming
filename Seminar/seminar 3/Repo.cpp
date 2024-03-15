//
// Created by user on 4/6/2023.
//

#include <fstream>
#include "Repo.h"
#include <algorithm>

Repo::Repo() {

}

Repo::Repo(const char *f_name) {
    file_name = f_name;
    ifstream f(file_name);
    while(!f.eof()){
        string name;
        double medie;
        f>>name>>medie;
        Student s(name,medie);
        elems.push_back(s);
    }
    f.close();
}

void Repo::saveToFile() {
    ofstream fo(file_name);
    for(Student s: elems)
        fo<<s.toString()<<endl;//fo<<s;
    fo.close();
}

void Repo::add(Student &s) {
    elems.push_back(s);
    saveToFile();

}

void Repo::remove(Student &s) {
    vector<Student>::iterator it;
    it = std::find(elems.begin(), elems.end(), s);
    if (it!=elems.end())
    {
        elems.erase(it);
        saveToFile();
    }
}

int Repo::find(Student &s) {
    vector<Student>::iterator it;
    it = std::find(elems.begin(), elems.end(), s);
    if (it!=elems.end())
        return (it - elems.begin());
}

void Repo::update(Student &s1, Student &s2) {
    vector<Student>::iterator it;
    int pozitie = find(s1);///apelam functia de mai sus
    if (pozitie >= 0){
        elems[pozitie] = s2;
        saveToFile();
    }
}

vector<Student> Repo::getAll() {
    return elems;
}

int Repo::size() {
    return elems.size();
}

Repo::~Repo() {}


