#pragma once
#include "repo.h"
#include "produs.h"
#include <string>

using namespace std;

class RepositoryFile : public Repository<pair<Produs, int>> {
private:
    string filename;
public:
    RepositoryFile(string filename);
    RepositoryFile();
    void writeData();
    int size();
    void addEntity(pair<Produs, int> entity);      // adaugarea unui obiect de tip predefinit in vector
    bool updateEntity(pair<Produs, int>& entity, pair<Produs, int>& new_entity);      //actualizarea unui obiect predefinit din vector
    bool delEntity(const pair<Produs, int>& old_entity);              //stergerea unui obiect din vector
    bool findEntity(pair<Produs, int> entity);                 //cautarea unui obiect intr-un vector
    RepositoryFile& operator=(const RepositoryFile& repo);
};