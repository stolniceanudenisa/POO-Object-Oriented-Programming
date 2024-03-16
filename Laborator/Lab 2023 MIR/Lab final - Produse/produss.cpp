
#include <vector>
#include <string>
#include <cstring>
#include "produss.h"


//constructor
Produs::Produs()
{
    this->cod = 0;
    this->nume = "";
    this->pret = 0;
    this->nrap = 0;
}
 
//constructor cu parametri
Produs::Produs(int cod, string nume, int pret, int nrap) {
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
    this->nrap = nrap;
}

// constructor de copiere
Produs::Produs(const Produs& p)
{
    this->cod = p.cod;
    this->nume = p.nume;
    this->pret = p.pret;
    this->nrap = p.nrap;
}

//destructor
Produs::~Produs()
{
}

//getter pentru nume
string Produs::getNume()
{
    return this->nume;
}

//setter pentru nume
void Produs::setNume(string nume)
{
    this->nume = nume;
}

//getter pentru pret
int Produs::getPret()
{
    return this->pret;
}
//setter pentru pret
void Produs::setPret(int pret)
{
    this->pret = pret;
}

//getter pentru cod
int Produs::getCod()
{
    return this->cod;
}

//setter pentru cod
void Produs::setCod(int cod)
{
    this->cod = cod;
}


//setter pentru nr aparitii
void Produs::setNraparitii(int nrap)
{

    this->nrap = nrap;
}
//getter pentru nraparitii
int Produs::getNraparitii()
{

    return this->nrap;
}

//operator de atribuire
Produs& Produs::operator=(const Produs& p)
{
    if (this == &p)
    {
        return *this;
    }
    this->cod = p.cod;
    this->nume = p.nume;
    this->pret = p.pret;
    this->nrap = p.nrap;
    return *this;
}

//operator de egalitate
bool Produs::operator==(const Produs& p)
{
    return this->cod == p.cod && this->nume == p.nume && this->pret == p.pret && this->nrap == p.nrap;
}


