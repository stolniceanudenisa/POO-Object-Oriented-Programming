//
// Created by user on 04-May-23.
//

#include "Tara.h"

Tara::Tara() {
    denumire = "";
    populatie = 0;
}

Tara::Tara(string denumire_new, int pop_new) {
    denumire = denumire_new;
    populatie = pop_new;
}

Tara::Tara(const Tara & tara) {
    denumire = tara.denumire;
    populatie = tara.populatie;
}

string Tara::getDenumire() {
    return denumire;
}

int Tara::getPop() {
    return populatie;
}

void Tara::setDenumire(string denumire_new) {
    denumire = denumire_new;
}

void Tara::setPop(int pop) {
    populatie = pop;
}

string Tara::toString() {
    return denumire + " " + to_string(populatie);
}

Tara::~Tara() {
    denumire = "";
    populatie = 0;
}

Tara &Tara::operator=(const Tara & tara) {
    if(this != &tara)
    {
        denumire = tara.denumire;
        populatie = tara.populatie;
    }
    return *this;
}

bool Tara::operator==(const Tara & tara) {
    if(denumire == tara.denumire && populatie == tara.populatie)
        return true;
    return false;
}
