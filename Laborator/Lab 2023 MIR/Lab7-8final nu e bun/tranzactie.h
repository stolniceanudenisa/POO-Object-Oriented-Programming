//
// Created by 40766 on 12.04.2023.
//

#ifndef LAB7_8FINAL_TRANZACTIE_H
#define LAB7_8FINAL_TRANZACTIE_H


#include <iostream>
using namespace std;

class Tranzactie{
private:
    int ziua, suma;
    char* tip;
    char* descriere;
public:
    Tranzactie();
    Tranzactie(int ziua, int suma, const char* tip, const char* descriere);
    Tranzactie(const Tranzactie& tr);
    ~Tranzactie();

    int get_ziua();
    int get_suma();
    char* get_tip();
    char* get_descriere();

    void set_ziua(int ziua);
    void set_suma(int suma);
    void set_tip(const char* tip);
    void set_descriere(const char* descriere);

    Tranzactie& operator=(const Tranzactie& tr);
    bool operator==(const Tranzactie& tr);
    friend ostream& operator<<(ostream& os, const Tranzactie& tr);
    friend istream& operator>>(istream& is, Tranzactie& tr);
};



#endif //LAB7_8FINAL_TRANZACTIE_H
