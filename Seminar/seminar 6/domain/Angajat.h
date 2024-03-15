//
// Created by user on 25-May-23.
//

#ifndef SEM_6_313_ANGAJAT_H
#define SEM_6_313_ANGAJAT_H
#include <string>

class Angajat {
private:
    std::string nume;
    float salar;
    std::string studii;
public:
    Angajat(const std::string &nume, float salar, const std::string &studii);

    const std::string &getNume() const;

    const std::string &getStudii() const;

    void setSalar(float salar);

    float getSalar() const;

    std::string toString();
};


#endif //SEM_6_313_ANGAJAT_H
