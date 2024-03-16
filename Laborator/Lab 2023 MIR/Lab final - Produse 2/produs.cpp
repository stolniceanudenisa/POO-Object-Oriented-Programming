//
// Created by 40766 on 05.05.2023.
//
#include <vector>
#include <string>
#include <cstring>
#include "produs.h"
 

Produs::Produs() {
    this->cod = 0;
    this->nume = "";
    this->pret = 0;
    this->nrap = 0;
}

Produs::Produs(int cod, string nume, int pret, int nrap) {
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
    this->nrap = nrap;
}


Produs::Produs(const Produs& p)
{
    this->cod = p.cod;
    this->nume = p.nume;
    this->pret = p.pret;
    this->nrap = p.nrap;
}

Produs::~Produs()
{
}

string Produs::getNume()
{
    return this->nume;
}

void Produs::setNume(string nume)
{
    this->nume = nume;
}

int Produs::getPret()
{
    return this->pret;
}

void Produs::setPret(int pret)
{
    this->pret = pret;
}

int Produs::getCod()
{
    return this->cod;
}

void Produs::setCod(int cod)
{
    this->cod = cod;
}

int Produs::getNraparitii()
{
    return this->nrap;
}
void Produs::getNraparitii(int nrap)
{
    this->nrap = nrap;
}


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

bool Produs::operator==(const Produs& p)
{
    return this->cod == p.cod && this->nume == p.nume && this->pret == p.pret && this->nrap == p.nrap;
}


