#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include "ui.h"
#include "valpexc.h"
#include "notfoundexception.h"



using namespace std;

UI::UI(Service& ctrl) : ctrl(ctrl)
{
}

UI::~UI()
{
}

void UI::runMenu()
{
    string optiune;
    bool optiuneCorecta;
    while (true)
    {
        cout << endl;
        this->displayMenu();
        cout << endl;
        this->showAll(this->ctrl.getAll());
        optiuneCorecta = false;
        cout << endl;
        cout << "Introduceti optiunea: ";
        getline(cin, optiune);
        if (optiune == "1")
        {
            optiuneCorecta = true;
            this->addProdus();
        }
        else if (optiune == "2")
        {
            optiuneCorecta = true;
            this->updateProdus();
        }
        else if (optiune == "3")
        {
            optiuneCorecta = true;
            this->deleteProdusCod();
        }
        else if (optiune == "4")
        {
            optiuneCorecta = true;

            this->cumparaProdus();
        }
        else if (optiune == "5")
        {
            optiuneCorecta = true;
            this->filtrareDupaPret();
        }

        else if (optiune == "6")
        {
            optiuneCorecta = true;
            this->sorteazaDupaNume();
        }
        else if (optiune == "61")
        {
            optiuneCorecta = true;
            this->sorteazaDupaPret();
        }
        else if (optiune == "a")
        {
            optiuneCorecta = true;
            this->showAll(this->ctrl.getAll());
        }
        else if (optiune == "at")
        {
            optiuneCorecta = true;
            afisarebanitonomat();
        }
        else if (optiune == "x")
        {
            break;
        }
        /*if (!optiuneCorecta)
        {
            cout << "Optiune gresita! Reincercati\n";
        }*/
    }
}

void UI::displayMenu()
{
    cout << "1. Adauga Produs\n";
    cout << "2. Modifica Produs\n";
    cout << "3. Sterge produs\n";
    cout << "4. Cumpara produs\n";
    cout << "5. Filtrare dupa pret min/max\n";
    cout << "6. Sorteaza dupa nume\n";
    cout << "61. Sorteaza dupa pret\n";
    cout << "a. Afiseaza toate produsele\n";
    cout << "at. Afiseaza bani tonomat\n";
    cout << "x. Iesire\n";
}

void UI::showAll(vector<Produs*> produse)
{

    //for (const auto& produs : produse) {
    //    cout << produs->toString() << endl;
    //}

    for (int i = 0; i < produse.size(); i++)
    {
        cout << produse[i]->toString() << '\n';
    }


}


void UI::addProdus()
{

    int cod, nrap;
    string denumire;
    int pret;

    cout << "Introduceti codul produsului: ";
    cin >> cod;
    cin.ignore(); // ignore newline character left in the input stream

    cout << "Introduceti denumirea produsului: ";
    getline(cin, denumire);

    cout << "Introduceti pretul produsului: ";
    cin >> pret;

    cout << "Introduceti nr de aparitii: ";
    cin >> nrap;
    cin.ignore(); // ignore newline character left in the input stream


    try {
        this->ctrl.addProdus(cod, denumire, pret, nrap);
    }
    catch (ValidationException& ve)
    {
        cout << ve.what() << endl;
    }
    

}

void UI::updateProdus()
{

   int cod, nrap;
    string denumire;
    double pret;

    cout << "Introduceti codul produsului existent: ";
    cin >> cod;
    cin.ignore();

    cout << "Introduceti denumirea produsului existent: ";
    getline(cin, denumire);
    cin.ignore();

    cout << "Introduceti pretul nou al produsului: ";
    cin >> pret;

    cout << "Introduceti nr de aparitii: ";
    cin >> nrap;
    cin.ignore();  
 
 
    try {
        this->ctrl.updateProdus(cod,denumire, pret, nrap);
    }
    catch (ValidationException& ve)
    {
        cout << ve.what() << endl;
    }
    catch (NotFoundException& ve)
    {
        cout << ve.what() << endl;
    }
}

void UI::deleteProdus()
{
    string nume;
    cout << "Dati numele produsului de sters: ";
    getline(cin, nume);
    
    try {
        this->ctrl.deleteProdus(nume);
    }
    catch (NotFoundException& ve)
    {
        cout << ve.what() << endl;
    }
}
void UI::deleteProdusCod()
{
    int cod;

    cout << "Dati codul produsului de sters: ";
    cin >> cod;
    cin.ignore();
 

    try {
        this->ctrl.deleteProdusCod(cod);
    }
    catch (NotFoundException& ve)
    {
        cout << ve.what() << endl;
    }
}
 
void UI::cumparaProdus()
{
    int buget;
    cout << "Introduceti suma: ";
    cin >> buget;
    int ok = 1, cod;
    while (ok)
    {

        cout << endl << "Ce doriti sa cumparati de: " << buget << " lei?" << endl << endl;
        cout << "Codul produsului dorit: ";
        cin >> cod;
        int res = ctrl.buyProdus(cod, buget);


        if (res == -1)
            cout << "Produsul nu a fost gasit" << endl;
        else
            if (res == -2)
                cout << "Tonomatul nu are in stoc acest produs" << endl;
            else
                if (res == -3)
                    cout << "Bani insuficienti" << endl;

        cout << endl << "Banii ramasi: " << buget << endl << endl;
        
        cout << "Mai vreti sa cumparati alt produs?" << endl;
        cout << "1. Da" << endl << "0. Nu" << endl;
        cin >> ok;
        if (ok == 1) {
            int pret;
            cout << endl << "Banii dumneavoastra: " << buget << endl << endl;
            cout << "Doriti sa mai adaugati bani?" << endl;
            cout << "1. Da" << endl << "0. Nu" << endl;
            cin >> pret;
            if (pret) {
                cout << "Introduceti bani: ";
                cin >> pret;
                buget = buget + pret;
            }
        }
        else
        {
            //this->ctrl.deleteProdusCod(cod);
            cout << "Restul dumneavoastra: " << buget << endl << endl;
        }
    }
}

void UI::filtrareDupaPret()
{
    string buffer;
    int pretMin, pretMax;
    cout << "Dati pretul minim: ";
    getline(cin, buffer);
    pretMin = stoi(buffer);
    cout << "Dati pretul maxim: ";
    getline(cin, buffer);
    pretMax = stoi(buffer);

    vector<Produs*> rezultat = this->ctrl.filterByPrice(pretMin, pretMax);
    this->showAll(rezultat);
}

void UI::sorteazaDupaNume()
{
    vector<Produs*> rezultat = this->ctrl.sorteazaDupaNume();
    this->showAll(rezultat);
}

void UI::sorteazaDupaPret()
{
    vector<Produs*> rezultat = this->ctrl.sorteazaDupaPret();
    this->showAll(rezultat);
}

void UI::afisarebanitonomat()
{
    this->ctrl.afisareBaniTonomat();
}
