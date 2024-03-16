#pragma once
 

#include "repofile.h"

class Service {
private:
    //int bani;
    vector<pair<int, int>> bani = { {1, 20}, {5, 20}, {10, 40}, {20, 40}, {50, 50}, {100, 50}, {500, 20} };


    RepoFile& repo;
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
    void afisareBaniTonomat();

    int buyProdus(int cod, int& buget);
    bool findByCode(int code);
 
    vector<Produs*> filterByPrice(int pretMin, int pretMax);
    vector<Produs*> sorteazaDupaNume();
    vector<Produs*> sorteazaDupaPret();

};
bool comparaDupaNume(Produs* p1, Produs* p2);
bool comparaDupaPret(Produs* p1, Produs* p2);


