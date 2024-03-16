#ifndef LAB9_10_REPOFILE_H
#define LAB9_10_REPOFILE_H
#include "Repo.h"
#include <map>
#include <fstream>

using namespace std;

template<typename T> class RepoFile : public Repo<T> {
private:
    string fileName;
public:

    RepoFile(){

    }

    RepoFile(string file): fileName(file){
        loadFromFile();
    }
    ~RepoFile(){

    }

    void addElement(T element, int n){
        Repo<T>::addElement(element, n);
        this->saveToFile();
    }

    void deleteElement(T element){
        Repo<T>::deleteElement(element);
        this->saveToFile();
    }

    void modifyAmountElement(const T& element, int amount){
        Repo<T>::modifyAmountElement(element, amount);
        this->saveToFile();
    }

    int amountOfElement(const T& element){
         return Repo<T>::amountOfElement(element);

    }

    map<T, int> getRepo(){

        return Repo<T>::getRepo();

    }


    //    Repo<T>& operator=(const Repo<T> &repo1);
    //
    //    Repo<T>& operator=(const map<T, int>&repo1);

private:


    void loadFromFile(){
        ifstream f(this->fileName);
        if(f.is_open())
        {
            T element;
            int n;
            while(!f.eof())
            {
                f >> element >> n;
                this->addElement(element, n);
            }
        }
        f.close();
    }

    void saveToFile(){
        ofstream f(this->fileName);
        map<T, int> repository = this->getRepo();
        for(auto itr = repository.begin(); itr != repository.end(); itr++)
            f << itr->first << ' ' <<  itr->second;
        f.close();
    }



};


#endif //LAB9_10_REPOFILE_H
