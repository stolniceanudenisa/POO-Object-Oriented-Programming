
#ifndef LAB4_REPO_H
#define LAB4_REPO_H

#include <vector>
#include "Entitate.h"

class Repo {
private:
    std::vector<Entitate> entitati;
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
    * add item
    */

    void addItem(Entitate &e);

    /*
    * returneaza un element de pe o pozitie
    */
    Entitate getItemFromPos(int pos);


    int getSize();





















    int getIndexOfMaxEntitate();
    int getLongestEqualSequence();
    int countTrianglesInQuadrant12();


//    const Entitate& getEntitate(int index) const {
//        return entitati[index];
//    }
//
//    Entitate& operator[](int index) {
//        return entitati[index];
//    }

};



#endif //LAB4_REPO_H
