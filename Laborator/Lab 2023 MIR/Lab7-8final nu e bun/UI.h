//
// Created by 40766 on 15.04.2023.
//

#ifndef LAB7_8FINAL_UI_H
#define LAB7_8FINAL_UI_H

#include "service.h"


class UI {
private:
    Service& service;
public:
    UI(Service& service);
    ~UI();

    void run_menu();
private:
    void menu();
    void ui_add_tranz1();

    void ui_afisare_elems();
    void ui_afisare_elems_tip();
    void ui_afisare_elems_maimare_suma();
    void ui_afisare_elems_suma_egala();
    void ui_afisare_elems_sold_zi();


    void ui_stergere_tranz_zi();
    void ui_stergere_tranz_interval_zi();
    void ui_stergere_tranz_tip();
    void ui_modificare_tranzactie();
    void ui_modificare_tranzactie2();
    void ui_inlocuire_suma();

    void ui_suma_totala_tip();
    void ui_max_out();

    void ui_filtru_in();
    void ui_filtru_in_suta();
    void ui_undo();

};


#endif //LAB7_8FINAL_UI_H
