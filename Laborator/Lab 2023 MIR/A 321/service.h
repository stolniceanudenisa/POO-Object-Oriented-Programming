#pragma once
#include "repofile.h"
#include "produs.h"
#include<string>

using namespace std;

class Service {
private:
    RepositoryFile repo;
    int buget;
public:
    Service();
    Service& operator=(const Service& service);
    Service(RepositoryFile& repo);
    void addProd(int cod, string nume, int pret, int nrUnit);
    bool findByCode(int code);
    void updateBuget(int buget);
    int getBuget();
     
    void updateProd(int cod, string nume, int pret, int nrUnit);
    int buyProdus(int cod, int& buget);
    void deleteProd(int cod);
    vector<pair<Produs, int>> sortUnit();
    vector<pair<Produs, int>> sortPrice();
    vector<pair<Produs, int>> lowPrice(int price);
    vector<pair<Produs, int>> getAll();


};

