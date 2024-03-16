//
// Created by 40766 on 12.04.2023.
//

#ifndef LAB7_8FINAL_REPO_H
#define LAB7_8FINAL_REPO_H



#include "tranzactie.h"
#include <vector>

class Repo{
private:
    Tranzactie tranzactii[100];
    int lungime;
public:
    Repo();
    ~Repo();
    Tranzactie* get_all();
    int get_size();
    void add_elem(const Tranzactie& tr);

    void delete_elem_zi(int ziua);
    void delete_elem_interval(int ziuainceput, int ziuafinal);
    void delete_elem_tip(char* tip);

    void update_elem(const Tranzactie& oldtr, const Tranzactie& newtr);
    void update_elem2(int pos, Tranzactie &elem);

    void afisare_elems();
    void afisare_elems_tip(char* tip);
    void afisare_elems_maimare_suma(int suma);
    void afisare_elems_suma_egala(int suma);
    void afisare_elems_sold_zi(int ziua);

    void afisare_max_out(int ziua, char* tip);

    void suma_totala_tip(char* tip);
    void filtru_in(char* tip);
    void filtru_in_suta(char* tip, int suma);

    void set_all(const vector<Tranzactie>& newList);

    Tranzactie getAt(int pos);

};




#endif //LAB7_8FINAL_REPO_H
