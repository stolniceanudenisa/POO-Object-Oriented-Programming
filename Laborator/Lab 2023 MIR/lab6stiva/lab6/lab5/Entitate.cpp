
#include "Entitate.h"
#include <cmath>

Entitate::Entitate() {
    this->latura1 = 0;
    this->latura2 = 0;
    this->latura3 = 0;
}

Entitate::Entitate(int latura1, int latura2, int latura3) {
    this->latura1 = latura1;
    this->latura2 = latura2;
    this->latura3 = latura3;
}

Entitate::Entitate(const Entitate &tr) {
    this->latura1 = tr.latura1;
    this->latura2 = tr.latura2;
    this->latura3 = tr.latura3;
}


int Entitate::getLatura1() const {
    return this->latura1;
}


int Entitate::getLatura2() const {
    return this->latura2;
}


int Entitate::getLatura3() const {
    return this->latura3;
}


void Entitate::setLatura1(int latura1) {
    this->latura1 = latura1;
}


void Entitate::setLatura2(int latura2) {
    this->latura2 = latura2;
}


void Entitate::setLatura3(int latura3) {
    this->latura3 = latura3;
}


int Entitate::arie() const {
    int sp = (latura1 + latura2 + latura3) / 2;
    return sqrt(sp * (sp - latura1) * (sp - latura2) * (sp - latura3));

}


bool Entitate::operator==(const Entitate &e) {
    return this->latura1 == e.latura1 and this->latura2 == e.latura2 and this->latura3 == e.latura3;
}


Entitate &Entitate::operator>(const Entitate &e) {
    if (this->arie() > e.arie())
        return *this;
}
//
///// operator >> de cititre pt entitate
std::istream &operator>>(std::istream &is, Entitate& e) {
    int latura1, latura2, latura3;
    is >> latura1 >> latura2 >> latura3;
    e.setLatura1(latura1);
    e.setLatura2(latura2);
    e.setLatura3(latura3);
    return is;
}

///// operator << de afisare pt entitate
std::ostream &operator<<(std::ostream &os, Entitate &e) {
    os << "Entitatea: cu lat1 = " << e.getLatura1() << " si lat2 = " << e.getLatura2() << " si lat3 = " << e.getLatura3() << '\n';
    return os;
}


Entitate &Entitate::operator=(const Entitate &e) {
    this->latura1 = e.latura1;
    this->latura2 = e.latura2;
    this->latura3 = e.latura3;
    return *this;
}

int Entitate::get_perimetru() {
    return latura1 + latura2 + latura3;
}



