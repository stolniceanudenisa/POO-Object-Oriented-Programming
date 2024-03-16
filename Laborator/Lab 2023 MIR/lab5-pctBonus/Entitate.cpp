//
// Created by alex t. on 22/03/2023.
//

#include "Entitate.h"

/// Constructor
/// \In: -
/// \Out: an empty object of type Entitate
Entitate::Entitate() {
    this->raza = 0;
    this->cX = 0;
    this->cY = 0;
}

/// Constructor with parameters
/// \In: raza, cX, cY
/// \Out: an object of type Entitate that contains the given info
Entitate::Entitate(int raza, int cX, int cY) {
    this->raza = raza;
    this->cX = cX;
    this->cY = cY;
}

/// Copy constructor
/// \In: an object c of type Entitate
/// \Out: another object of type Entitate that contains the same info as c
Entitate::Entitate(const Entitate &c) {
    this->raza = c.raza;
    this->cX = c.cX;
    this->cY = c.cY;
}

/// \def getter
/// \In: an object of type Entitate
/// \Out: raza Entitate
int Entitate::getRaza() {
    return this->raza;
}

/// \def getter
/// \In: an object of type Entitate
/// \Out: coordonata x
int Entitate::getCX() {
    return this->cX;
}

/// \def getter
/// \In: an object of type Entitate
/// \Out: coord Y
int Entitate::getCY() {
    return this->cY;
}

/// \def setter
/// \In: an object of type Entitate and a raza
/// \Out: the same object with a new raza
void Entitate::setRaza(int raza) {
    this->raza = raza;
}

/// \def setter
/// \In: an object of type Entitate and a cX
/// \Out: the same object with a new name
void Entitate::setCX(int cX) {
    this->cX = cX;
}

/// \def setter
/// \In: an object of type Entitate and a name (string)
/// \Out: the same object with a new name
void Entitate::setCY(int cY) {
    this->cY = cY;
}

/// \def calculeaza aria
/// \In -
/// \Out Aria entitatii
double Entitate::aria() const {
    return 3.14*this->raza*this->raza;
}

/// \def calculeaza perimetru
/// \In -
/// \Out -
int Entitate::perimetru() {
    return 2*3.14*this->raza;
}

/// \def suprascrie operator ==
/// \In obiect de tip entitate
/// \Out valoarea true sau false
bool Entitate::operator==(const Entitate &e) {
    return this->raza == e.raza and this->cX == e.cX and this->cY == e.cY;
}

/// \def suprascrie operator >
/// \In obiect de tip entitate
/// \Out cel mai mare dintre obiecte
bool Entitate::operator>(const Entitate &e) {
    if (this->aria() > e.aria())
        return true;
    return false;
}

/// \def operator >> de cititre pt entitate
std::istream &operator>>(std::istream &is, Entitate& e) {
    int raza, cX, cY;
    is >> raza >> cX >> cY;
    e.setRaza(raza);
    e.setCX(cX);
    e.setCY(cY);
    return is;
}

/// \def operator << de afisare pt entitate
std::ostream &operator<<(std::ostream &os, Entitate &e) {
    os << "Entitatea: cu raza = " << e.getRaza() << " de coordonata x = " << e.getCX() << " si de coordonata y = " << e.getCY() << '\n';
    return os;
}

/// \def suprascrie operatorul =
Entitate &Entitate::operator=(const Entitate &e) {
    this->raza = e.raza;
    this->cY = e.cY;
    this->cX = e.cX;
    return *this;
}



