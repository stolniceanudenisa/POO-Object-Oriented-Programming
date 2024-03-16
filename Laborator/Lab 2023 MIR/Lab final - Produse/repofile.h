#pragma once
 
#include "repos.h"


class RepoFile : public Repo {
private:
    string fileName;
public:
    RepoFile(string fileName, ValidatorProdus* validator);
    //RepoFile(string fileName);
    //RepoFile();
    ~RepoFile();

    void addProdus(Produs* p);
    void updateProdus(Produs* pVechi, Produs* pNou);
    void deleteProdus(Produs* p);
    int getNumarProduse(string nume);
    void setFileName(string fileName);
    string getFileName();

private:
    void loadFromFile();
    void saveToFile();

};

