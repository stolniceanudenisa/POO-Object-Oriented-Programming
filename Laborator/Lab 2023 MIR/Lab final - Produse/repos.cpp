
#include "repos.h"
#include "produss.h"
#include "notfoundexception.h"


//constructor
Repo::Repo(ValidatorProdus* validator)
{
    this->validator = validator;
}


Repo::Repo()
{
}
//destructor
Repo::~Repo()
{
    for (int i = 0; i < this->produse.size(); i++)
    {
        delete this->produse[i];
    }
    delete this->validator;

}

//functie ce returneaza lungimea vectorului din repo

int Repo::size()
{
    return produse.size();
}

//functie ce returneaza produsul de pe o pozitie anume
Produs* Repo::get_at(int pos)
{
    //if (pos < 0 || pos >= this->produse.size())
    //{
    //    return nullptr;
    //}
    return this->produse[pos];
}
//functie ce returneaza toate produsele din repo
vector<Produs*> Repo::getAll()
{
    return this->produse;
}



//functie ce returneaza produsul de pe o pozitie anume
Produs* Repo::get(int poz)
{
    if (poz < 0 || poz >= this->produse.size())
    {
        return nullptr;
    }
    return this->produse[poz];

}



//functie ce returneaza produsul cu un nume
Produs* Repo::find(string nume)
{
    for (int i = 0; i < this->produse.size(); i++)
    {
        if (this->produse[i]->getNume() == nume)
        {

            return this->produse[i];
        }
    }
    return nullptr;
}



//functie ce returneaza produsul cu un cod anume
Produs* Repo::findcod(int cod)
{
    for (int i = 0; i < this->produse.size(); i++)
    {
        if (this->produse[i]->getCod() == cod)
        {

            return this->produse[i];
        }
    }
    return nullptr;
}



//functie ce returneaza true daca un produs cu un cod e gasit, fals in caz contrar
bool Repo::findbycoderepo(int cod)
{
    for (Produs* prod : produse) {
        if (prod->getCod() == cod) {
            return true;
        }
    }
    return false;
}



//functie ce returneaza adauga in vector un produs
void Repo::addProdus(Produs* p)
{
    this->validator->validate(p);
    this->produse.push_back(p);

}

//functie ce returneaza sterge din vector un produs dupa cod
void Repo::deleteProdusCod(Produs* p)
{
    bool updated = false;
    if (p)
    {
        for (int i = 0; i < this->produse.size(); i++)
        {
            if (this->produse[i]->getCod() == p->getCod())
            {
                delete this->produse[i];
                this->produse.erase(this->produse.begin() + i);
                updated = true;
            }
        }
    }
    if (!updated)
    {
        throw NotFoundException("Nu se poate face stergere, pt. ca produsul nu a fost gasit!");
    }
}

//functie ce returneaza sterge din vector un produs dupa nume
void Repo::deleteProdus(Produs* p)
{
    bool updated = false;
    if (p)
    {
        for (int i = 0; i < this->produse.size(); i++)
        {
            if (this->produse[i]->getNume() == p->getNume())
            {
                delete this->produse[i];
                this->produse.erase(this->produse.begin() + i);
                updated = true;
            }
        }
    }
     if (!updated)
     {
         throw NotFoundException("Nu se poate face stergere, pt. ca produsul nu a fost gasit!");
     }
}
//functie ce returneaza modifiva din vector un produs  
void Repo::updateProdus(Produs* pVechi, Produs* pNou)
{
    this->validator->validate(pNou);
    bool updated = false;

    if (pVechi)
    {
        for (int i = 0; i < this->produse.size(); i++)
        {
            if (*this->produse[i] == *pVechi)
            //if (this->produse[i]->getNume() == pVechi->getNume())
            {
                delete this->produse[i];
                this->produse[i] = pNou;//->clone();
                updated = true;
            }
        }
    }

    if (!updated)
    {
        throw NotFoundException("Nu se poate face update, pt. ca produsul nu a fost gasit!");
    }
}

int Repo::getNumarProduse(string nume) {
    int numarProduse = 0;
    for (Produs* produs : this->produse) {
        if (produs->getNume() == nume) {
            numarProduse += numarProduse;
        }
    }
    return numarProduse;
}



