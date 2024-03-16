//
// Created by alex t. on 23/03/2023.
//

#ifndef LAB4_MENIUOPERATIONS_H
#define LAB4_MENIUOPERATIONS_H

#include "Repo.h"

void printOptions();
void meniuAdd(Repo &rep);
void meniuPrint(Repo &rep);
bool verif(Entitate &e);
Entitate meniuBigEnt(Repo &rep);
void ceaMaiFrumoasaLista(Repo &rep, Repo &rezList);
void secvMax(Repo &rep, int &start, int &stop);
#endif //LAB4_MENIUOPERATIONS_H
