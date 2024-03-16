 
#include "ui.h"
#include <iostream>


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
        this->displayMenu();
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
            this->updateProdus();
        }
        else if (optiune == "3")
        {
            optiuneCorecta = true;
            this->deleteProdus();
        }
        else if (optiune == "4")
        {
            optiuneCorecta = true;
            //this->cumparaProdus();
            this->cumparaProdus();
        }

        else if (optiune == "a")
        {
            optiuneCorecta = true;
            this->showAll(this->ctrl.getAll());
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
    cout << "a. Afiseaza toate produsele\n";
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

    this->ctrl.addProdus(cod, denumire, pret, nrap);

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

    cout << "Introduceti pretul nou al produsului: ";
    cin >> pret;

    cout << "Introduceti nr de aparitii: ";
    cin >> nrap;
    cin.ignore(); // ignore newline character left in the input stream

    this->ctrl.updateProdus(cod, denumire, pret, nrap);
    /* try {
         this->ctrl.updateProdus(cod, denumire, pret);
     }*/
     //catch (ValidationException& ve)
     //{
     //    cout << ve.what() << endl;
     //}
     //catch (NotFoundException& ve)
     //{
     //    cout << ve.what() << endl;
     //}
}

void UI::deleteProdus()
{
    string nume;
    cout << "Dati numele produsului de sters: ";
    getline(cin, nume);
    this->ctrl.deleteProdus(nume);
}

/* try {
     this->ctrl.deleteProdus(nume);
 }
 catch (NotFoundException& ve)
 {
     cout << ve.what() << endl;
 }*/


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
                    cout << "Buget insuficient" << endl;

        cout << endl << "Banii ramasi: " << buget << endl << endl;
        //this->ctrl.deleteProdusCod(cod);


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
        {
            this->ctrl.deleteProdusCod(cod);
            //cout << "RESTUL DUMNEAVOASTRA: " << buget << endl << endl;
        }
    }
}

