//
// Created by fabia on 4/20/2022.
//

#ifndef LAB9_10_REPO_H
#define LAB9_10_REPO_H
#include "Product.h"
#include <map>
using namespace std;


template <typename T> class Repo {
private:

    map<T, int> repo;

public:

    Repo() {

    }

    void addElement(T, int);

    void deleteElement(T);

   // void deleteAmountElement(const T&, int);

    void modifyAmountElement(const T &element, int amount);

    ~Repo();

    map<T, int> getRepo();

    Repo<T>& operator=(const Repo<T> &repo1);

    Repo<T>& operator=(const map<T, int>&repo1);

    int amountOfElement(const T &element);
};



#endif //LAB9_10_REPO_H
