
#include <iostream>
#include "meniuOperations.h"

void printOptions() {
    std::cout<< "1. Adauga un obiect de tip entitate" << std::endl;
    std::cout<< "2. Afiseaza toate entitatile" << std::endl;
    std::cout<< "3. Cea mai mare entitate" << std::endl;
    std::cout<< "4. Entitati din cadranul I" << std::endl;
    std::cout<< "5. Secventa de entitati egale" << std::endl;
    //std::cout<< "6. Perimetru" << std::endl;
    //std::cout<< "7. Arie" << std::endl;
    std::cout<< "0. Exit" << std::endl;
}





















void meniuPrint(Repo &rep) {
    int nrCrt = rep.getSize(), i;
    Entitate rez;
    for (i = 0; i < nrCrt; i++) {
        rez = rep.getItemFromPos(i);
        std::cout << rez;
    }
    //std::cout<<rez.get_perimetru()<<" "<<rez.arie();
}










void meniuAdd(Repo &rep) {
    Entitate e;
    std::cin >> e;
    rep.addItem(e);
}

























 Entitate meniuBigEnt(Repo &rep) {
    int n = rep.getSize();
    Entitate rezMax = rep.getItemFromPos(0);
    Entitate e;
    for (int i = 1; i < n; i++) {
        e = rep.getItemFromPos(i);
        rezMax = e.operator>(rezMax);
    }
    return rezMax;
}


