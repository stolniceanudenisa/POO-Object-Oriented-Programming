//
// Created by user on 25-May-23.
//

#include "ListaDeAngajati.h"
#include "../util/MyException.h"

ListaDeAngajati::ListaDeAngajati() {
    nr_angajati = 0;
}

void ListaDeAngajati::add(const Angajat &angajat) {
    elems.push_back(angajat);
    nr_angajati++;
}

Angajat& ListaDeAngajati::element_at(int poz) {
    if(poz>elems.size() or poz<0)
        throw MyException("Index in afara limitelor!");
    return elems[poz];
}

int ListaDeAngajati::getNrAngajati() const {
    return nr_angajati;
}
