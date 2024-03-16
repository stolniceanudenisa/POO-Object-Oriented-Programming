//
// Created by 40766 on 15.04.2023.
//

#ifndef LAB7_8FINAL_SERVICE_H
#define LAB7_8FINAL_SERVICE_H

#include "repo.h"
#include <vector>
#include <stack>


class Service{
private:
    Repo& repo;
    stack<vector<Tranzactie>> history;
public:
    Service(Repo& repo);
    ~Service();
    vector<Tranzactie> getAll_service();
    Tranzactie* allTransactions = repo.get_all();
    void afisare_elemente_toate();
    void afisare_elems_tip_service(char* tip);
    void afisare_elems_maimare_suma_service(int suma);
    void afisare_elems_suma_egala_service(int suma);
    void afisare_elems_sold_zi_service(int ziua);
    void afisare_max_out_service(int ziua, char* tip);
    void filtru_in_service(char* tip);
    void filtru_in_suta_service(char* tip, int suma);
    void suma_totala_tip_service(char* tip);
    void add_elem_service(int ziua, int suma, const char *tip, const char *descriere);
    void delete_elem_zi_service(int ziua);
    void delete_elem_interval_service(int ziuai, int ziuaf);
    void delete_elem_tip_service( char *tip);
    void update_elem_service(const Tranzactie& oldtr, const Tranzactie& newtr);
    void update_elem_service2(int pos, int ziua, int suma, char *tip, char* descriere);

    bool undo();
    int get_size_service();

    void pt_inloc_suma(int ziua, int suma, char* tip, char* descriere);
};




#endif //LAB7_8FINAL_SERVICE_H
