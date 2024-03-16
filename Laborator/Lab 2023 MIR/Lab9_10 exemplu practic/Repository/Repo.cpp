//
// Created by fabia on 4/20/2022.
//

#include "Repo.h"
#include "NotFoundElementException.h"

//template <typename T> Repo<T>::Repo() {
//};

//template <typename T> Repo<T>::Repo(T) {
//
//}

template <typename T>
void Repo<T>::addElement(T element, int noElements) {
    this->repo.insert(pair<T, int>(element, noElements));
}

template<typename T>
Repo<T>::~Repo() = default;

template<typename T>
Repo<T>& Repo<T>::operator=(const Repo<T> &repo1) {
    this->repo = repo1;
    return *this;
}

template<typename T>
map<T, int> Repo<T>::getRepo() {
    return this->repo;
}

template<typename T>
void Repo<T>::deleteElement(T element) {
    if(this->repo.find(element) == this->repo.end())
        throw ElementNotFoundException("The element doesn't exit");
    this->repo.erase(element);
}


template<typename T>
Repo<T>& Repo<T>::operator=(const map<T, int>& givenMap){
    this->repo = givenMap;
    return *this;
}

template<typename T>
void Repo<T>::modifyAmountElement(const T &element, int amount){
    if(this->repo.find(element) == this->repo.end())
        throw ElementNotFoundException("The element doesn't exit");
    auto it = this->repo.find(element);
    it -> second +=amount;
}

template<typename T>
int Repo<T>::amountOfElement(const T &element) {
    if(this->repo.find(element) == this->repo.end())
        throw ElementNotFoundException("The element doesn't exit");
    auto it = this->repo.find(element);
    return it -> second;
}

//template<typename T>
//void Repo<T>::deleteAmountElement(const T &element, int amount) {
//
//}

