//
// Created by alex t. on 23/03/2023.
//

#include <iostream>
#include "meniuOperations.h"

/// \def optiunile din meniu
/// \In -
/// \Out -
void printOptions() {
    std::cout << "Bine ati venit!" << std::endl;
    std::cout << "1. Adauga un obiect de tip entitate" << std::endl;
    std::cout << "2. Afiseaza toate entitatile" << std::endl;
    std::cout << "3. Cea mai mare entitate" << std::endl;
    std::cout << "4. Toate entitatile din cadranul 1" << std::endl;
    std::cout << "5. Cea mai lunga secventa de entitati egale" << std::endl;
    std::cout << "0. Asta te scoate din aplicatie varule" << std::endl;
}

/// \def adauga o entitate in lista din repository
/// \In obiect de tip repo
/// \Out -
void meniuAdd(Repo &rep) {
    Entitate e;
    std::cin >> e;
    rep.addItem(e);
}

/// \def Afiseaza toate entitatile din lista
/// \In obiect de tip repo
/// \Out -
void meniuPrint(Repo &rep) {
    int nrCrt = rep.getSize(), i;
    Entitate rez;
    for (i = 0; i < nrCrt; i++) {
        rez = rep.getItemFromPos(i);
        std::cout << rez;
    }
}

/// \def cea mai mare entitate bazata pe arie
/// \In obiect de tip repo
/// \Out rezMax(entitate)
 Entitate meniuBigEnt(Repo &rep) {
    int n = rep.getSize();
    Entitate rezMax = rep.getItemFromPos(0);
    Entitate e;
    for (int i = 1; i < n; i++) {
        e = rep.getItemFromPos(i);
        if (e > rezMax) {
            rezMax = e;
        }
    }
    return rezMax;
}

/// \def verifica conditia ca ent sa fie in primul cadran
/// \In entitatea e
/// \Out true sau false
bool verif(Entitate &e) {
    if (e.getCX() > 0 and e.getCY() > 0 and e.getCX() > e.getRaza() and e.getCY() > e.getRaza())
        return true;
    return false;
}

/// \def gaseste toate entitatile aflate in primul cadran trigonometric
/// \In 2 obiecte de tip Repo, repository-ul folosit si o lista de rezultate
/// \Out -
void ceaMaiFrumoasaLista(Repo &rep, Repo &rezList) {
    int n = rep.getSize(), k = 0;
    Entitate e;
    for (int i = 0; i < n; ++i) {
        e = rep.getItemFromPos(i);
        if (verif(e) == true) {
            rezList.addItem(e);
        }
    }
}

/// \def gaseste secventa maxima de entitati egale
/// \In obiect de tip Repo, start(int), stop(int)
/// \Out -
void secvMax(Repo &rep, int &start, int &stop) {
    int l, lmax, stMax, stpMax, n, i, st, stp;
    Entitate eCurent, ePrecedent;
    l = i = 1;
    stMax = stpMax = lmax = st = stp = 0;
    n = rep.getSize();
    ePrecedent = rep.getItemFromPos(0);
    while (i < n) {
        eCurent = rep.getItemFromPos(i);
        if (eCurent == ePrecedent) {
            l++;
        }
        else {
            if (l > lmax) {
                lmax = l;
                stMax = st;
                stpMax = i-1;
            }
            st = i;
            l = 1;
        }
        ePrecedent = eCurent;
        i++;
    }
    if (l > lmax) {
        lmax = l;
        stMax = st;
        stpMax = i-1;
    }
    start = stMax;
    stop = stpMax;
}