

#include <limits>
#include <cmath>
#include "Repo.h"

Repo::Repo() {
    this->nrEntitati = 0;
}

//destructor
Repo::~Repo() {}

//adauga un element
void Repo::addItem(Entitate &e) {
    this->entitati.push_back(e);
}
//returneaza pozitia unui element
Entitate Repo::getItemFromPos(int pos) {
    return this->entitati[pos];
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

int Repo::getIndexOfMaxEntitate() {
    int index = -1;
    int maxArea = std::numeric_limits<int>::min();
    for (int i = 0; i < getSize(); i++) {
        int area = entitati[i].arie();
        if (area > maxArea) {
            maxArea = area;
            index = i;
        }
    }
    return index;
}

/*
int nre=0;
int ceamaimarearie = this->entitati[nre].arie();
for (int i = 1; i < getSize(); i++) {
if (this->entitati[nre].arie() > ceamaimarearie) {
ceamaimarearie = this->entitati[nre].arie();
}
}
std::cout << "Cel mai mare triunghi are aria:" << ceamaimarearie << '\n';
return ceamaimarearie;
*/


int Repo::getLongestEqualSequence() {
    int maxLength = 0;
    int currentLength = 1;

    for (int i = 0; i < this->getSize() - 1; i++) {
        if (this->entitati[i] == this->entitati[i + 1]) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }

    if (currentLength > maxLength) {
        maxLength = currentLength;
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


/*
 Sure! One example of a triangle that satisfies the condition where all three angles are between 0 and 90 degrees is a triangle w
 ith sides of length 3, 4, and 5 units. This is also known as a Pythagorean triple, as it satisfies the Pythagorean theorem.
 The angle opposite the side of length 5 can be found using the inverse tangent function and is approximately 53.13 degrees.
 The other two angles can then be found using the fact that the sum of all three angles in a triangle is always 180 degrees.
 he angle opposite the side of length 4 is approximately 36.87 degrees and the angle opposite the side of length 3 is approximately 90 degrees.
*/

/*
Angle A: acos((4^2 + 5^2 - 3^2) / (2 * 4 * 5)) = 36.87 degrees
        Angle B: acos((3^2 + 5^2 - 4^2) / (2 * 3 * 5)) = 53.13 degrees
        Angle C: acos((3^2 + 4^2 - 5^2) / (2 * 3 * 4)) = 90 degrees

*/
int Repo::countTrianglesInQuadrant12() {
    int count = 0;

    //4 2 5 nu e cos A=0.65..., angleA= 49.45
    //           cos B=0.925..., angleB= 22.33
    //           cos C= -0.31..., angleC= 108.209

    // 3 4 5 e
    // 9 9 9
    //7 8 9 da
    // 4 5 6 e

    for (int i = 0; i < this->getSize(); i++) {

        double side1 = entitati[i].getLatura1();
        double side2 = entitati[i].getLatura2();
        double side3 = entitati[i].getLatura3();

        double cosA = (side2*side2 + side3*side3 - side1*side1) / (2*side2*side3);
        double cosB = (side1*side1 + side3*side3 - side2*side2) / (2*side1*side3);
        double cosC = (side1*side1 + side2*side2 - side3*side3) / (2*side1*side2);

        double angleA = radToDeg(std::acos(cosA));
        double angleB = radToDeg(std::acos(cosB));
        double angleC = radToDeg(std::acos(cosC));


        // Check if triangle is in Quadrant 1
        if (angleA > 0 && angleA < 90 && angleB > 0 && angleB < 90 && angleC > 0 && angleC <= 90) {
            count++;
        }
    }

    return count;
}


