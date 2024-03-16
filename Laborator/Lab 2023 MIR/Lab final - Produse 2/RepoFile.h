#pragma once
#include "repo.h"
 

class RepoFile : public Repo {
private:
    string fileName;
public:
    //RepoFile(string fileName, ValidatorProdus* validator);
    RepoFile(string fileName);
    RepoFile();
    ~RepoFile();

    void addProdus(Produs* p);
    void updateProdus(Produs* pVechi, Produs* pNou);
    void deleteProdus(Produs* p);
    int getNumarProduse(string nume);


    //int size();
   // Produs* get_at(int pos);

private:
    void loadFromFile();
    void saveToFile();

};

