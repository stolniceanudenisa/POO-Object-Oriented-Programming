//
// Created by 40766 on 05.05.2023.
//
 
#pragma once
#include "RepoFile.h"

class Service {
private:
    RepoFile& repoProdus;
public:
    Service(RepoFile& repoProdus);
    ~Service();

    vector<Produs*> getAll();

    void addProdus(int cod, string nume, int pret);

};



 
