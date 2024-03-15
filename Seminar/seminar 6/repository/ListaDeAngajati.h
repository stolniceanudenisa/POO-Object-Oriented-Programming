//
// Created by user on 25-May-23.
//

#ifndef SEM_6_313_LISTADEANGAJATI_H
#define SEM_6_313_LISTADEANGAJATI_H
#include "../domain/Angajat.h"
#include <vector>

class ListaDeAngajati {
private:
    int nr_angajati;
    std::vector<Angajat> elems;
public:
    int getNrAngajati() const;

public:
    ListaDeAngajati();
    void add(const Angajat &angajat);
    Angajat& element_at(int poz);
};


#endif //SEM_6_313_LISTADEANGAJATI_H
