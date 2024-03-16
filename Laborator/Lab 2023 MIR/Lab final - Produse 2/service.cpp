 

#include "service.h"
#include "produs.h"
#include <algorithm>


Service::Service(RepoFile& repo)
{
    this->repo = repo;
}


Service::~Service() {

}

vector<Produs*> Service::getAll()
{
    vector<Produs*> produse = this->repo.getAll();
    //produse.insert(produse.end(),produse.begin(),produse.end());

    return produse;
}

void Service::addProdus(int cod, string nume, int pret, int nrap)
{
    Produs* p = new Produs(cod, nume, pret, nrap);
    this->repo.addProdus(p);
}



void Service::updateProdus(int cod, string nume, int pretnou, int nrap)
{
    Produs* pVechi = this->repo.find(nume);
    Produs* pNou = new Produs(cod, nume, pretnou, nrap);
    this->repo.updateProdus(pVechi, pNou);
}

void Service::deleteProdus(string nume)
{
    Produs* p = this->repo.find(nume);
    this->repo.deleteProdus(p);


    /*try
    {
        this->repoProdus.deleteProdus(pd);
    }
    catch (NotFoundException& ve)
    {
        Produs* ps = this->repoProdus.find(nume);
        this->repoProdus.deleteProdus(ps);
    }*/
}

bool Service::findByCode(int code) {
    for (Produs* prod : getAll()) {
        if (prod->getCod() == code) {
            return true;
        }
    }
    return false;
}



int Service::buyProdus(int cod, int& buget)
{
    vector<Produs*> produse = repo.getAll();
    for (int i = 0; i < produse.size(); i++)
    {
        if (produse[i]->getCod() == cod)
        {
            Produs* p = produse[i];
            if (buget - p->getPret() >= 0) {
                buget = buget - p->getPret();
                //p->setStoc(p->getStoc() - 1);
                //repo.updateProdus(p);
                updateBuget(buget + p->getPret());
                return buget;
            }
        }
    }

}



void Service::deleteProdusCod(int cod)
{
    Produs* p = this->repo.findcod(cod);
    this->repo.deleteProdusCod(p);
}

void Service::updateBuget(int bani) {
    this->bani = this->bani + bani;
}

int Service::getBuget() {
    return this->bani;
}






/* Produs* produs = this->repoProdus.find(nume);
 if (produs == nullptr)
 {
     cout << "Produsul nu exista!" << endl;
     return;
 }

 int pretProdus = produs->getPret();
 if (this->bani < pretProdus)
 {
     cout << "Nu aveti destui bani pentru a cumpara acest produs!" << endl;
     return;
 }

 cout << "Introduceti monede pentru a cumpara produsul (cu o valoare intreaga):" << endl;
 int moneda, sumaIntrodusa = 0;
 while (sumaIntrodusa < pretProdus)
 {
     cin >> moneda;
     if (moneda != 1 && moneda != 5 && moneda != 10 && moneda != 20 && moneda != 50 && moneda != 100 && moneda != 200 && moneda != 500)
     {
         cout << "Moneda introdusa nu este valida!" << endl;
         continue;
     }
     sumaIntrodusa += moneda;
 }

 int rest = sumaIntrodusa - pretProdus;
 cout << "Produsul " << nume << " a fost cumparat! Restul dumneavoastra este: " << rest << " lei." << endl;

 this->bani += pretProdus;
 produs->scadeCantitate();*/
 //this->repoProdus.saveToFile();


int Service::getNumarProduse(string nume)
{
    return 0;

}