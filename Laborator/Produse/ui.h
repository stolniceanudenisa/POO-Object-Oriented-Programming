//
// Created by 40766 on 05.05.2023.
//
 
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

};

 