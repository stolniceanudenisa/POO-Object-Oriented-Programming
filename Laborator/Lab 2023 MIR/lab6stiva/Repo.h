
#ifndef LAB4_REPO_H
#define LAB4_REPO_H

#include <stack>
#include "Entitate.h"

class Repo {
private:
    std::stack<Entitate> entitati;
    int nrEntitati;
public:
    /*
     *  constructor
     */
    Repo();
    /*
     *  destructor
     */
    ~Repo();
    /*
     *  adauga element
     */
    void addItem(Entitate &e);
    /*
     * returneaza elem de pe o pozitie
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
