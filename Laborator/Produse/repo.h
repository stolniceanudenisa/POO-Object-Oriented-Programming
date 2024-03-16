//
// Created by 40766 on 05.05.2023.
//

#pragma once
#include "produs.h"
#include <vector>


class Repo {
protected:
    vector<Produs*> produse;

public:
    //Repo(ValidatorProdus* validator);
    Repo();
    ~Repo();

    vector<Produs*> getAll();
    Produs* get(int poz);
    Produs* find(string nume);

    void addProdus(Produs* p);

};


 