//
// Created by user on 4/6/2023.
//

#include "UI.h"
#

UI::UI() {
}

UI::UI(Service &s) {
    service = s;
}

void UI::add() {
    cout<<"Dati numele studentului: "<<endl;
    string nume;
    cin>>nume;
    cout<<"Dati media studentului: ";
    double medie;
    cin>>medie;
    service.add(nume, medie);
}

void UI::menu() {
    cout<<"Meniu:"<<endl;
    cout<<"1. Afisati studentii existenti: "<<endl;
    cout<<"2. Adaugare studenti: "<<endl;
    cout<<"0. Exit"<<endl;
    int opt;
    cout<<"Dati optiunea: "<<endl;
    cin>>opt;
    while(opt!=0){
        switch(opt){
            case 1:
                break;
            case 2:
                add();
                break;
            case 0:
                break;
        }
    }

}
