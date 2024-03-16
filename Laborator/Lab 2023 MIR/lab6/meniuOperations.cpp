#include <cmath>
#include <iostream>
#include <limits>
#include "meniuOperations.h"
#include "Repo.h"

Entitate valori[100];
int nr;
void printOptions() {
    std::cout<<'\n';
    std::cout<< "1. Adauga un obiect de tip entitate" << std::endl;
    std::cout<< "2. Afiseaza toate entitatile" << std::endl;
    std::cout<< "3. Cea mai mare entitate" << std::endl;
    std::cout<< "4. Entitati din cadranul I" << std::endl;
    std::cout<< "5. Secventa de entitati egale" << std::endl;
    //std::cout<< "6. Perimetru" << std::endl;
    //std::cout<< "7. Arie" << std::endl;
    std::cout<< "0. Exit" << std::endl;
    std::cout<<'\n';
}

void meniuAdd(Repo &rep) {
    Entitate e;
    std::cin >> e;
    rep.addItem(e);
}




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


double radToDeg1(double rad) {
    return rad * 180.0 / M_PI;
}



int countTrianglesInQuadrant1231(Repo &rep){
    int count = 0;

    //4 2 5 nu e cos A=0.65..., angleA= 49.45
    //           cos B=0.925..., angleB= 22.33
    //           cos C= -0.31..., angleC= 108.209
    // 3 1 1 nu e are unghiuri cu minus
    // 3 4 5 nu
    // 9 9 9  bun
    //7 8 9 bun
    // 4 5 6 e
    // 1 1 1
    // 2 3 2

    for (int i = 0; i < nr; i++) {


        double side1 = valori[i].getLatura1();
        double side2 = valori[i].getLatura2();
        double side3 = valori[i].getLatura3();

        double cosA = (side2*side2 + side3*side3 - side1*side1) / (2*side2*side3);
        double cosB = (side1*side1 + side3*side3 - side2*side2) / (2*side1*side3);
        double cosC = (side1*side1 + side2*side2 - side3*side3) / (2*side1*side2);
        double angleA = radToDeg1(std::acos(cosA));
        double angleB = radToDeg1(std::acos(cosB));
        double angleC = radToDeg1(std::acos(cosC));


        // daca triunghiul e in cadranul 1
        if (angleA > 0 && angleA < 90 && angleB > 0 && angleB < 90 && angleC > 0 && angleC < 90) {
            count++;
        }
    }

    return count;
}
int getLongestEqualSequencee(Repo &rep){
    int maxLength = 0;

    int currentLength = 1;
    //Repo repo;
    for (int i = 0; i < nr - 1; i++) {
        // Compare the sides and area of the current entity with the next entity
        if (valori[i].getLatura1() == valori[i + 1].getLatura1() &&
            valori[i].getLatura2() == valori[i + 1].getLatura2() &&
            valori[i].getLatura3() == valori[i + 1].getLatura3() &&
            valori[i].arie() == valori[i + 1].arie()) {

            currentLength++;

            // Update the maximum length if the current length is greater
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        } else {
            // Reset the current length if the entities are not equal
            currentLength = 1;
        }
    }

    return maxLength;

}
int getIndexOfMaxEntitate1(Repo &rep){
    int index = -1;
    int maxArea = std::numeric_limits<int>::min();
    for (int i = 0; i < nr; i++) {
        int area = valori[i].arie();
        if (area > maxArea) {
            maxArea = area;
            index = i;
        }
    }
    return index;

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

