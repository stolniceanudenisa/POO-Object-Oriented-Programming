//
// Created by alex t. on 22/03/2023.
//

#include "Repo.h"

Repo::Repo() {
    this->entitati = new Entitate[10];
    this->nrEntitati = 0;
}

Repo::~Repo() {
    delete[] entitati;
}

/// \def adauga un obiect in lista de entitati
/// \In un obiect de tip entitate
/// \Out -
void Repo::addItem(Entitate &e) {
    this->entitati[this->nrEntitati++] = e;
}

/// \def returneaza un element din lista de entitati
/// \In pozitia(int)
/// \Out entitatea de pe pozitia pos
Entitate Repo::getItemFromPos(int pos) {
    return this->entitati[pos];
}

/// \def marimea listei de entitati
/// \In -
/// \Out lungimea listei nrEntitati(int)
int Repo::getSize() {
    return this->nrEntitati;
}
