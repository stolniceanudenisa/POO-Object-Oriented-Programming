#pragma once
 
 
#include "service.h"
class UI {
private:
    Service& ctrl;
public:
    UI(Service& ctrl);
    ~UI();
    void runMenu();
private:
    void displayMenu();
    void showAll(vector<Produs*> produse);
    void addProdus();
    void updateProdus();
    void deleteProdus();

    void cumparaProdus();
};

