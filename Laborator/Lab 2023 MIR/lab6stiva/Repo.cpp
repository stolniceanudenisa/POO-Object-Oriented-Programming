

#include <limits>
#include <cmath>
#include "Repo.h"

Repo::Repo() {
    //this->nrEntitati = 0;
}

//destructor
Repo::~Repo() {}

//adauga un element
void Repo::addItem(Entitate &e) {
    this->entitati.push(e);
}
//returneaza pozitia unui element

/*
 *nu se pot accesa in stiva elementele dupa index
 * ci doar cele din top ul stivei
 */
Entitate Repo::getItemFromPos(int pos) {
    std::stack<Entitate> stack_temporar;
    Entitate result;
    int currentPos = 0;

    // Pop elements from the original stack and push them onto a temporary stack
    while (!entitati.empty()) {
        Entitate current = entitati.top();
        entitati.pop();

        if (currentPos == pos) {
            result = current;
        }

        stack_temporar.push(current);
        currentPos++;
    }

    // Pop elementele din stiva temporara si le punem inapoi in stiva originala
    while (!stack_temporar.empty()) {
        Entitate current = stack_temporar.top();
        stack_temporar.pop();
        entitati.push(current);
    }

    return result;
}
// retunreaza size ul vectorului
int Repo::getSize() {
    return this->entitati.size();
}














//

//int Repo::ceamaimareentitate(const Entitate &e) {
//
//    if (getSize() == 0) {
//        std::cout << "Nu exista entitati in repo!\n";
//        return 0;
//    }
//
//    int ceamaimarearie = this->entitati[0].arie();
//    for (int i = 1; i < getSize(); i++) {
//        if (this->entitati[i].arie() > ceamaimarearie) {
//            ceamaimarearie = this->entitati[i].arie();
//        }
//    }
//    std::cout << "Cel mai mare triunghi are aria:" << ceamaimarearie << '\n';
//    return ceamaimarearie;
//}
//
//int Repo::celmaimailungsecventa( int nrTriunghiuri, Repo aux) {
//    int lungimeSecventa = 1;
//    int inceputSecventa = 0;
//    int lungimeMaxima = 1;
//    int inceputMaxim = 0;
//
//    for (int i = 1; i < nrTriunghiuri; i++) {
//        if (this->entitati[i].arie() == this->entitati[i - 1].arie()) {
//            lungimeSecventa++;
//        }
//        else {
//            if (lungimeSecventa > lungimeMaxima) {
//                lungimeMaxima = lungimeSecventa;
//                inceputMaxim = inceputSecventa;
//            }
//            lungimeSecventa = 1;
//            inceputSecventa = i;
//        }
//    }
//
//    if (lungimeSecventa > lungimeMaxima) {
//        lungimeMaxima = lungimeSecventa;
//        inceputMaxim = inceputSecventa;
//    }
//    int j;
//    j = 0;
//    for (int i = inceputMaxim; i <= inceputMaxim + lungimeMaxima; i++)
//    {
//        Entitate copy = this->getEntitate(i); // create a copy of the current Entitate object
//        aux.addItem(copy);
//        j++;
//    }
//    return lungimeMaxima;
//}




// returneaza indexul triunghiului cu cea mai mare arie

int Repo::getIndexOfMaxEntitate() {
    int index = -1, i = 0;
    double maxArie = -1;
    std::stack<Entitate> aux;

    while (!entitati.empty()) {
        Entitate e = entitati.top();
        entitati.pop();
        double arie = e.arie();
        if (arie > maxArie) {
            maxArie = arie;
            index = i;
        }
        aux.push(e);
        i++;
    }
    while (!aux.empty()) {
        entitati.push(aux.top());
        aux.pop();
    }
    return index;
}



// returneaza lungimea celei mai lungi secvente de entitati egale
int Repo::getLongestEqualSequence() {
    int maxLength = 1, currentLength = 1;
    std::stack<Entitate> aux;

    if (entitati.size() <= 1) {
        return entitati.size();
    }

    Entitate current = entitati.top();
    entitati.pop();
    aux.push(current);

    while (!entitati.empty()) {
        Entitate e = entitati.top();
        entitati.pop();

        if (e.arie() == current.arie()) {
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        } else {
            currentLength = 1;
        }

        current = e;
        aux.push(current);
    }

    while (!aux.empty()) {
        entitati.push(aux.top());
        aux.pop();
    }
    return maxLength;
}


/*
int Repo::getLongestEqualSequence() {
    int maxLength = 0;
    int currentLength = 1;

    for (int i = 0; i < this->nrEntitati - 1; i++) {
        // Compare the area of the current entity with the next entity
        if (this->entitati[i].arie() == this->entitati[i + 1].arie()) {

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
*/



/*
sunt in cadranul I:

(3, 4, 5)      (0, 0), (1, 1), (2, 0)
(5, 12, 13)     (0, 0), (2, 0), (1, -1)
(8, 15, 17)     (0, 0), (1, 1), (0, 2)



nu sunt in cadranul I:

(3, 4, 6)      (0, 0), (-1, 1), (-2, 0)
(7, 10, 12)     (0, 0), (-2, 0), (-1, -1)
(9, 40, 41)    (0, 0), (1, -1), (0, -2)
 */






double radToDeg(double rad) {
    return rad * 180.0 / M_PI;
}



// returneaza numarul de triunghiuri din cadranul 1
int Repo::countTrianglesInQuadrant12() {
    int count = 0;
    std::stack<Entitate> stack_temporar; // stivă temporară pentru a deține entitățile procesate

    // evaluam toate entitatile din stiva
    while (!entitati.empty()) {
        Entitate current = entitati.top();
        entitati.pop();

        double side1 = current.getLatura1();
        double side2 = current.getLatura2();
        double side3 = current.getLatura3();

        double cosA = (side2*side2 + side3*side3 - side1*side1) / (2*side2*side3);
        double cosB = (side1*side1 + side3*side3 - side2*side2) / (2*side1*side3);
        double cosC = (side1*side1 + side2*side2 - side3*side3) / (2*side1*side2);

        double angleA = radToDeg(std::acos(cosA));
        double angleB = radToDeg(std::acos(cosB));
        double angleC = radToDeg(std::acos(cosC));

        // daca triunghiul e in cadranul 1
        if (angleA > 0 && angleA < 90 && angleB > 0 && angleB < 90 && angleC > 0 && angleC < 90) {
            count++;
        }

        stack_temporar.push(current); // adăugam entitatea procesată înapoi la stiva temporară
    }

    // refacem stiva originala transferand elementele din stiva temporara
    while (!stack_temporar.empty()) {
        Entitate current = stack_temporar.top();
        stack_temporar.pop();
        entitati.push(current);
    }

    return count;
}


