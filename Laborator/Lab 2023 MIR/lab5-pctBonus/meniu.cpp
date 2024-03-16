//
// Created by alex t. on 23/03/2023.
//

#include <iostream>
#include "meniu.h"
#include "Repo.h"
#include "meniuOperations.h"

void meniu() {
    bool waterscrew = true;
    int optiune;
    Repo rep;
    Entitate rez;
    printOptions();
    while (waterscrew) {
        std::cout << "Alegeti o optiune: ";
        std::cin >> optiune;
        if (optiune == 1) /// adauga o entitate in lista prin repo
            meniuAdd(rep);
        else if (optiune == 2) /// afiseaza toate entitatile din lista prin repo
            meniuPrint(rep);
        else if (optiune == 3) {
            rez.operator=(meniuBigEnt(rep));/// gaseste entitatea maxima
            std::cout << rez;
        }
        else if (optiune == 4) {
            Repo rezList;
            Entitate e;
            ceaMaiFrumoasaLista(rep, rezList);
            if (rezList.getSize() == 0) {
                std::cout << "Aia e, nu e nimic in lista" << std::endl;
            }
            else {
                for (int i = 0; i < rezList.getSize(); ++i) {
                    e.operator=(rezList.getItemFromPos(i));
                    std::cout << e << " ";
                }
                std::cout << std::endl;
            }
        }
        else if (optiune == 5) {
            Entitate e;
            int start, stop;
            secvMax(rep, start, stop);
            for (int i = start; i <= stop; ++i) {
                    e.operator=(rep.getItemFromPos(i));
                    std::cout << e << " ";
                }
                std::cout << std::endl;
        }
        else if (optiune == 0)
            waterscrew = false;
        else
            std::cout << "Alegeti o optiune valida!!!";
    }
}
