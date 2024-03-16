
#include <iostream>
#include "meniu.h"
#include "Repo.h"
#include "meniuOperations.h"


void meniu() {
    bool op = true;
    int optiune;
    Repo rep;
    Repo aux;
    //int nrTriunghiuri = 0,lungime;
    //Entitate rez;
    //Entitate ent[100];
    //int aux[100] = { };

    while (op) {
        printOptions();
        std::cout << "Alegeti o optiune:";
        std::cin >> optiune;

        if (optiune == 1)
        {
            int lat1,lat2,lat3;
            std::cout<<"lat1=";
            std::cin>>lat1;
            std::cout<<"lat2=";
            std::cin>>lat2;
            std::cout<<"lat3=";
            std::cin>>lat3;
            Entitate triunghi(lat1,lat2,lat3);
            rep.addItem(triunghi);
        }
        else if (optiune == 2)
            meniuPrint(rep);


        else if (optiune == 3)
        {
            int index = rep.getIndexOfMaxEntitate();
            if (index == -1) {
                std::cout << "Nu exista nicio entitate in repo.\n";
            } else {
                Entitate maxEntitate = rep.getItemFromPos(index);
                std::cout << "Entitatea cu cea mai mare arie este: " << maxEntitate << '\n';
            }
        }

        else if (optiune == 4)
        {
            int count = rep.countTrianglesInQuadrant12();
            std::cout << "Numarul de entitati din cadranul 1: " << count <<'\n';
        }

        else if (optiune == 5)
        {
            int maxLength = rep.getLongestEqualSequence();
            if (maxLength > 1) {
                std::cout << "Cea mai lunga secventa de entitati egale are lungimea: " << maxLength << std::endl;
            } else {
                std::cout << "Nu exista secvente de entitati egale!" << std::endl;
            }
        }

        else if (optiune == 0)
            op = false;
        else
            std::cout << "Alegeti o optiune valida.";
    }
}




//
//else if (optiune == 3) {
//rez.operator=(meniuBigEnt(rep));
//std::cout << rez;
//}






//        else if (optiune == 3)
//        {
////            int ceamaimare = rep.ceamaimareentitate( Entitate());
////            std::cout << "Cel mai mare triunghi are aria: " << ceamaimare << std::endl;
//              //Entitate e; // create an object of type Entitate
//              //int ceamaimare = rep.ceamaimareentitate(e); // pass the object as an argument
//              std::cout<<rep.ceamaimareentitate(Entitate());
//              //std::cout<<ceamaimare;
//        }

//
//else if (optiune == 4)
//{
//int count = rep.getNumEntitiesInQuadrant1();
//std::cout << "Numarul de entitati situate in cadranul 1 este: " << count << std::endl;
//}

//else if (optiune == 41)
//{
//// 3 4 5         3 4 6 nu
//// 2 3 4         6 2 8
//int count = rep.countTrianglesInQuadrant1();
//if (count == 0) {
//std::cout << "Nu exista triunghiuri in cadranul I." << std::endl;
//}
//else {
//std::cout << "Numarul de triunghiuri in cadranul I este: " << count << std::endl;
//}
//}



//else if (optiune == 31)
//{
//if (rep.getSize() == 0) {
//std::cout << "Nu exista entitati in repo.\n";
//} else {
//Entitate maxEntitate = rep.getItemFromPos(0);
//for (int i = 1; i < rep.getSize(); i++) {
//Entitate entitateCurenta = rep.getItemFromPos(i);
//if (entitateCurenta.arie() > maxEntitate.arie()) {
//maxEntitate = entitateCurenta;
//}
//}
//std::cout << "Cel mai mare triunghi: " << maxEntitate << '\n';
//}
//
//}


//else if (optiune == 51)
//{
//lungime=rep.celmaimailungsecventa(nrTriunghiuri, aux);
//for (int i = 0; i < lungime; i++)
//std::cout << aux[i] << " ";
//std::cout << '\n';
//}