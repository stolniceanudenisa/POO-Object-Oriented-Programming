//
// Created by user on 4/6/2023.
//

#ifndef SEMINAR3_313_UI_H
#define SEMINAR3_313_UI_H

#include "Student.h"
#include "Service.h"

class UI {
private:
    Service service;
    void add();
    void remove();
    void update();
    void find();
    void print_all();
    void number_students();
public:
    UI();
    UI(Service&);
    void menu();

};


#endif //SEMINAR3_313_UI_H
