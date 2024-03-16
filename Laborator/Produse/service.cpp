//
// Created by 40766 on 05.05.2023.
//

#include "service.h"
#include "produs.h"
#include <algorithm>


Service::Service(RepoFile& repoProdus) : repoProdus(repoProdus)
{
}


Service::~Service() {

}

vector<Produs*> Service::getAll()
{
    vector<Produs*> produse = this->repoProdus.getAll();
    produse.insert(produse.end(),produse.begin(),produse.end());
    return produse;
}

void Service::addProdus(int cod, string nume, int pret)
{
    Produs* p = new Produs(cod,nume, pret);
    this->repoProdus.addProdus(p);
}
