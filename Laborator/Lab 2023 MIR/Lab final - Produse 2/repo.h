
 
#pragma once
#include "produs.h"
#include <vector>
  

class Repo {
protected:
    vector<Produs*> produse;

public:

    Repo();
    ~Repo();
    int size();
    Produs* get_at(int pos);

    vector<Produs*> getAll();
    Produs* get(int poz);
    Produs* find(string nume);
    Produs* findcod(int cod);

    void addProdus(Produs* p);
    void deleteProdus(Produs* p);
    void deleteProdusCod(Produs* p);
    void updateProdus(Produs* pVechi, Produs* pNou);
    int getNumarProduse(string nume);
};


