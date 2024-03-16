#pragma once
#include<iostream>
#include <string>

using namespace std;

class Produs {
private:
    int cod;
    string nume;
    int pret;
public:
    Produs();
    Produs(int cod, string nume, int pret);
    Produs(const Produs& prod);
    int getCod();
    int getPret();
    string getNume();
    void setCod(int cod);
    void setNume(string nume);
    void setPret(int pret);
    Produs& operator=(const Produs& prod);
    bool operator==(const Produs& prod) const;
    string ToString();
    ~Produs();


};

