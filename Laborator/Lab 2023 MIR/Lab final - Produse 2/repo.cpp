 
#include "repo.h"
#include "produs.h"
 

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
    //delete this->validator;
}

int Repo::size()
{
    return produse.size();
}

Produs* Repo::get_at(int pos)
{
    return this->produse[pos];
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

}

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


void Repo::addProdus(Produs* p)
{
    //this->validator->validate(p);
    this->produse.push_back(p);

}


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
}

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
    /* if (!updated)
     {
         throw NotFoundException("Nu se poate face stergere, pt. ca produsul nu a fost gasit!");
     }*/
}

void Repo::updateProdus(Produs* pVechi, Produs* pNou)
{
    //this->validator->validate(pNou);
    bool updated = false;

    if (pVechi)
    {
        for (int i = 0; i < this->produse.size(); i++)
        {
            if (this->produse[i]->getNume() == pVechi->getNume())
            {
                delete this->produse[i];
                this->produse[i] = pNou;//->clone();
                updated = true;
            }
        }
    }

    //if (!updated)
    //{
    //    throw NotFoundException("Nu se poate face update, pt. ca produsul nu a fost gasit!");
    //}
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



