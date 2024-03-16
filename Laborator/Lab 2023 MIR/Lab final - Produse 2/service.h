#pragma once
 
#include "RepoFile.h"

class Service {
private:
    int bani = 500;
    RepoFile repo;
public:
    Service(RepoFile& repo);
    ~Service();

    void updateBuget(int buget);
    int getBuget();

    vector<Produs*> getAll();

    void addProdus(int cod, string nume, int pret, int nrap);
    void updateProdus(int cod, string nume, int pretnou, int nrap);
    void deleteProdus(string nume);
    void deleteProdusCod(int cod);


    int buyProdus(int cod, int& buget);

    bool findByCode(int code);
    //int cumparaProdus(int cod, int& bani);


    int getNumarProduse(string nume);
};




