

#include "repo.h"
#include <cstring>
#include <iostream>
#include <map>

/// cosntructor
Repo::Repo() {
    this->lungime = 0;
}

/// destructor
Repo::~Repo() = default;

Tranzactie* Repo::get_all() {
    return this->tranzactii;
}

/// returneaza lungimea vectorului
int Repo::get_size() {
    return this->lungime;
}

/// adaugarea unui obiect de tip tranzactie
void Repo::add_elem(const Tranzactie &tr) {
    if(this->lungime == 100)
        return;
    this->tranzactii[this->lungime] = tr;
    this->lungime++;
}

void Repo::afisare_elems() {
    for(int i=0; i< this->get_size(); i++)
    {
        cout << "Ziua: " << this->tranzactii[i].get_ziua()<<", "<< "Suma: "
        << this->tranzactii[i].get_suma()<<", "<< "Tipul: " <<this->tranzactii[i].get_tip()<<", "<< "Descrierea: "<<this->tranzactii[i].get_descriere();
        cout << endl;
    }
}

void Repo::delete_elem_zi(int ziua) {
    int i = 0;
    while (i < this->get_size()) {
        if (this->tranzactii[i].get_ziua() == ziua) {
            for (int j = i; j < this->get_size() - 1; j++) {
                this->tranzactii[j] = this->tranzactii[j + 1];
            }
            this->lungime--;
        }
        else {
            i++;
        }
    }
}

void Repo::delete_elem_interval(int ziuainceput, int ziuafinal) {
    int i = 0;
    while (i < this->get_size()) {
        int ziua = this->tranzactii[i].get_ziua();
        if (ziuainceput <= ziua && ziua <= ziuafinal) {
            for (int j = i; j < this->get_size() - 1; j++) {
                this->tranzactii[j] = this->tranzactii[j + 1];
            }
            this->lungime--;
        }
        else {
            i++;
        }
    }
}

void Repo::delete_elem_tip(char *tip) {
    int i = 0;
    while (i < this->get_size()) {
        if (strcmp(this->tranzactii[i].get_tip(), tip) == 0) {
            for (int j = i; j < this->get_size() - 1; j++) {
                this->tranzactii[j] = this->tranzactii[j + 1];
            }
            this->lungime--;
        }
        else {
            i++;
        }
    }
}

void Repo::update_elem(const Tranzactie &oldtr, const Tranzactie &newtr) {
    for(int i=0; i< this->get_size(); i++)
    {
        if(this->tranzactii[i] == oldtr)
        {
            this->tranzactii[i] = newtr;
        }
    }
}

void Repo::update_elem2(int pos, Tranzactie &elem) {
    this->tranzactii[pos] = elem;
}

void Repo::afisare_elems_tip(char *tip) {
    for(int i=0; i< this->get_size(); i++)
    {
        if(strcmp(this->tranzactii[i].get_tip(), tip) == 0)
        {
            cout << "Ziua: " << this->tranzactii[i].get_ziua()<<", "<< "Suma: "
                 << this->tranzactii[i].get_suma()<<", "<< "Tipul: " <<this->tranzactii[i].get_tip()<<", "<< "Descrierea: "<<this->tranzactii[i].get_descriere();
            cout << endl;
        }
    }
}

void Repo::afisare_elems_maimare_suma(int suma) {
    for(int i=0; i< this->get_size(); i++)
    {
        if(this->tranzactii[i].get_suma() >suma)
        {
            cout << "Ziua: " << this->tranzactii[i].get_ziua()<<", "<< "Suma: "
                 << this->tranzactii[i].get_suma()<<", "<< "Tipul: " <<this->tranzactii[i].get_tip()<<", "<< "Descrierea: "<<this->tranzactii[i].get_descriere();
            cout << endl;
        }
    }
}

void Repo::afisare_elems_suma_egala(int suma) {
    for(int i=0; i< this->get_size(); i++)
    {
        if(this->tranzactii[i].get_suma() == suma)
        {
            cout << "Ziua: " << this->tranzactii[i].get_ziua()<<", "<< "Suma: "
                 << this->tranzactii[i].get_suma()<<", "<< "Tipul: " <<this->tranzactii[i].get_tip()<<", "<< "Descrierea: "<<this->tranzactii[i].get_descriere();
            cout << endl;
        }
    }
}

void Repo::afisare_elems_sold_zi(int ziua) {
    int sumain=0, sumaout=0;
    for(int i=0; i< this->get_size(); i++)
    {
        if(this->tranzactii[i].get_ziua() == ziua)
        {
            if(strcmp(this->tranzactii[i].get_tip(), "in") == 0)
                sumain = sumain +tranzactii[i].get_suma();

            if(strcmp(this->tranzactii[i].get_tip(), "out") == 0)
                sumaout = sumaout +tranzactii[i].get_suma();
        }
    }
    cout<< abs(sumain -sumaout);
    cout << endl;
}


void Repo::afisare_max_out(int ziua, char* tip) {
    int maxi=-1;
    for(int i=0; i< this->get_size(); i++)
    {
        if(this->tranzactii[i].get_ziua() == ziua && strcmp(this->tranzactii[i].get_tip(), tip) == 0)
        {
            if(this->tranzactii[i].get_suma() > maxi) {
                maxi = this->tranzactii[i].get_suma();
            }
        }
    }
    if(maxi == -1) {
        cout << "Nu exista tranzactii de tipul " << tip << " pentru ziua " << ziua << endl;
    } else {
        cout << "Cea mai valoroasa tranzactie de tip " << tip << " din ziua " << ziua << " este " << maxi << endl;
    }
}



void Repo::suma_totala_tip(char *tip) {
    int suma=0;
    for(int i=0; i< this->get_size(); i++)
    {
        if(strcmp(this->tranzactii[i].get_tip(), tip) == 0)
        {
            suma = suma + tranzactii[i].get_suma();
        }
    }
    cout<< suma;
    cout << endl;
}


void Repo::filtru_in(char *tip) {
    for(int i=0; i< this->get_size(); i++)
    {
        if(strcmp(this->tranzactii[i].get_tip(), tip) == 0)
        {
            cout << "Ziua: " << this->tranzactii[i].get_ziua()<<", "<< "Suma: "
                 << this->tranzactii[i].get_suma()<<", "<< "Tipul: " <<this->tranzactii[i].get_tip()<<", "<< "Descrierea: "<<this->tranzactii[i].get_descriere();
            cout << endl;
        }
    }
}

void Repo::filtru_in_suta(char *tip, int suma) {
    for(int i=0; i< this->get_size(); i++)
    {
        if(strcmp(this->tranzactii[i].get_tip(), tip) == 0 &&  this->tranzactii[i].get_ziua() < suma)
        {
            cout << "Ziua: " << this->tranzactii[i].get_ziua()<<", "<< "Suma: "
                 << this->tranzactii[i].get_suma()<<", "<< "Tipul: " <<this->tranzactii[i].get_tip()<<", "<< "Descrierea: "<<this->tranzactii[i].get_descriere();
            cout << endl;
        }
    }
}

void Repo::set_all(const vector<Tranzactie> &newList) {
    int n = newList.size();
    for (int i = 0; i < n; i++) {
        tranzactii[i] = newList[i];
    }
    lungime = n;
}

Tranzactie Repo::getAt(int pos) {
    if (pos > -1 && pos < this->lungime)
        return this->tranzactii[pos];
}
