
#ifndef LAB4_REPO_H
#define LAB4_REPO_H
#include "Entitate.h"

class Repo {
private:
    Entitate* entitati;
    int nrEntitati;
public:

    /*
     * constructor
     */
    Repo();
    /*
     * destructor
     */

    ~Repo();

    /*
     * adauga element
     */
    void addItem(Entitate &e);


    Entitate getItemFromPos(int pos);

    /*
     * returneaza size ul
     */
    int getSize();



















    int getIndexOfMaxEntitate();
    int getLongestEqualSequence();
//    int getNumEntitiesInQuadrant1();
//
//    int countTrianglesInQuadrant1();
    int countTrianglesInQuadrant12();


//    int ceamaimareentitate(const Entitate &e);
//    int celmaimailungsecventa(int nrTriunghiuri, Repo aux);
//    const Entitate& getEntitate(int index) const {
//        return entitati[index];
//    }
//
//    Entitate& operator[](int index) {
//        return entitati[index];
//    }

};



#endif //LAB4_REPO_H
