#include "produs.h"
#include<string>

using namespace std;

Produs::Produs() {
    this->pret = -1;
    this->cod = -1;
    this->nume = nullptr;
}

Produs::Produs(int cod, string nume, int pret) {
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
}

Produs::Produs(const Produs& prod) {
    this->cod = prod.cod;
    this->nume = prod.nume;
    this->pret = prod.pret;
}

int Produs::getCod() {
    return this->cod;
}

int Produs::getPret() {
    return this->pret;
}

string Produs::getNume() {
    return this->nume;
}

void Produs::setCod(int cod) {
    this->cod = cod;
}

void Produs::setNume(string nume) {
    this->nume = nume;
}

void Produs::setPret(int pret) {
    this->pret = pret;
}

Produs& Produs::operator=(const Produs& prod) {
    if (this != &prod) {
        this->pret = prod.pret;
        this->nume = prod.nume;
        this->cod = prod.cod;
    }
    return *this;
}

bool Produs::operator==(const Produs& prod) const {
    return nume == prod.nume && cod == prod.cod && pret == prod.pret;
}

Produs::~Produs() {

}

string Produs::ToString() {
    return "Cod: " + to_string(this->cod) + " | Denumire: " + this->nume + " | Pret: " + to_string(this->pret);
    //return "cod: " + to_string(this->cod) + ", nume: " + this->nume + ", pret: " + to_string(pret);
}
