//
// Created by 40766 on 12.04.2023.
//

#include "tranzactie.h"
#include <cstring>

Tranzactie::Tranzactie() {
    this->ziua=0;
    this->suma = 0;
    this->tip=new char[1];
    strcpy_s(this->tip, 1, "");
    this->descriere=new char[1];
    strcpy_s(this->descriere, 1, "");

}

Tranzactie::Tranzactie(int ziua, int suma, const char *tip, const char *descriere) {
    this->ziua=ziua;
    this->suma = suma;
    if(tip == nullptr)
    {
        this->tip=nullptr;
    }
    else
    {
        this->tip = new char[strlen(tip) + 1];
        strcpy_s(this->tip, strlen(tip) + 1, tip);
    }

    if(descriere == nullptr)
    {
        this->descriere=nullptr;
    }
    else
    {
        this->descriere = new char[strlen(descriere) + 1];
        strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
    }

}


Tranzactie::Tranzactie(const Tranzactie &tr) {
    this->ziua = tr.ziua;
    this->suma = tr.suma;
    if(tr.tip == nullptr)
    {
        this->tip=nullptr;
    }
    else
    {
        this->tip = new char[strlen(tr.tip) + 1];
        strcpy_s(this->tip, strlen(tr.tip) + 1, tr.tip);
    }

    if(tr.descriere == nullptr)
    {
        this->descriere=nullptr;
    }
    else
    {
        this->descriere = new char[strlen(tr.descriere) + 1];
        strcpy_s(this->descriere, strlen(tr.descriere) + 1, tr.descriere);
    }
}

Tranzactie::~Tranzactie() {
    delete[] this->tip;
    delete[] this->descriere;
}

int Tranzactie::get_ziua() {
    return this->ziua;
}

int Tranzactie::get_suma() {
    return this->suma;
}

char *Tranzactie::get_tip() {
    return this->tip;
}

char *Tranzactie::get_descriere()  {
    return this->descriere;
}


void Tranzactie::set_ziua(int ziua) {
    this->ziua=ziua;
}

void Tranzactie::set_suma(int suma) {
    this->suma=suma;
}

void Tranzactie::set_tip(const char *tip) {
    if(tip == nullptr)
    {
        this->tip=nullptr;
    }
    else
    {
        this->tip = new char[strlen(tip) + 1];
        strcpy_s(this->tip, strlen(tip) + 1, tip);
    }
}

void Tranzactie::set_descriere(const char *descriere) {
    if(descriere == nullptr)
    {
        this->descriere=nullptr;
    }
    else
    {
        this->descriere = new char[strlen(descriere) + 1];
        strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
    }
}

Tranzactie& Tranzactie::operator=(const Tranzactie &tr) {
    if (this != &tr)
    {
        this->set_ziua(tr.ziua);
        this->set_suma(tr.suma);
        this->set_tip(tr.tip);
        this->set_descriere(tr.descriere);
    }
    return *this;
}

bool Tranzactie::operator==(const Tranzactie &tr) {
    return this->ziua == tr.ziua &&  this->suma == tr.suma && strcmp(this->tip, tr.tip) == 0  && strcmp(this->descriere, tr.descriere) == 0;
}

ostream &operator<<(ostream &os, const Tranzactie &tr) {
    os << tr.ziua;
    os << tr.suma;
    if (tr.tip == nullptr)
    {
        os << "NULL ";
    }
    else
    {
        os << tr.tip << " ";
    }

    if (tr.descriere == nullptr)
    {
        os << "NULL ";
    }
    else
    {
        os << tr.descriere << " ";
    }

    return os;
}

istream& operator>>(istream& is, Tranzactie &tr)
{
    char tip[20];
    char descriere[20];
    cout<<"Ziua:\n ";
    is >>tr.ziua;
    cout<<"Suma: \n";
    is >> tr.suma;
    cout<<"Tipul: \n";
    is >> tip;
    tr.tip = new char[strlen(tip) + 1];
    strcpy_s(tr.tip, strlen(tip) + 1, tip);
    cout<<"Descrierea:\n ";
    is >> descriere;
    tr.descriere = new char[strlen(descriere) + 1];
    strcpy_s(tr.descriere, strlen(descriere) + 1, descriere);
    return is;
}

