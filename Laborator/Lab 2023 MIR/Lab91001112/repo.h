#pragma once
#include<iostream>
#include<vector>
#include"validatorprodus.h"
#include"validationexception.h"

using namespace std;

template <class obiect>class Repository {
protected:
    vector<obiect> elems;
    ValidatorProdus validatorP;
public:
    Repository();      //constructor fara parametrii
    ~Repository();     //destructor
    void addEntity(obiect entity);      // adaugarea unui obiect de tip predefinit in vector
    bool updateEntity(obiect& entity, obiect& new_entity);      //actualizarea unui obiect predefinit din vector
    bool delEntity(const obiect& old_entity);              //stergerea unui obiect din vector
    bool findEntity(obiect entity);                 //cautarea unui obiect intr-un vector
    obiect getAt(int pos);
    int size();                                     //returneaza numarul de elemente
    vector<obiect> getAll();                       //returneaza adresa vectorului de obiecte
    int find(Produs p);
};

template<class obiect>
obiect Repository<obiect>::getAt(int pos) {
    return this->elems[pos];
}

template <class obiect>
Repository<obiect>::Repository() {

}

template <class obiect>
Repository<obiect>::~Repository() {

}


//in: un obiect de tip predefinit
//out: -
//Descr: adauga un obiect in vector
template <class obiect>
void Repository<obiect>::addEntity(obiect entity) {

   
    this->elems.push_back(entity);
}

//in: doua obiecte de tip predefinit
//out: o valoare bool
//Desc: Functia returneaza true daca s-a adaugat entitatea de tip obiect in vector, respectiv false in caz contrar
template <class obiect>
bool Repository<obiect>::updateEntity(obiect& old_entity, obiect& new_entity) {
    if (findEntity(old_entity)) {
        int i = 0;
        while (i < elems.size() && !(this->elems.at(i) == old_entity))
            i++;
        this->elems.at(i) = new_entity;
        return true;
    }
    return false;
}

//in: un obiect de tip predefinit
//out: o valoare bool
//Desc: Functia returneaza true daca s-a gasit entitatea de tip obiect in vector, respectiv false in caz contrar
template <class obiect>
bool Repository<obiect>::findEntity(obiect entity) {
    int i = 0;
    while (i < this->elems.size()) {
        if (this->elems.at(i) == entity)
            return true;
        i++;
    }
    return false;
}

//in: un obiect de tip predefinit
//out: o valoare bool
//Desc: Functia returneaza true daca s-a sters entitatea de tip obiect in vector, respectiv false in caz contrar
template <class obiect>
bool Repository<obiect>::delEntity(const obiect& old_entity) {
    if (findEntity(old_entity)) {
        int poz = 0;
        while (poz < elems.size() && !(elems.at(poz) == old_entity))
            poz++;
        for (int i = poz; i < elems.size() - 1; i++)
            this->elems.at(i) = this->elems.at(i + 1);
        this->elems.pop_back();
        return true;
    }
    return false;
}

//in:
//out: returneaza vector
//Desc: Functia returneaza vectorul de obiecte
template <class obiect>
vector<obiect> Repository<obiect>::getAll() {
    return this->elems;
}

template<class obiect>
inline int Repository<obiect>::find(Produs p)
{
    for (int i = 0; i < elems.size(); i++) {
        if (elems[i] == p) {
            return i;
        }
    }
    return -1;
}

//in:
//out:
//Desc: returneaza numarul de elemente
template <class obiect>
int Repository<obiect>::size() {
    return elems.size();
}
