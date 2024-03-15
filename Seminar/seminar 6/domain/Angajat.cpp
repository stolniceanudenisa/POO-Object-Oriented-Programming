//
// Created by user on 25-May-23.
//

#include "Angajat.h"

Angajat::Angajat(const std::string &nume, float salar, const std::string &studii) : nume(nume), salar(salar),
                                                                                    studii(studii) {}

const std::string &Angajat::getNume() const {
    return nume;
}

const std::string &Angajat::getStudii() const {
    return studii;
}

void Angajat::setSalar(float salar) {
    this->salar = salar;
}

std::string Angajat::toString() {
    std::string string_angajat;
    string_angajat = nume + " " + std::to_string(salar) + " " + studii;
    return string_angajat;
}

float Angajat::getSalar() const {
    return salar;
}
