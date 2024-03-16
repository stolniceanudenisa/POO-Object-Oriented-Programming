//
// Created by fabia on 5/3/2022.
//

#ifndef LAB9_10_UI_H
#define LAB9_10_UI_H
#include "Service.h"

class UI {
private:
    Service& service;
public:
    UI(Service& givenService);
    ~UI();

    bool showAllProducts();
    void runMenu();
    void console(string&);
    int handleMoneyExchange(int);
    void handleMoneyChange(int);
};


#endif //LAB9_10_UI_H
