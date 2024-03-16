//
// Created by alex t. on 22/03/2023.
//

#include <iostream>
#include "test.h"
#include "Entitate.h"
#include "Repo.h"
#include "meniuOperations.h"
#include "assert.h"

void test() {
    int start, stop;
    Repo rep, rezList;
    Entitate e1 = Entitate(2, 2, 2), e2 = Entitate(1, 1, 1);
    rep.addItem(e1);
    rep.addItem(e2);
    rep.addItem(e2);
    rep.addItem(e2);
    rep.addItem(e2);
    rep.addItem(e1);
    /// teste pentru repo
    assert(rep.getSize() == 6);
    assert(rep.getItemFromPos(0) == e1);
    /// teste pentru meniuOperations
    secvMax(rep, start, stop);
    assert(start == 1 and stop == 4);
    ceaMaiFrumoasaLista(rep, rezList);
    assert(rezList.getSize() == 0);
}

void test2() {
    Repo rep;
    Entitate e1 = Entitate(2, 2, 2), e2 = Entitate(1, 1, 1), eRezultat;
    rep.addItem(e1);
    rep.addItem(e2);
    eRezultat.operator=(meniuBigEnt(rep));
    assert(eRezultat == e1);
}