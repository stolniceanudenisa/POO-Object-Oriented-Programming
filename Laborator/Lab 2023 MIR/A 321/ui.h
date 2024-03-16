#pragma once
#include "service.h"

class UI {
private:
    Service service;
    void printMenu();
    void addProdus();
    void addBancnote();
    void buyProd();
    /*void sortPret();
    void sortUnit();
    void filPret();*/
    void afisTonomat();
    void modifProd();
    void delProd();
public:
    UI(Service service);
    void Menu();
};
