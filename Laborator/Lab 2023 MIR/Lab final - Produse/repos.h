#pragma once
 
#include <vector>
#include "produss.h"
#include "valp.h"

class Repo {
protected:
    vector<Produs*> produse;
    ValidatorProdus* validator;
public:
    Repo(ValidatorProdus* validator);
    Repo();
    ~Repo();
    int size();
    Produs* get_at(int pos);

    vector<Produs*> getAll();
    Produs* get(int poz);
    Produs* find(string nume);
    Produs* findcod(int cod);
    bool findbycoderepo(int cod);
    void addProdus(Produs* p);
    void deleteProdus(Produs* p);
    void deleteProdusCod(Produs* p);
    void updateProdus(Produs* pVechi, Produs* pNou);
    int getNumarProduse(string nume);
};


