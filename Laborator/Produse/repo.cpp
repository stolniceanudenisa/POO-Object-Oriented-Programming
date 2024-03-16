//
// Created by 40766 on 05.05.2023.
//
#include "repo.h"

//
//Repo::Repo(ValidatorProdus* validator)
//{
//    this->validator = validator;
//}

Repo::Repo()
{
}

Repo::~Repo()
{
    for (int i = 0; i < this->produse.size(); i++)
    {
        delete this->produse[i];
    }

}

vector<Produs*> Repo::getAll()
{
    return this->produse;
}

Produs* Repo::get(int poz)
{
    if (poz < 0 || poz >= this->produse.size())
    {
        return nullptr;
    }
    return this->produse[poz];
    //return this->produse[poz]->clone();
}

Produs* Repo::find(string nume)
{
    for (int i = 0; i < this->produse.size(); i++)
    {
        if (this->produse[i]->getNume() == nume)
        {
            //return this->produse[i]->clone();
            return this->produse[i];
        }
    }
    return nullptr;
}

void Repo::addProdus(Produs* p)
{

    this->produse.push_back(p);
    //this->produse.push_back(p->clone());
}

