//
// Created by alex t. on 22/03/2023.
//

#ifndef LAB4_REPO_H
#define LAB4_REPO_H
#include "Entitate.h"

class Repo {
private:
    //Entitate entitati[10];
    Entitate* entitati;
    int nrEntitati;
public:
    Repo();
    ~Repo();
    void addItem(Entitate &e);
    Entitate getItemFromPos(int pos);
    int getSize();
};


#endif //LAB4_REPO_H
