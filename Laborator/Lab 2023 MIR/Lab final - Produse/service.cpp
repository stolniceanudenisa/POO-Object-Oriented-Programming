

#include "service.h"
#include "notfoundexception.h"

#include <algorithm>



//constructor
Service::Service(RepoFile& repo) : repo(repo)
{
    this->repo = repo;
     
}

//destructor
Service::~Service() {

}


//functie ce returneaza toate produsele din vector
vector<Produs*> Service::getAll()
{
    vector<Produs*> produse = this->repo.getAll();
     
    return produse;
}

//functie ce adauga un produs in service

void Service::addProdus(int cod, string nume, int pret, int nrap)
{
    Produs* p = new Produs(cod, nume, pret, nrap);
    this->repo.addProdus(p);
}


// functie de modificare a unui produs
void Service::updateProdus(int cod, string nume, int pretnou, int nrap)
{
    Produs* pVechi = this->repo.find(nume);
    Produs* pNou = new Produs(cod, nume, pretnou, nrap);
    this->repo.updateProdus(pVechi, pNou);
}

//functie de stergere a unui produs
void Service::deleteProdus(string nume)
{
    Produs* p = this->repo.find(nume);
    this->repo.deleteProdus(p);

    try
    {
        this->repo.deleteProdus(p);
    }
    catch (NotFoundException& ve)
    {
        Produs* ps = this->repo.find(nume);
        this->repo.deleteProdus(ps);
    }
}


//functie ce returneaza true daca gaseste un produs dupa cod, false altfel
bool Service::findByCode(int code) {
    for (Produs* prod : getAll()) {
        if (prod->getCod() == code) {
            return true;
        }
    }
    return false;
}


//functia de cumparare a unui produs din tonomat
int Service::buyProdus(int cod, int& buget)
{
    vector<Produs*> produse = repo.getAll();
    if (findByCode(cod)) {
        for (int i = 0; i < repo.size(); i++) {
            if (produse[i]->getCod() == cod) {
                if (produse[i]->getNraparitii() < 1)
                    return -2; // daca nu mai e pe stoc
                else {
                    Produs* p = produse[i];
                    if (buget - p->getPret() >= 0) {
                        int rest = buget - p->getPret();
                        int j = bani.size() - 1;
                        while (rest > 0 && j >= 0) {
                            if (bani[j].second > 0 && bani[j].first <= rest) {
                                rest -= bani[j].first;
                                bani[j].second--;
                            }
                            else {
                                j--;
                            }
                        }

                        if (rest == 0) {
                            buget = buget - p->getPret();
                            p->setNraparitii(p->getNraparitii() - 1);
                            updateBuget(buget + p->getPret());
                            return buget;
                        }
                        else {
                            // Nu există bancnote disponibile pentru a da rest
                            // Adaugam bancnotele inapoi in vectorul de bancnote
                            while (j < bani.size() - 1) {
                                bani[j + 1].second++;
                                j++;
                            }
                            return -4;
                        }
                    }
                    else {
                        return -3; //daca nu avem bani
                    }
                }
            }
        }
    }
    else
        return -1; //daca nu exista

    //int valoare_bancnota = bani[i].first; // valoarea bancnotei de pe pozitia i
    //int nr_aparitii = bani[i].second; // numarul de aparitii al bancnotei de pe pozitia i
    ////////////////////////////////////////
    //vector<Produs*> produse = repo.getAll();
    //if (findByCode(cod)) {
    //    for (int i = 0; i < repo.size(); i++) {
    //        if (produse[i]->getCod() == cod) {
    //            if (produse[i]->getNraparitii()  < 1)
    //                return -2; // daca nu mai e pe stoc
    //            else {
    //                Produs* p = produse[i];
    //                if (buget - p->getPret() >= 0) {
    //                    buget = buget - p->getPret();

    //                    p->setNraparitii(p->getNraparitii() - 1);
    //                    updateBuget(buget + p->getPret());
    //                    return buget;
    //                }
    //                else {
    //                    return -3; //daca nu avem bani
    //                }
    //            }
    //        }
    //    }
    //}
    //else
    //    return -1; //daca nu exista

}


// functie ce sterge un produs cu un anumit cod
void Service::deleteProdusCod(int cod)
{
    Produs* p = this->repo.findcod(cod);
    this->repo.deleteProdusCod(p);
}



vector<Produs*> Service::filterByPrice(int pretMin, int pretMax)
{
    vector<Produs*> rezultat;
    for (int i = 0; i < this->repo.getAll().size(); i++)
    {
        Produs* p = this->repo.get(i);
        int pret = p->getPret();
        if (pretMin <= pret && pret <= pretMax)
        {
            rezultat.push_back(p);
        }
    }
   /* for (int i = 0; i < this->repo.getAll().size(); i++)
    {
        Produs* p = this->repo.get(i);
        int pret = p->getPret();
        if (pretMin <= pret && pret <= pretMax)
        {
            rezultat.push_back(p);
        }
    }*/
    return rezultat;
}

vector<Produs*> Service::sorteazaDupaNume()
{
    vector<Produs*> produse = this->repo.getAll();
    sort(produse.begin(), produse.end(), comparaDupaNume);
    return produse;
}
vector<Produs*> Service::sorteazaDupaPret()
{
    vector<Produs*> produse = this->repo.getAll();
    sort(produse.begin(), produse.end(), comparaDupaPret);
    return produse;
}


bool comparaDupaNume(Produs* p1, Produs* p2)
{
    return p1->getNume() < p2->getNume();
}

bool comparaDupaPret(Produs* p1, Produs* p2)
{
    return p1->getPret() < p2->getPret();
}




//functie ce afiseaza banii din tonomat
void Service::afisareBaniTonomat()
{
    for (auto bancnota : bani) {
        cout << "Bancnota " << bancnota.first << " lei: " << bancnota.second << " bucati\n";
    }
}

void Service::updateBuget(int bani) {
    //this->bani = this->bani + bani;
}

int Service::getBuget() {
    return 0;
    //return this->bani;
}