//
// Created by user on 04-May-23.
//

#ifndef SEMINAR5_311_TARA_H
#define SEMINAR5_311_TARA_H
#include <string>
using  namespace std;


class Tara {
protected:
    string denumire;
    int populatie;
public:
    Tara();
    Tara(string, int);
    Tara(const Tara&);
    string getDenumire();
    int getPop();
    void setDenumire(string);
    void setPop(int);
    string toString();
    Tara& operator=(const Tara&);
    bool operator==(const Tara&);
    ~Tara();
};


#endif //SEMINAR5_311_TARA_H
