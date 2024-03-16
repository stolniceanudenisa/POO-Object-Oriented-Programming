#pragma once
 

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Produs {
protected:
    string nume;
    int cod, pret;
    int nrap;

public:
    Produs();
    Produs(int cod, string nume, int pret, int nrap);
    Produs(const Produs& p);
    ~Produs();

    string getNume();
    void setNume(string nume);
    int getPret();
    void setPret(int pret);

    int getCod();
    void setCod(int cod);

    void setNraparitii(int nrap);
    int getNraparitii();

    Produs& operator=(const Produs& p);

    bool operator==(const Produs& p);

    string toString() const {
        stringstream ss;
        ss << "Cod: " << this->cod << " | Denumire: " << this->nume << " | Pret: " << this->pret << " | Nr bucati: " << this->nrap;
        return ss.str();
    }


};