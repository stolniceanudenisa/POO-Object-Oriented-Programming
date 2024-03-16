#include "ui.h"
#include<iostream>
#include<string>

using namespace std;

UI::UI(Service service) {
    this->service = service;
}

void UI::printMenu() {
    cout << endl;
    cout << "1. Adauga Produs" << endl;
    cout << "2. Modifica Produs\n";
    cout << "3. Sterge produs\n";
    cout << "4. Cumpara produs\n";
    cout << "5. Adauga bani in tonomat" << endl;
 
    cout << "a. Afiseaza tonomat + produse\n";
    //cout << "a1. Afiseaza toate produsele\n";
     
    cout << "x. Iesire\n";
    cout << "Alegeti optiunea : ";
    cout << endl;

   /*  
    cout << "5. Sorteaza dupa pret/bucata" << endl;
    cout << "6. Sorteaza dupa numarul de exemplare" << endl;
    cout << "7. Afisare cu pret mai mic decat cel dat" << endl;
    cout << "8. Elimina produs din tonomat" << endl;
    cout << "10. Afisare buget si produsele Tonomatului" << endl;
    cout << "0. Exit" << endl;
    cout << "Alegeti optiunea : ";*/
 

}

void UI::addProdus() {
    string nume;
    int pret, cod, nrapp;
    cout << "Introduceti codul produsului: ";
    cin >> cod;
    cout << "Introduceti numele produsului: ";
    cin >> nume;
    cout << "Introduceti pretul produsului: ";
    cin >> pret;
    cout << "Introduceti numarul de aparitii: ";
    cin >> nrapp;
    this->service.addProd(cod, nume, pret, nrapp);
}

void UI::addBancnote() {
    int pret;
    cout << "Introduceti bancnota: ";
    cin >> pret;
    this->service.updateBuget(pret);
}

void UI::modifProd() {
    int pret, cod, nrapp;
    string nume;
    cout << "Introduceti codul produsului: ";
    cin >> cod;
    cout << "Introduceti numele produsului: ";
    cin >> nume;
    cout << "Introduceti pretul produsului: ";
    cin >> pret;
    cout << "Introduceti numarul de aparitii: ";
    cin >> nrapp;
    service.updateProd(cod, nume, pret, nrapp);
}

void UI::buyProd() {
    int buget;
    cout << "Introduceti suma: ";
    cin >> buget;
    int ok = 1, cod;
    while (ok) {
        for (auto prod : service.getAll()) {
            cout << "nr aparitii: " << prod.second << ", " << prod.first.ToString() << endl;
        }
        cout << endl << "Ce doriti sa cumparati de: " << buget << " lei?"<<endl << endl;
        cout << "Codul produsului dorit: ";
        cin >> cod;
        int res = service.buyProdus(cod, buget);
        if (res == -1)
            cout << "Produsul nu a fost gasit" << endl;
        else
            if (res == -2)
                cout << "Tonomatul nu are in stoc acest produs" << endl;
            else
                if (res == -3)
                    cout << "Buget insuficient" << endl;

        cout << endl << "Banii ramasi: " << buget << endl << endl;
        cout << "Doriti sa continuati?" << endl;
        cout << "1. DA" << endl << "0. NU" << endl;
        cin >> ok;
        if (ok == 1) {
            int pret;
            cout << endl << "BUGET DUMNEAVOASTRA: " << buget << endl << endl;
            cout << "Doriti sa adaugati bancnote?" << endl;
            cout << "1. DA" << endl << "0. NU" << endl;
            cin >> pret;
            if (pret) {
                cout << "Introduceti bancnote: ";
                cin >> pret;
                buget = buget + pret;
            }
        }
        else
            cout << "RESTUL DUMNEAVOASTRA: " << buget << endl << endl;
    }
}

//
//void UI::sortPret() {
//    vector<pair<Produs, int>> v = service.sortPrice();
//    for (int i = 0; i < v.size(); i++)
//        cout << "unit: " << v[i].second << " " << v[i].first.ToString() << endl;
//}
//
//void UI::sortUnit() {
//    vector<pair<Produs, int>> v = service.sortUnit();
//    for (int i = 0; i < v.size(); i++)
//        cout << "unit: " << v[i].second << ", " << v[i].first.ToString() << endl;
//}
//
//void UI::filPret() {
//    int price;
//    cout << "Introduceti pretul dorit: ";
//    cin >> price;
//    vector<pair<Produs, int>> v = service.lowPrice(price);
//    for (int i = 0; i < v.size(); i++)
//        cout << "unit: " << v[i].second << ", " << v[i].first.ToString() << endl;
//}

void UI::afisTonomat() {
    cout << "Bani din tonomat: " << service.getBuget() << endl;
    cout << "Produse: " << endl;
    for (auto prod : service.getAll())
        cout << "nr aparitii: " << prod.second << ", " << prod.first.ToString() << endl;
}

void UI::Menu() 
{
    string optiune; 
    bool optiuneCorecta;
    while (true) {
        printMenu();
        optiuneCorecta = false;
        getline(cin, optiune);

        if (optiune == "1")
        {
            optiuneCorecta = true;
            this->addProdus();
        }
        else if (optiune == "2")
        {
            optiuneCorecta = true;
            this->modifProd();
        }
        else if (optiune == "3")
        {
            optiuneCorecta = true;
            this->delProd();
        }

        else if (optiune == "4")
        {
            optiuneCorecta = true;
            buyProd();
        }

        else if (optiune == "5")
        {
            optiuneCorecta = true;
            this->addBancnote();
        }
 
         
        else if (optiune == "a")
        {
            optiuneCorecta = true;
            afisTonomat();
            /*
            this->showAll(this->ctrl.getAll());*/
        }
        else if (optiune == "x")
        {
            break;
        }
        /*else if (!optiuneCorecta)
        {
            cout << "Optiune gresita! Reincercati\n";
        }*/

    }
    
}

void UI::delProd() 
{
    int cod;
    cout << "Codul produsului de sters: ";
    cin >> cod;
    service.deleteProd(cod);
}