//
// Created by 40766 on 05.05.2023.
//
 
#pragma once
#include "repo.h"

class RepoFile : public Repo {
private:
    string fileName;
public:

    RepoFile(string fileName);

    ~RepoFile();

    void addProdus(Produs* p);

private:
    void loadFromFile();
    void saveToFile();

};

 
